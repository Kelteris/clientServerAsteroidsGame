/************************************************************************
 * Body File:
 *    Asteroids: because men have gun that need bullets
 * Author:
 *    Robert Dickerson
 * Contains:
 *    Code for the parent Asteroid class with its children
 ***********************************************************************/

#include "inertia.h"
#include "game.h"

#define SPAWNBUFFER  30.0 // Space between ship spawn and rock spawn
#define SPAWNSPEED    1.5 // Random speed for Large Asteroids
#define KICKSPEED     1.9 // Random Speed for derived chunks
/*************************************************************
 * Asteroid: Default constructor
 *************************************************************/
Asteroid :: Asteroid() : Inertia(), rotate(random(-1 , 1))
{
   v.setAngle(random(0, 360));
}

/*************************************************************
 * Asteroid : Copy Velocity of object passed in
 *************************************************************/
Asteroid :: Asteroid(const Velocity & rhs)
      : Inertia(rhs), rotate(random(-1 , 1))
{
   v.setAngle(random(0, 360));
}

/*************************************************************
 * Large Asteroid : Default constructor with random spawn
 *************************************************************/
LargeAsteroid :: LargeAsteroid() : Asteroid()
{
   // Choose between 1 and 0
   int flip = random(-1, 1);

   // Random X spawn
   if (flip == 0)
      v.setX(random( SPAWN, v.getXMax()) + SPAWNBUFFER);
   else
      v.setX(random(v.getXMin(), -SPAWN) - SPAWNBUFFER);

   // Random Y spawn
   flip =  random(-1, 1);
   if (flip == 0)
      v.setY(random( SPAWN, v.getYMax()) + SPAWNBUFFER);
   else
      v.setY(random(v.getYMin(), -SPAWN) + SPAWNBUFFER);

   v.setVelocity(random(-SPAWNSPEED, SPAWNSPEED)
                ,random(-SPAWNSPEED, SPAWNSPEED));
}

/******************************************************
 * Draw the Large Asteroid
 ********************************************************/
void LargeAsteroid :: draw() const
{
   drawLargeAsteroid( v.getPoint(), v.getAngle());
}

/*************************************************************
 * Medium Asteroid :: Default Constructor
 *************************************************************/
MediumAsteroid :: MediumAsteroid() : Asteroid()
{
   int flip = random(-1, 1);

   // Random X spawn
   if (flip == 0)
      v.setX(random( SPAWN, v.getXMax()) + SPAWNBUFFER);
   else
      v.setX(random(v.getXMin(), -SPAWN) - SPAWNBUFFER);

   // Random Y spawn
   flip =  random(-1, 1);
   if (flip == 0)
      v.setY(random( SPAWN, v.getYMax()) + SPAWNBUFFER);
   else
      v.setY(random(v.getYMin(), -SPAWN) + SPAWNBUFFER);

   v.setVelocity(random(-1.5, 1.5), random(-1.5, 1.5));
}

/****************************************************************
 * Medium Asteroid : Copy Velocity 
 ****************************************************************/
MediumAsteroid :: MediumAsteroid(const Velocity & rhs) : Asteroid(rhs)
{
   Velocity kick(random(-KICKSPEED, KICKSPEED),
                 random(-KICKSPEED, KICKSPEED),
                 0.0, 0.0);
    v += kick;
}

/*************************************************************
 * Draw the Medium Asteroid
 *************************************************************/
void MediumAsteroid :: draw() const
{
   drawMediumAsteroid( v.getPoint(), v.getAngle());  
}


/*************************************************************
 * Small Asteroid
 *************************************************************/
SmallAsteroid :: SmallAsteroid() : Asteroid()
{
   int flip = random(-1, 1);
   
   // Random X spawn
   if (flip == 0)
      v.setX(random( SPAWN, v.getXMax()) + SPAWNBUFFER);
   else
      v.setX(random(v.getXMin(), -SPAWN) - SPAWNBUFFER);
   
   // Random Y spawn
   flip =  random(-1, 1);
   if (flip == 0)
      v.setY(random( SPAWN, v.getYMax()) + SPAWNBUFFER);
   else
      v.setY(random(v.getYMin(), -SPAWN) + SPAWNBUFFER);
}

/**************************************************************
 * Small Asteroid : Copy Velocity
 ****************************************************************/
SmallAsteroid :: SmallAsteroid(const Velocity & rhs) : Asteroid(rhs)
{
   // Sets the velocity for the spawned Asteroids
   Velocity kick(random(-KICKSPEED - 1, KICKSPEED + 1),
                 random(-KICKSPEED - 1, KICKSPEED + 1),
                 0.0, 0.0);
    v += kick;  
}

/***************************************************************
 * Draw the Small Asteroid
 ****************************************************************/
void SmallAsteroid :: draw() const
{
   drawSmallAsteroid(v.getPoint(), v.getAngle());  
}

