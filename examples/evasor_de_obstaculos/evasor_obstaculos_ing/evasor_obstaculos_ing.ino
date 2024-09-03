#include <CVR_easyrobot.h>

EasyRobot robot; //Instancia de la clase EasyRobot

#define rightSensor 11 // Sensor infrarrojo https://www.cvrelectronica.com/description/?product_id=143
#define leftSensor 12 // Sensor infrarrojo https://www.cvrelectronica.com/description/?product_id=143


void setup() {
  pinMode(rightSensor, INPUT); //Se configura el pin 11 (sensor derecho como entrada)
  pinMode(leftSensor, INPUT); //Se configura el pin 12 (sensor izquierdo como entrada)
}

void loop() {

  robot.ledRGBSetColor(BLUE_COLOR); //Se establece el color azul al iniciar el programa
  delay(2000);  // Espera 2 segundos
  robot.ledRGBSetColor(GREEN_COLOR); //Se establece el color verde cuando no se detecta un obstaculo
  robot.onMotors(FORWARD); //Se encienden ambos motores en modo avance

  while(1){
    if(!digitalRead(leftSensor) || !digitalRead(rightSensor)){ // Se detecta la detección de un objeto cercano
      robot.ledRGBSetColor(RED_COLOR); //Se establece el color rojo cuando no se detecta un obstaculo
      robot.onMotors(BACKWARD); //Se encienden ambos motores en modo reversa
      delay(1000); // Espera 2 segundos
      robot.apagarMotores(); //apagar ambos motores
      robot.onMotor1(BACKWARD); //motor en avance - para giro
      robot.onMotor2(FORWARD); //motor en retroceso - para giro
      delay(1000); // espera de 1 segundo
      robot.ledRGBSetColor(GREEN_COLOR); // Se establece el led en coor verde
    }else{
      robot.onMotors(FORWARD); //Se encienden ambos motores en modo avance
    }
  }
}