/**
 * /************************************************************************
 *            Easy Robot - CVR ELECTRÓNICA                                 *
 *              Autor: Cristian Valdez R                                   *
 *           Url Github: https://github.com/                               *
 * Documentación: https://cvrelectronica.com/easyrobot/doc                 *
 *                       Versiones:                                        *        
 *                      1.0 - Actual                                       *
 ***************************************************************************
 ***************************************************************************
 * EasyRobot Es una tarjeta de desarrollo que simplifica y facilita        *
 * el proceso de desarrollo y ensamble de tu proyecto de robótica.         *
 * EasyRobot está basada en el microcontrolador Atmega328p de Microchip    *
 * precargado con el bootloader de Arduino UNO, por lo que es totalmente   *
 * compatible con el IDE de Arduino y cualquier software compatible.       *
 * Integra todos los componentes necesarios para la fácil implementación   *
 * de tu proyecto de robótica, lo que te ahorrará un motón de tiempo de    *
 * conexión entre componentes ya que todos los componetes se encuentran    *
 * interconectados de tal forma que se aproveche en gran medida los pines  *
 * disponibles en el microcontrolador según nuestra experiencia.           *
 ***************************************************************************/
#include "CVR_easyrobot.h"
#include <Servo.h>

Servo srv;

EasyRobot::EasyRobot() {
    pinMode(M1A, OUTPUT);
    pinMode(M1B, OUTPUT);
    pinMode(M2A, OUTPUT);
    pinMode(M2B, OUTPUT);
    pinMode(LEDONBOARD, OUTPUT);
    pinMode(PUSHBUTTON, INPUT_PULLUP);
    pinMode(NEOPIXELDATAPIN,OUTPUT);
    digitalWrite(NEOPIXELDATAPIN,0);
    delayMicroseconds(50);
}

void EasyRobot::enablePwm(){
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
}

void EasyRobot::activarPwm(){
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
}

void EasyRobot::setVelocity(uint8_t m, uint8_t v){
    _motor = m;
    _pwm = map(v,0,100,0,255);
    switch(_motor){
        case 1:
            analogWrite(6,_pwm);
            break;
        case 2:
            analogWrite(5,_pwm);
            break;
    }
}

void EasyRobot::configurarVelocidad(uint8_t m, uint8_t v){
    _motor = m;
    _pwm = map(v,0,100,0,255);
    switch(_motor){
        case 1:
            analogWrite(6,_pwm);
            break;
        case 2:
            analogWrite(5,_pwm);
            break;
    }
}

void EasyRobot::onMotor1(uint8_t d = FORWARD) {
    _md = d;
    switch(_md){
        case 1:
            digitalWrite(M1A, HIGH);
            digitalWrite(M1B, LOW);
            break;
        case 0:
            digitalWrite(M1A, LOW);
            digitalWrite(M1B, HIGH);
            break;
    }
    
}

void EasyRobot::onMotor2(uint8_t d = FORWARD) {
    _md = d;
    switch(_md){
        case 1:
            digitalWrite(M2A, HIGH);
            digitalWrite(M2B, LOW);
            break;
        case 0:
            digitalWrite(M2A, LOW);
            digitalWrite(M2B, HIGH);
            break;
    }
}

void EasyRobot::onMotors(uint8_t d = FORWARD, uint8_t v = 255) {
    _md = d;
    switch(_md){
        case 1:
            digitalWrite(M1A, HIGH);
            digitalWrite(M1B, LOW);
            digitalWrite(M2A, HIGH);
            digitalWrite(M2B, LOW);
            break;
        case 0:
            digitalWrite(M1A, LOW);
            digitalWrite(M1B, HIGH);
            digitalWrite(M2A, LOW);
            digitalWrite(M2B, HIGH);
            break;
    }

}

