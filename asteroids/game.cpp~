/************************************************************************
 * GAME.CPP
 *    Default Constructor with element spawning and allocating, advance
 *    function to remove "dead" elements and keep living elements rolling,
 *    interact function for bombs, shotgun, and ship movement. 
 * Authors:
 *    Travis Confer
 *    Robert Dickerson
 ***********************************************************************/

#include "game.h"

#define MAX(x ,y) (x > y ? x : y) //Return the greater input
#define MIN(x ,y) (x < y ? x : y) //Return the lesser  input

#define BOMB 3          // Bombs to start with
#define BOMB_SPREAD 100 // BOMB Radius
#define SHOT_SPREAD 3   // Spread distance between shotgun shots
#define ROCKS 6         // Set the amount of rocks
#define BIGSTAR 30      // Amount of big stars
#define BIGSTARSIZE 5   // big star radius
/*****************************************************************
 * DEFAULT CONSTRUCTOR:
 *      Construct ship, and push back asteroids as new elements.
 *      Create the stars in the sky.
 **************************************************************/
Game :: Game() : isBirdShot(false), bombs(BOMB), bombTime(0)
{
   for (int i = 0; i < STARS; i++)
      star[i].setPoint(random(star[i].getXMin(),
                              star[i].getXMax()),
                       random(star[i].getXMin(),
                              star[i].getXMax()));
   
   pElement.push_back(new Ship());
   
   for (int i = 0; i < ROCKS; i++)
      pElement.push_back(new LargeAsteroid());
   
   /**************************************      
    * Uncomment below for big stars!
    **************************************/
   // for (int i = 0; i < BIGSTAR; i++)
   //    bigstar[i].setPoint(random(bigstar[i].getXMin(),
   //                               bigstar[i].getXMax()),
   //                        random(bigstar[i].getXMin(),
   //                               bigstar[i].getXMax()));
}

/*****************************************************************
 * ADVANCE:
 *      Iterate through all elements and move them along, unless
 *      they're already dead. Then delete them. Create new asteroids
 *      from fallen larger asteroids. 
 **************************************************************/
void Game :: advance()
{
   for (list <Inertia *> :: iterator it = pElement.begin();
        it != pElement.end(); it++)
   {
      (*it)->advance();
      if ((*it)->isDead())
      {
         // When we destroy a Large Asteroid
         if ((*it)->getSize() == 20)
         {
            pElement.push_back(new MediumAsteroid((*it)->getVelocity()));
            pElement.push_back(new MediumAsteroid((*it)->getVelocity()));
            pElement.push_back(new  SmallAsteroid((*it)->getVelocity()));
         }

         // When we destroy a Medium Asteroid
         if ((*it)->getSize() == 15)
         {
            pElement.push_back( new SmallAsteroid((*it)->getVelocity()));
            pElement.push_back( new SmallAsteroid((*it)->getVelocity()));
         }

         // Dispose of the "dead" elements
         delete *it;
         *it = NULL;
         pElement.erase(it++);
         
      }
   }

   // Explosion Speed and incrementing
   if (bombTime > 0)
      bombTime -= 10;
}

/*****************************************************************
 * INTERACT:
 *    Lets us trigger the bombs, fire the gun, switch weapons,
 *    and lets us control the ship. Also checks for distances
 *    and kills those in close proximity.
 **************************************************************/
void Game :: interact(bool space, int up, int down,
                      int left , int right, bool t, bool b)
{
   // Bomb Dropping
   if (b && pElement.front()->getType() == "ship" && bombs > 0)
   {
      bombTime = BOMB_SPREAD;
      this->bombs--;
   }
   
   // Destroy everything in Bomb's radius
   if (bombTime > 0)
   for (list <Inertia *> :: iterator it = pElement.begin();
        it != pElement.end(); it++) // Loop through objects
      if (( *it)->getType() != "ship")
         // IF distance from ship to rock is less than radius
         if (minimumDistance
             (pElement.front()->getVelocity(),
              (*it)->getVelocity())
             < BOMB_SPREAD - (bombTime + 2))
            (*it)->kill();
   
   // Shooting Control
   if (space &&  pElement.front()->getType() == "ship")
      if (isBirdShot)
         for (int i = 0; i < 5; i++)
         {
            // new Velocity for when we use shotgun
            Velocity shot(pElement.front()->getVelocity());
            
            // Spread the bullets evenly according to SHOT_SPREAD 
            shot.setAngle(shot.getAngle() - ((i - 2)*SHOT_SPREAD));
            
            pElement.push_back(new Bullet(shot));
         }
      else // Boring Bullets
         pElement.push_back(new Bullet(pElement.front()->getVelocity()));

   if (t) // Switch to Shotgun
      isBirdShot = (isBirdShot ? false : true);

   // Normal Ship Control
   for (list <Inertia *> :: iterator it = pElement.begin();
        it != pElement.end(); it++)
      (*it)->interact(up, down, left, right, b);

   // Kill elements that collide, unless same element
   for (list <Inertia *> :: iterator it = pElement.begin();
        it != pElement.end(); it++)
      for (list <Inertia *> :: iterator jit = pElement.begin();
           jit != pElement.end(); jit++)
      {
         if (( *it)->getType() != (*jit)->getType())
            if ((minimumDistance(( *it)->getVelocity(),
                                 (*jit)->getVelocity()) < (*jit)->getSize()))
            {
               if ((( *it)->getType() == "ship" &&
                    (*jit)->getType() == "bullet") ||
                   (( *it)->getType() == "bullet" &&
                    (*jit)->getType() == "ship"))
                  ; // Friendly Fire is off. Do nothing for now.
               else
               {
                  ( *it)->kill();
                  (*jit)->kill();
               }
            }
      } 
}

