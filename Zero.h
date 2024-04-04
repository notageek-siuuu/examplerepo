#ifndef ZERO_H
#define ZERO_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"
#include "Joystick.h"


/** Level Zero Class
@author Lewis Cheadle
@brief Draws the maps and the objects in the level
@date May 2020
*/ 
class Zero
{

public:
    /** Constructor */
    Zero();
    
    /** Destructor */
    ~Zero();
    
    /** Draws the map and objects within the level
        * @param lcd N5110 object
     */
    void draw(N5110 &lcd);
    
private:


};
#endif
