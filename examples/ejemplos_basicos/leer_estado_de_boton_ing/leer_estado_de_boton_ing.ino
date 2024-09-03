#include <CVR_easyrobot.h>

EasyRobot robot;
        
void setup() { }
        
void loop() {
    digitalWrite(LEDONBOARD,robot.readButton());
}  