#include <CVR_easyrobot.h>

EasyRobot robot; //Instancia de la clase EasyRobot


void setup() {
  Serial.begin(115200);
}

void loop() {
  if(Serial.available() > 0){
    char c = Serial.read();
    if(c == '1'){
      robot.onMotors(FORWARD);
    }else if(c == '5'){
      robot.apagarMotores();
    }else if(c == '2'){
      robot.onMotor1(BACKWARD);
      robot.onMotor2(FORWARD);
    }else if(c == '3'){
      robot.onMotor1(FORWARD);
      robot.onMotor2(BACKWARD);
    }else if(c == '4'){
      robot.onMotors(BACKWARD);
    }else if(c == '6'){
      robot.ledRGBSetColor(COLOR_ROJO);
    }else if(c == '7'){
      robot.ledRGBSetColor(COLOR_VERDE);
    }else if(c == '8'){
      robot.ledRGBSetColor(COLOR_AZUL);
    }else if(c == '9'){
      robot.ledRGBSetColor(APAGADO);
    }
  }

}
