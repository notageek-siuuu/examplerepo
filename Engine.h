#ifndef IMPOSSENGINE_H
#define IMPOSSENGINE_H

#include "mbed.h"
#include "N5110.h"

#include "Ball.h"

#include "Zero.h"
#include "One.h"
#include "Two.h"
#include "Three.h"
#include "Four.h"
#include "Five.h"


// gap from edge of screen

class ImpossEngine
{

public:

    /** Constructor */
    ImpossEngine();
    
    /** Destructor */
    ~ImpossEngine();

   
    int update(UserInput input);
    /** Updates all of the values for the ball and maps
         * @param pad Gamepad object
         * @param lcd N5110 object
         */
    void update(N5110 &lcd);
    
    /** Draws the level, ball and objects in the levels
         * @param pad Gamepad object
         * @param lcd N5110 object
         */
    void draw(N5110 &lcd);
    
    /** Goes to the start menu, also initialises the ball
         * @param pad Gamepad object
         * @param lcd N5110 object
         */
    void complete(N5110 &lcd);
    
    /** Sets the level to zero
         */
    void set_level_zero();
    
    /** Stores the value of the level
         */
    int level;

    
    void level_finish();
    
private:

    /** Checks for a collision between the ball and a wall/object
         * @param pad Gamepad object
         * @param lcd N5110 object
         */
    void check_collision( N5110 &lcd);
    
    
    
    Ball _ball; //Ball function call
    One _one; //Level Zero function call
    Zero _zero; //Level One function call
    Two _two; // Level Two function call
    Three _three; // Level Three function call
    Four _four; // Level Four function call
    Five _five; // Level Five function call
    
    /* Stores the x position of the ball */
    int x_pos;
    
    /* Stores the y postition of the ball */
    int y_pos;
    
    /* Used as a counter to check if a collision has occured */
    int x;
    
    /* Used as a counter to check if a collision has occured */
    int y;
    
    /* Used to store the value returned when fetching the x co-ordinate of the
    balle */
    int pos;
    
    Direction _d; //Direction function call
    float _mag; //Magnitude function call

};

#endif
