#include <CVR_easyrobot.h>

EasyRobot robot;
                        
void setup() { }
                        
void loop() {
    digitalWrite(LEDENPLACA,robot.leerBoton());
}  