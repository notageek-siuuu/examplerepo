#include "ImpossEngine.h"


ImpossEngine::ImpossEngine()
{

}

ImpossEngine::~ImpossEngine()
{

}



int ImpossEngine::update(UserInput input) {   
    //printf("Pong Engine: Update\n");
     // checking for a goal is a priority 
    _ball.update();
    
    // important to update paddles and ball before checking collisions so can
    // correct for it before updating the display
    return 0;
}

//Used to set the level to zero
void ImpossEngine::set_level_zero()
{
    level = 0;
}

//Draws the levels, obstacles and ball
void ImpossEngine::draw(N5110 &lcd)
{
    // draw the elements in the LCD buffer
    // pitch   
    
    
    if (level == 0){
        _zero.draw(lcd);
    }

    if (level == 1){
        _one.draw(lcd);
    } 
    
    if (level == 2){
        _two.draw(lcd);
    }
    
    if (level == 3){
         _three.draw(lcd);
    }
    
    if (level == 4){
         _four.draw(lcd);
    }
    
    if (level == 5){
         _five.draw(lcd);
    }
    
    if (level == 6){
        while(1){
            lcd.clear();
            lcd.printString("  Well done!  ",0,0);
            lcd.printString(" You beat all ",0,1);
            lcd.printString("of the levels!",0,2);
            lcd.printString("Press reset to",0,3);
            lcd.printString("  try again!  ",0,4);
            
            
            lcd.refresh();
            }    
    }
         
    _ball.update();
    
    _ball.draw(lcd);

}

//Updates all parameters, checks for collisions and checks to see if the level
//has been completed


//Checks every pixel around the ball, if any are "on"(1) then that is classed
//as a collision
void ImpossEngine::check_collision(N5110 &lcd)
{
    int _x = 0;
    int _y = 0;
    int i = 0;
    
    bool collision = false;
    //check around ball to see if it has made contact with anything
    
    while(i < 3){
        
        i++;
        
        if(lcd.getPixel(x_pos + _x,y_pos + _y) == 1){
            collision = true;
            }
            
        _x ++;
        
    }
    
    i = 0;
     
    while(i < 3){
        
        i++;
        
        if(lcd.getPixel(x_pos + _x,y_pos + _y) == 1){
            collision = true;
            }
            
        _y ++;
        
    }
    
    i = 0;
    
    while(i < 3){
        
        i++;
        
        if(lcd.getPixel(x_pos + _x,y_pos + _y) == 1){
            collision = true;
            }
            
        _x --;
        
    }
    
    i = 0;
    
    while(i < 3){
        
        i++;
        
        if(lcd.getPixel(x_pos + _x,y_pos + _y) == 1){
            collision = true;
            }
            
        _y --;
        
    //death sequence
    if(collision == true){
        lcd.clear();
        lcd.printString("  You died! ",0,2);
        lcd.refresh();
        
       
        
        //resets ball to start of level if a collision has been detected
        
        }
    }
}

//Checks to see if the ball has reached the end of the level, if it has,
//increases the value of the level and sets the ball back to the beginning of
//the level
