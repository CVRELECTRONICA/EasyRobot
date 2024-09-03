#include <CVR_easyrobot.h>

EasyRobot robot;
                        
void setup() {
    robot.activarPwm(); // activa el control por PWM
    robot.configurarVelocidad(MOTOR2, 70); // 75% de velocidad
    robot.configurarVelocidad(MOTOR1, 70); // 75% de velocidad
}
                        
void loop() {
    robot.onMotor1(FORWARD); //giro en avance
    delay(1000); //espera de 1 segundo
    robot.onMotor1(BACKWARD); //giro en retroceso
    delay(1000); //espera de 1 segundo
    robot.offMotors();
    robot.onMotor2(FORWARD); //giro en avance
    delay(1000); //espera de 1 segundo
    robot.onMotor2(BACKWARD); //giro en retroceso
    delay(1000); //espera de 1 segundo
    robot.onMotors(FORWARD);
    delay(1000);
    robot.onMotors(BACKWARD);
    delay(1000);
    robot.offMotors();
}