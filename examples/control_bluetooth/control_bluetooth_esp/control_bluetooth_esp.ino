#include <CVR_easyrobot.h>

EasyRobot robot; //Instancia de la clase EasyRobot


void setup() {
  Serial.begin(115200);
}

void loop() {
  if(Serial.available() > 0){
    char c = Serial.read();
    if(c == '1'){
      robot.encenderMotores(AVANZAR);
    }else if(c == '5'){
      robot.apagarMotores();
    }else if(c == '2'){
      robot.encenderMotor1(RETROCEDER);
      robot.encenderMotor2(AVANZAR);
    }else if(c == '3'){
      robot.encenderMotor1(AVANZAR);
      robot.encenderMotor2(RETROCEDER);
    }else if(c == '4'){
      robot.encenderMotores(RETROCEDER);
    }else if(c == '6'){
      robot.ledRGBEncenderColor(COLOR_ROJO);
    }else if(c == '7'){
      robot.ledRGBEncenderColor(COLOR_VERDE);
    }else if(c == '8'){
      robot.ledRGBEncenderColor(COLOR_AZUL);
    }else if(c == '9'){
      robot.ledRGBEncenderColor(APAGADO);
    }
  }

}
