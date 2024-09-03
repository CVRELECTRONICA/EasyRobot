#include <CVR_easyrobot.h>

EasyRobot robot;
                        
void setup() {
    robot.enableServo();
    robot.servoPosition(90); // Posición a 90 grados
}
                        
void loop() {
    for(int p=0; p<180; p++){
      robot.servoPosition(p+1); // Posición de 0 a 180 grados
      delay(25);
    }
    delay(500);
}        