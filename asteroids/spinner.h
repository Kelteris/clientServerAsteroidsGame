/************************************************************************
 *  Headerfile:
 *     THIS CODE WAS NOT USED IN THE FINAL PRODUCT
 *     Spinner : Header File
 *  Author:
 *     Mark Decker
 *  purpose:
 *     To spin the asteroids! Based on their size they will rotate
 *     a certain speed. 
 *************************************************************************/

#ifndef SPINNER_H
#define SPINNER_H

#include "asteroids.h"
#include <cmath>

/****************************************
 * SPINNER
 ****************************************/

class Spinner : public Inertia
{
  Public:
   //Spinner() : asteroids() 
   void hit();
   
  Protected:
   int orientation;
};

#endif //SPINNER_H
