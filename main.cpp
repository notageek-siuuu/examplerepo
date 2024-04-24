#include "mbed.h"
#include "Utils.h"
#include "N5110.h"
#include "ImpossEngine.h"
#include "Joystick.h"





/////////////// objects ///////////////
N5110 lcd(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
Joystick joystick(PC_1, PC_0);
DigitalIn buttonA(BUTTON1); //onboard user button


///////////// prototypes ///////////////
void init();
void render();
void welcome();
void start_menu();
void wait();

///////////// functions ////////////////

int main()
{

    int fps = 6;  // frames per second

    init();     // initialise and then display welcome screen...
    welcome();  // waiting for the user to start
    // brings up start menu for user to select option
    render();  // first draw the initial frame 
      // and wait for one frame period


    // game loop - read input, update the game state and render the display
    while (1) {
        
      
        render();
        
    }
}


// this function draws each frame on the LCD
void render()
{
    // clear screen, re-draw and refresh
    lcd.clear();  
    
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
    


void init() {
    lcd.init(LPH7366_1);
    lcd.setContrast(0.5);
    joystick.init();
         // paddle x position, paddle_height,paddle_width,ball_size,speed
}
