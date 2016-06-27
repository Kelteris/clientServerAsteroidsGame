/**********************************************************
 *  VELOCITY.cpp
 *    Velocity will do pretty much anything you want it to!
 *    (except for calculating magnitude and the angle).
 *    We don't care about that nonsense so far. We just want
 *    to simulate intertia at this point. 
 *
 *  AUTHOR:
 *    Travis Confer
 *********************************************************/

#include <iostream>
#include "velocity.h"
#include "point.h"

using namespace std;


/***************************************************
 * Non Default Constructor
 **************************************************/
Velocity :: Velocity (float dx, float dy, float x, float y) : Point(x, y)
{
   this->dx = dx;
   this->dy = dy;
}

/***************************************************
 * Non Default Constructor
 **************************************************/
Velocity :: Velocity (float x, float y) : Point(x, y)
{
   this->dx = 0.0;
   this->dy = 0.0;
}

/***************************************************
 * Copy constructor      
 **************************************************/
Velocity :: Velocity (const Velocity & v) : Point(v.getPoint())
{
   this->angle = v.angle;
   this->dx    = v.dx   ;
   this->dy    = v.dy   ;
};

/***************************************************
 *
 **************************************************/
void Velocity :: display() const
{
   cout.precision(2);
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   
   cout << "Point (" << getX() << ", " << getY() << ")"
        << "~~ Dx, Dy (" << dx << ", " << dy << ")";  
}

/***************************************************
 * SETTERS
 **************************************************/
void Velocity :: setDx       (float  dx)
{ this->dx = dx;       }
void Velocity :: setDy       (float  dy)
{ this->dy = dy;       }
void Velocity :: setAngle    (int angle)
{ this->angle = angle; }
void Velocity :: setVelocity (float dx, float dy)
{
   this->dx = dx;
   this->dy = dy;
}

/*************************************************
 * VELOCITY ADVANCE:
 *    Take the point and add the DeltaX and
 *    DeltaY to the coordinates. 
 *************************************************/
void Velocity :: advance()
{
   addX(dx);
   addY(dy);
}

/*************************************************
 * VELOCITY ++
 *************************************************/
void Velocity :: operator ++()
{
   advance();
}

/*************************************************
 * VELOCITY ++ (postfix)
 *************************************************/
void Velocity :: operator ++(int postfix)
{
   advance();
}

/*************************************************
 * VELOCITY = operator
 *************************************************/
Velocity & Velocity :: operator = (const Velocity & rhs)
{
   this->angle = rhs.angle;
   this->dx    = rhs.dx   ;
   this->dy    = rhs.dy   ;
   
   return *this;
}


/*************************************************
 * VELOCITY += operator
 *************************************************/
Velocity & Velocity :: operator += (const Velocity & rhs)
{
   this->angle += rhs.angle;
   this->dx    += rhs.dx   ;
   this->dy    += rhs.dy   ;
   
   return *this;
}
