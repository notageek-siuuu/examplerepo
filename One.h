#ifndef ONE_H
#define ONE_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"
#include "Joystick.h"

/** Level One Class
@author Lewis Cheadle
@brief Draws the maps and the objects in the level
@date May 2020
*/ 
class One
{

public:

    /** Constructor */
    One();
    
    /** Destructor */
    ~One();
    
    /** Draws the map and objects within the level
        * @param lcd N5110 object
     */
    void draw(N5110 &lcd);
    /// accessors and mutators
    
private:


};
#endif