/*****************************************************************
 * GAME DRAW:
 *     Draw the screen and any bombs that explode, along with all elements
 **************************************************************/
void Game :: draw()
{
   // Display Bomb
   if (bombTime > 1 &&  pElement.front()->getType() == "ship")
   {
      drawCircle(pElement.front()->getPoint(), (BOMB_SPREAD - bombTime) - 8);
      drawCircle(pElement.front()->getPoint(), (BOMB_SPREAD - bombTime) + .01);
      drawCircle(pElement.front()->getPoint(), (BOMB_SPREAD - bombTime) + 2);
      drawCircle(pElement.front()->getPoint(), (BOMB_SPREAD - bombTime) + 5);
   }

   // Draw all normal elements
   for (list <Inertia *> :: iterator it = pElement.begin();
        it != pElement.end(); it++)
   {
      (*it)->draw();
   }

   // Firing Mode with instructions on how to switch
   Point point1(point1.getXMin() + 10, point1.getYMax() - 20);
   drawText(point1, (isBirdShot ? "Fire Mode: SHOTGUN"
                     : "Fire Mode: RIFLE "));
   Point point3(point3.getXMin() + 10, point3.getYMax() - 40);
   drawText(point3, "Press \"T\" to switch");

   // Display if/when user dies
   if (pElement.front()->getType() != "ship" || !pElement.front())
   {
      Point point2(-40.0, -10.0);
      drawText(point2, "Press \"R\" to reset");
   }

   // Display the bombs we have left
   Point point4(point4.getXMin() + 10, point4.getYMin() + 10);
   switch (bombs)
   {
      case 3:
         drawText(point4, "BOMBS: {O} {O} {O} ");
         break;
      case 2:
         drawText(point4, "BOMBS: {O} {O} ");
         break;
      case 1:
         drawText(point4, "BOMBS: {O} ");
         break;
      case 0:
         drawText(point4, "BOMBS: ----");
         break;
      default:
         drawText(point4, "BOMBS: You've got a ton of bombs");
         break;
   }

   // Instructions on how to bomb
   Point point5(point5.getXMin() + 10, point5.getYMin() + 30);
   drawText(point5, "Press \"B\" to bomb");

   // Paint the sky!
   for (int i = 0; i < STARS; i++)
      drawStarDot(this->star[i].getPoint());
   
   /*******************************
    * Uncomment below for big stars!
    ********************************/
   // for (int i = 0; i < BIGSTAR; i++)
   // { 
   //    drawBigStar(this->bigstar[i].getPoint(), BIGSTARSIZE);
   // }
}

/*****************************************************************
 * GAME RESET:
 *     Erase all list items, and rebuild list
 **************************************************************/
void Game :: reset()
{
   pElement.clear();               // Clean slate, like baptism
   
   pElement.push_back(new Ship()); // Populate with ship
   
   for (int i = 0; i < ROCKS; i++) // Asteroids for fun
       pElement.push_back(new LargeAsteroid());
   
   bombs = BOMB; 
}

/*****************************************************************
 * GAME HASELEMENTS:
 *     Check to see if there are any elements left. Honestly,
 *     this class doesn't work, but if it did we would use it
 *     to prevent seg faults when the last ship and asteroid collide.
 **************************************************************/
bool Game :: hasElements()
{
   // cerr << pElement.size() << endl;
   if (pElement.empty())
   {
      cerr << "THIS IS EMPTY!" << endl;
      return false;
   }
   if (pElement.size() > 0)
      return true;
   else
      return false;
}

/**************************************************************
 * MINIMUM DISTANCE: (and maximum frustration)
 *    Take 2 vectors, and determine what the closest point
 *    between the 2 are/were/will be. Return the smallest
 *    distance found. 
 **************************************************************/
float Game :: minimumDistance(const Velocity & a,
                              const Velocity & b) const
{
   float slice = 0.0;
   // Initialize high so MIN won't auto-select it
   // ITS OVER 9000!!!!!
   float minDist = 9001.0;
   
   // Make the largest change in coordinate the slice fraction
   slice = (1 / (MAX( (MAX(abs(a.getDx()), abs(a.getDy()))),
                      (MAX(abs(b.getDx()), abs(b.getDy()))))));

   // Go through the percentages of the
   for (float i = 0.0; i < 100.0; i += slice)
   {
      float distanceSquared = 
         pow(((a.getX() + a.getDx() * (slice/100)) -
              (b.getX() + b.getDx() * (slice/100))) , 2.0) +
         pow(((a.getY() + a.getDy() * slice/100) -
              (b.getY() + b.getDy() * slice/100)), 2.0);
      // Reassign if the next value is smaller than the last
      minDist = MIN(distanceSquared, minDist);
   }

   // Praise Pythagoras! 
   return sqrt(minDist);
}
