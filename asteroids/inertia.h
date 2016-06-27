/*************************************************
 * INERTIA.h:
 *  Velocity class with the zest of polymorphism.
 *  Contains SHIP header, ASTEROIDS header, and
 *  also BULLET header. They all coexist together.
 * AUTHOR:
 *  Travis Confer
 ************************************************/

#ifndef INERTIA_H
#define INERTIA_H

#include <cmath>     // For the purpose of PI
#include <iostream>
using namespace std;

#include "velocity.h"
#include "uiDraw.h"

#define SPAWN  30.0  // How much room do we give the ship?

#define LARGE  20.0  //size of a large rock
#define MEDIUM 15.0  //size of a medium rock
#define SMALL  10.5  //size of a small rock
#define SHIP    5.5  //size of ship
/**********************************************************
 * INERTIA : Oh YEAH!
 **********************************************************/
class Inertia
{
  public:
   // CONSTRUCTORS
   Inertia() : v(), dead(false)
   { v.setWrap(true); }
   Inertia(float x,     float y) : v(x, y), dead(false)
   { v.setWrap(true); }
  Inertia(const Velocity & rhs) :  v(rhs),  dead(false)
   { v.setWrap(true); }

   // Virtual Functions
   virtual void interact(int up, int down, int left, int right,
                         bool b){}
   virtual void   draw    () const = 0;
   virtual float  getSize () const = 0;
   virtual string getType () const {return "nothing";  }
   void           kill    ()       { this->dead = true;}
   
   // GETTERS
   Velocity getVelocity() const { return this->v;           }
   Point    getPoint   () const { return this->v.getPoint();}
   bool       isDead   () const { return dead;              }
   
   // All do the same, but for convenience of user
   virtual void advance ()        { v.advance();} 
   void operator ++ (           ) { v.advance();} 
   void operator ++ (int postfix) { v.advance();} 
   
   
  protected:
   Velocity v;
   bool dead;
};

/*************************************************************
 * SHIP : Ship class Header
 *************************************************************/
 class Ship : public Inertia 
 { 
   public: 
    Ship(); 

    // Interact and Draw (pass in up to see if we draw flames) 
    void interact  (int up, int down, int left, int right, bool b); 
    void draw      () const ; 
    string getType () const { return "ship"; }
    float  getSize () const { return SHIP  ; }

   private:
    bool thrust; 
 }; 

/*********************************************************************
 * BULLET : The Bullet class
 **************************************************************/
class Bullet : public Inertia
{
  public:     // each bullet constructs itself
   Bullet() : Inertia(), timeToLive(90)  { }
   Bullet(const Velocity & rhs);
   
   void draw      () const;
   void advance   ()      ;
   string getType () const { return "bullet"; }
   float  getSize () const { return 0.01  ;   }

  private:
   int timeToLive;
};

/*******************************************************************
 * ASTEROIDS : The Asteroid class
 ******************************************************************/
class Asteroid : public Inertia
{
  public:
   Asteroid();
   Asteroid(const Velocity & rhs);
   
   virtual void draw      () const = 0;
   int    getRotate       () const { return rotate;    }
   string getType         () const { return "asteroid";}
   
  private:
   int rotate;
};

/**********************************************************************
* Large Asteroid Class
***********************************************************************/
class LargeAsteroid : public Asteroid
{
  public:
   LargeAsteroid();
   
   void draw       () const;
   void advance    () { v.advance(); v.setAngle(v.getAngle() + getRotate());}
   
   float  getSize  () const { return LARGE;   }
};

/**********************************************************************
* Medium Asteroid Class
***********************************************************************/
class MediumAsteroid : public Asteroid
{
  public:
   MediumAsteroid();
   MediumAsteroid(const Velocity & rhs);
   
   void draw       () const;
   void advance    () { v.advance(); v.setAngle(v.getAngle() + 3);}
   
   float  getSize  () const { return MEDIUM;   }
};

/**********************************************************************
* Small Asteroid Class
***********************************************************************/
class SmallAsteroid : public Asteroid
{
  public:
   SmallAsteroid();
   SmallAsteroid(const Velocity & rhs);
   
   void draw       () const;
   void advance    () { v.advance(); v.setAngle(v.getAngle() + 5);}
   
   float  getSize  () const { return SMALL;   }
};

#endif //INERTIA_H
