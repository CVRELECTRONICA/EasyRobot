#include <CVR_easyrobot.h>

EasyRobot robot;
        
void setup() { }
        
void loop() {
    digitalWrite(LEDENPLACA,1);
    delay(500);
    digitalWrite(LEDENPLACA,0);
    delay(500);
}  