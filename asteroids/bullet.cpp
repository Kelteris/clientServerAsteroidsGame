/************************************************************************
 * Body File:
 *    Bullet : Because men have gun, that need bullets
 * Author:
 *    Robert Dickerson
 * Contains:
 *    The code for continuing the bullet in a straight path, killing it, and
 *    drawing it. 
 ***********************************************************************/

#include "inertia.h"
#include "uiDraw.h"
#include <cmath> 
#include <cassert>
#include <iostream>
using namespace std;

#define SAFE 0.75 // Safe distance away from front of ship
#define SPEED 10  // speed of the bullet
#define LIFE  30  // How many frames we want to have bullet
/******************************************************************
 * NON-DEFAULT Constructor: Copy whatever velocity is fed in
 ***************************************************************/
Bullet :: Bullet(const Velocity & rhs) : Inertia(rhs), timeToLive(LIFE)
{  
   v.setDx(v.getDx() + (-sin(v.getAngle() * M_PI / 180) * SPEED));
   v.setDy(v.getDy() + ( cos(v.getAngle() * M_PI / 180) * SPEED));

   // Don't spawn inside the ship
   v.addX(v.getDx()*SAFE);
   v.addY(v.getDy()*SAFE);
}

/******************************************************************
 * DRAW: Draw a small dot to be our bullet
 ***************************************************************/
void Bullet :: draw() const
{
   drawDot(v.getPoint());
}

/******************************************************************
 * KILL: Kills bullet when timer counts down
 ***************************************************************/
void Bullet :: advance()
{
   v.advance();
   
   this->timeToLive--;
   
   if (timeToLive == 0)  // Time to Die
      kill();
}

