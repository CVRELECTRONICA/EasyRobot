#include <CVR_easyrobot.h>

EasyRobot robot;
                        
void setup() {
    robot.activarPwm(); // activa el control por PWM
    robot.configurarVelocidad(MOTOR2, 70); // 75% de velocidad
    robot.configurarVelocidad(MOTOR1, 70); // 75% de velocidad
}
                        
void loop() {
    robot.encenderMotor1(AVANZAR); //giro en avance
    delay(1000); //espera de 1 segundo
    robot.encenderMotor1(RETROCEDER); //giro en retroceso
    delay(1000); //espera de 1 segundo
    robot.apagarMotores();
    robot.encenderMotor2(AVANZAR); //giro en avance
    delay(1000); //espera de 1 segundo
    robot.encenderMotor2(RETROCEDER); //giro en retroceso
    delay(1000); //espera de 1 segundo
    robot.encenderMotores(AVANZAR);
    delay(1000);
    robot.encenderMotores(RETROCEDER);
    delay(1000);
    robot.apagarMotores();
}