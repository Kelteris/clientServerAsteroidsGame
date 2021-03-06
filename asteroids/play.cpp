/*********************************************************
 * ASTEROIDS
 *   You know the drill, play the game
 *
 * AUTHORS:
 *     Robert Dickerson
 *     Travis Confer
 *     Mark Decker
 ********************************************************/

#include <iostream>
using namespace std;

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "inertia.h"
#include "game.h"

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void * p)
{
   Game * pGame = (Game *)p;

   if (pGame->hasElements())
   {
      // Move the game forward
      pGame->advance();
      
      // Draw the objects
      pGame->draw();
            
      // Take in user input
      pGame->interact(pUI->isSpace(), pUI->isUp(), pUI->isDown(),
                      pUI->isLeft(), pUI->isRight(), pUI->isT(),
                      pUI->isB());
      
      // Reset if desired
      if (pUI->isR())
         pGame->reset();
   }
}

// set the bounds of the drawing rectangle
float Point::xMin = -250.0;
float Point::xMax =  250.0;
float Point::yMin = -250.0;
float Point::yMax =  250.0;

/*********************************
 * Main is pretty sparse.  Just initialize
 * my ball type and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Interface ui(argc, argv, "~~*INTERSTELLAR*~~"); // initialize OpenGL
   Game game;                           // Initialize game state
   ui.run(callBack, &game);             // set everything into action

   return 0;
}