void EasyRobot::offMotors(){
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, LOW); 
}
void EasyRobot::encenderMotor1(uint8_t d = FORWARD) {
    _md = d;
    switch(_md){
        case 1:
            digitalWrite(M1A, HIGH);
            digitalWrite(M1B, LOW);
            break;
        case 0:
            digitalWrite(M1A, LOW);
            digitalWrite(M1B, HIGH);
            break;
    }
    
}

void EasyRobot::encenderMotor2(uint8_t d = FORWARD) {
    _md = d;
    switch(_md){
        case 1:
            digitalWrite(M2A, HIGH);
            digitalWrite(M2B, LOW);
            break;
        case 0:
            digitalWrite(M2A, LOW);
            digitalWrite(M2B, HIGH);
            break;
    }
}

void EasyRobot::encenderMotores(uint8_t d = FORWARD, uint8_t v = 255) {
    _md = d;
    switch(_md){
        case 1:
            digitalWrite(M1A, HIGH);
            digitalWrite(M1B, LOW);
            digitalWrite(M2A, HIGH);
            digitalWrite(M2B, LOW);
            break;
        case 0:
            digitalWrite(M1A, LOW);
            digitalWrite(M1B, HIGH);
            digitalWrite(M2A, LOW);
            digitalWrite(M2B, HIGH);
            break;
    }

}

void EasyRobot::apagarMotores() {
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, LOW); 
}

void EasyRobot::enableServo(){
    srv.attach(2);
}
void EasyRobot::servoPosition(uint8_t p){
    _servoPos = p;
    srv.write(_servoPos); 
}

void EasyRobot::activarServo(){
    srv.attach(2);
}
void EasyRobot::posicionServo(uint8_t p){
    _servoPos = p;
    srv.write(_servoPos); 
}

void EasyRobot::ledRGBSetColor(uint8_t r, uint8_t g, uint8_t b){
    unsigned char color[3] = {g , r , b};
    for(char i =0; i < 2; i++){
        // Serial.println("Si")
        for(int i = 0; i < 3; i++){ 
            unsigned char val = color[i];
            for(char x =0; x<8; x++){
               neopixel_sendBit((val & 0x80));
                val = val << 1;
            }
        }
    }
    neopixel_reset();
}

void EasyRobot::ledRGBEncenderColor(uint8_t r, uint8_t g, uint8_t b){
    unsigned char color[3] = {g , r , b};
    for(char i =0; i < 2; i++){
        // Serial.println("Si")
        for(int i = 0; i < 3; i++){ 
            unsigned char val = color[i];
            for(char x =0; x<8; x++){
               neopixel_sendBit((val & 0x80));
                val = val << 1;
            }
        }
    }
    neopixel_reset();
}

void EasyRobot::neopixel_reset(){
    digitalWrite(NEOPIXELDATAPIN,0);
    delayMicroseconds(50);
}

void EasyRobot::sendByte(uint8_t byte) {
    for (int i = 7; i >= 0; i--) { // Enviar bit a bit, de MSB a LSB
        neopixel_sendBit(byte & (1 << i)); // Enviar el bit más significativo primero
    }
}

void EasyRobot::neopixel_sendBit(bool bitVal) {
    if (bitVal) {
        // Enviar un '1'
        PORTB |= (1 << PB5); // Pin 13 en HIGH
        __asm__ __volatile__ ("nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t"); // Mantener HIGH ~0.8us
        PORTB &= ~(1 << PB5); // Pin 13 en LOW
        __asm__ __volatile__ ("nop\n\t" "nop\n\t"); // Mantener LOW ~0.45us
    } else {
        // Enviar un '0'
        PORTB |= (1 << PB5); // Pin 13 en HIGH
        __asm__ __volatile__ ("nop\n\t" "nop\n\t"); // Mantener HIGH ~0.4us
        PORTB &= ~(1 << PB5); // Pin 13 en LOW
        __asm__ __volatile__ ("nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t"); // Mantener LOW ~0.85us
    }
}

uint8_t EasyRobot::readButton(){
    return digitalRead(PUSHBUTTON);
}

uint8_t EasyRobot::leerBoton(){
    return digitalRead(PUSHBUTTON);
}