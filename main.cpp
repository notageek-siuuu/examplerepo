#include "mbed.h"
#include "Utils.h"
#include "N5110.h"
#include "ImpossEngine.h"
#include "Joystick.h"





/////////////// objects ///////////////
N5110 lcd;
Joystick joy;
ImpossEngine imposs;
int level;
int ball_x_pos;
int ball_y_pos;

///////////// prototypes ///////////////
void init();
void update_game(UserInput input);
void render();
void welcome();
void start_menu();

///////////// functions ////////////////

int main()
{

    int fps = 6;  // frames per second

    init();     // initialise and then display welcome screen...
    welcome();  // waiting for the user to start
    imposs.complete(lcd); // brings up start menu for user to select option
    render();  // first draw the initial frame 
    wait(1.0f/fps);  // and wait for one frame period


    // game loop - read input, update the game state and render the display
    while (1) {
        
        imposs.update(lcd);
        render();
        wait(1.0f/fps);
    }
}


// this function draws each frame on the LCD
void render()
{
    // clear screen, re-draw and refresh
    lcd.clear();  
    imposs.draw(lcd);
    lcd.refresh();
}

// simple splash screen displayed on start-up
void welcome() {
    
    lcd.printString("  Welcome to  ",0,1);
    lcd.printString("  Impossible  ",0,2);  
    lcd.printString("  Press Start ",0,4);
    lcd.refresh();
     
    // wait flashing LEDs until start button is pressed 
    
 
}
    



void init()
{
    // need to initialise LCD and Gamepad 
    lcd.init();
    Joystick*init();

}
