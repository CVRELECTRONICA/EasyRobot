#include <CVR_easyrobot.h>

EasyRobot robot;
                        
void setup() {
    robot.ledRGBSetColor(RED_COLOR);
    delay(300);
    robot.ledRGBSetColor(GREEN_COLOR);
    delay(300);
    robot.ledRGBSetColor(BLUE_COLOR);
    delay(300);
}
                        
void loop() {
    for(int c=0;c<256;c++){
      robot.ledRGBSetColor(c,255-c,255);
      delay(20);
    }for(int c=0;c<256;c++){
      robot.ledRGBSetColor(255-c,c,255);
      delay(20);
    }
    for(int c=0;c<256;c++){
      robot.ledRGBSetColor(255,c,255-c);
      delay(20);
    }
    for(int c=0;c<256;c++){
      robot.ledRGBSetColor(255,255-c,c);
      delay(20);
    }
}  