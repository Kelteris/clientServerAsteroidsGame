/**************************************************************
 * SHIP.CPP
 *   Contains the ship which is so kindly crafted.
 * Author:
 *   Travis Confer
 **************************************************************/

#include "inertia.h"

#define DAMPEN    0.1  // Speed at which we slow down
#define MIN_BREAK 0.01 // Slowest we can deccelerate to
/************************************************************
 * Constructs the Ship
 ***********************************************************/
Ship :: Ship() : Inertia(), thrust(false)
{
   // random angle and location (within spawn bounds)
   v.setPoint(random(-SPAWN, SPAWN),random(-SPAWN, SPAWN));
   v.setAngle(random(0 , 360));
}

/************************************************************
 * MOVE: Change the velocity accoding to our input
 ***********************************************************/
void Ship :: interact(int up, int down, int left, int right,
                      bool b)
{
   // For the draw function
   if (up)
      thrust = true;
   else
      thrust = false;
   
   v.setAngle(v.getAngle() + left );
   v.setAngle(v.getAngle() - right);
   
   if (up)
   {
      if (up > 5)
         up = 5;
      
      float speed = up;
      speed *= .05;
      
      v.setDx(v.getDx() + (-sin(v.getAngle() * M_PI / 180) * speed));
      v.setDy(v.getDy() + ( cos(v.getAngle() * M_PI / 180) * speed));
   }

   // Slow Inertia
   if (down)
   {
      if (v.getDx() >  MIN_BREAK  || v.getDx() < -MIN_BREAK)
         v.setDx(v.getDx() - (v.getDx() * DAMPEN));
            
      if (v.getDy() >  MIN_BREAK  || v.getDy() < -MIN_BREAK)
         v.setDy(v.getDy() - (v.getDy() * DAMPEN));
   }  
}

/************************************************************
 * DRAW: Draw the ship and the flame as well.
 ***********************************************************/
void Ship :: draw() const
{   
   drawShip(v.getPoint(), v.getAngle(), this->thrust);
}
