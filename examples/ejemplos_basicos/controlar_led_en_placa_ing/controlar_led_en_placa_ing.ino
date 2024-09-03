#include <CVR_easyrobot.h>

EasyRobot robot;
        
void setup() { }
        
void loop() {
    digitalWrite(LEDONBOARD,1);
    delay(500);
    digitalWrite(LEDONBOARD,0);
    delay(500);
}  