/*************************************************
 * VELOCITY.h:
 *  Probably one of the biggest mysteries to Travis
 *  is the world of physics. Needless to say, the
 *  task was undertaken by the hero. Could he do it?
 *  We shall see.
 * AUTHOR:
 *  Travis Confer
 ************************************************/
#ifndef VELOCITY_H
#define VELOCITY_H

#include <iostream>
#include "point.h"
class Velocity : public Point
{
public:
   //CONSTRUCTORS        
   Velocity() : Point(),  dx(0.0) , dy(0.0), angle(0) { }
   Velocity (float dx, float dy, float x, float y);
   Velocity (float x, float y); 
   Velocity (const Velocity & rhs);

   //DISPLAY
   void display() const;

   //GETTERS
   float getDx   ()       const { return dx;           } 
   float getDy   ()       const { return dy;           }
   int   getAngle()       const { return angle;        }
   Velocity getVelocity() const { return *this;        }
   
   //SETTERS
   void setAngle    (int angle         );
   void setDx       (float dx          );
   void setDy       (float dy          );
   void setVelocity (float dx, float dy);
   void advance();

   // OPERATORS
   void operator ++       (                    );
   void operator ++       (int postfix         );
   Velocity & operator =  (const Velocity & rhs);
   Velocity & operator += (const Velocity & rhs);
   
private:
   int angle;
   float  dx;
   float  dy;
};

#endif
