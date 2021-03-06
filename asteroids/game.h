/************************************************************************
 * GAME.H
 *    Game contains all the game objects and their functions.
 *    The separate objects are initialized here, and learn to
 *    play nicely with eachother. We also call the main 3
 *    functions here, DRAW, INTERACT, and ADVANCE.
 * Author:
 *    Robert Dickerson
 *    Travis Confer
 ***********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <math.h>
#include <cmath>
#include <list>
#include <string>
#include <iostream>  // mandatory for cin and cout
#include <cassert>   // Because Murphy's Law
#include "inertia.h"
#include "uiInteract.h"
#include "uiDraw.h"
using namespace std;

#define STARS 175       // MilkyWay?
/****************************************************
 * GAME: contains everything
 *****************************************************/
class Game
{
  public:
   Game();
   // Calls all draw functions
   void draw();

   // Takes in user inputs 
   void interact(bool space, int up, int down,
                 int left, int right, bool t, bool b);
   
   // Puts all objects in motion
   void advance();

   // Refresh, restart, rebirth
   void reset();

   // Check to see if we have any objects (doesn't work)
   bool hasElements();
   
   // Determines whether 2 objects truly collide
   float minimumDistance(const Velocity & a, const Velocity & b) const;
   
  private:
   list <Inertia *> pElement;
   int   bombs;
   int   bombTime;
   bool  isBirdShot;
   Point star[STARS];
   //Uncomment below for big Stars option
   /*Point bigstar[BIGSTAR];*/
};

#endif // GAME_H
