#include <CVR_easyrobot.h>

EasyRobot robot;
                        
void setup() {
    robot.ledRGBEncenderColor(COLOR_ROJO);
    delay(300);
    robot.ledRGBEncenderColor(COLOR_VERDE);
    delay(300);
    robot.ledRGBEncenderColor(COLOR_AZUL);
    delay(300);
}
                        
void loop() {
    for(int c=0;c<256;c++){
      robot.ledRGBEncenderColor(c,255-c,255);
      delay(20);
    }for(int c=0;c<256;c++){
      robot.ledRGBEncenderColor(255-c,c,255);
      delay(20);
    }
    for(int c=0;c<256;c++){
      robot.ledRGBEncenderColor(255,c,255-c);
      delay(20);
    }
    for(int c=0;c<256;c++){
      robot.ledRGBEncenderColor(255,255-c,c);
      delay(20);
    }
}  