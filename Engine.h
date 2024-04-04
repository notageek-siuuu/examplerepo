#ifndef IMPOSSENGINE_H
#define IMPOSSENGINE_H

#include "mbed.h"
#include "N5110.h"
#include "Joystick.h"
#include "Ball.h"
#include "Zero.h"
#include "One.h"
#include "Two.h"
#include "Three.h"
#include "Four.h"
#include "Five.h"


// gap from edge of screen

class PongEngine {
    public:
        PongEngine();  // pass in the lcd object from the main file
        void init(int paddle_position,int paddle_height,int paddle_width,int ball_size,int speed);
        int update(UserInput input);
        void draw(N5110 &lcd);
    private:
        void check_wall_collision();
        void check_paddle_collision();
        void check_goal();
        Ball _ball;
        int _lives;
};

#endif
