#include <CVR_easyrobot.h>

EasyRobot robot; //Instancia de la clase EasyRobot

#define sensorDerecha 11 // Sensor infrarrojo https://www.cvrelectronica.com/description/?product_id=143
#define sensorIzquierda 12 // Sensor infrarrojo https://www.cvrelectronica.com/description/?product_id=143


void setup() {
  pinMode(sensorDerecha, INPUT); //Se configura el pin 11 (sensor derecho como entrada)
  pinMode(sensorIzquierda, INPUT); //Se configura el pin 12 (sensor izquierdo como entrada)
}

void loop() {

  robot.ledRGBEncenderColor(COLOR_AZUL); //Se establece el color azul al iniciar el programa
  delay(2000);  // Espera 2 segundos
  robot.ledRGBEncenderColor(COLOR_VERDE); //Se establece el color verde cuando no se detecta un obstaculo
  robot.encenderMotores(AVANZAR); //Se encienden ambos motores en modo avance

  while(1){
    if(!digitalRead(sensorIzquierda) || !digitalRead(sensorDerecha)){ // Se detecta la detección de un objeto cercano
      robot.ledRGBEncenderColor(COLOR_ROJO); //Se establece el color rojo cuando no se detecta un obstaculo
      robot.encenderMotores(RETROCEDER); //Se encienden ambos motores en modo reversa
      delay(1000); // Espera 2 segundos
      robot.apagarMotores(); //apagar ambos motores
      robot.onMotor1(RETROCEDER); //motor en avance - para giro
      robot.onMotor2(AVANZAR); //motor en retroceso - para giro
      delay(1000); // espera de 1 segundo
      robot.ledRGBEncenderColor(COLOR_VERDE); // Se establece el led en coor verde
    }else{
      robot.encenderMotores(AVANZAR); //Se encienden ambos motores en modo avance
    }
  }
}