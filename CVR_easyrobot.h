/********************************************************************
 *            Easy Robot - CVR ELECTRÓNICA                          *
 *              Autor: Cristian Valdez R                            *
 *           Url Github: https://github.com/                        *
 * Documentación: https://cvrelectronica.com/easyrobot/doc          *
 *                       Versiones:                                 *        
 *                      1.0 - Actual                                *
 ********************************************************************/
#ifndef _CVREASYROBOT_H
#define _CVREASYROBOT_H

#include <Arduino.h>

#define AVANZAR 1
#define RETROCEDER 0
#define FORWARD 1
#define BACKWARD 0

#define M1A 9
#define M1B 10
#define M2A 7
#define M2B 8

#define MOTOR1 1
#define MOTOR2 2

#define LEDONBOARD 3
#define LEDENPLACA 3

#define SERVO 2

#define NEOPIXELDATAPIN 13
#define RED_COLOR    255, 0, 0
#define GREEN_COLOR  0, 255, 0
#define BLUE_COLOR   0, 0, 255
#define WHITE_COLOR  255, 255, 255
#define BLACK_COLOR  0, 0, 0
#define COLOR_ROJO   255, 0, 0
#define COLOR_VERDE  0, 255, 0
#define COLOR_AZUL   0, 0, 255
#define COLOR_BLANCO 255, 255, 255
#define COLOR_NEGRO  0, 0, 0
#define APAGADO  0, 0, 0
#define OFF  0, 0, 0

#define PUSHBUTTON 4

class EasyRobot {

public:
    EasyRobot();    // Constructor
    void enablePwm(); // Activa el control PWM pines 5 y 5 enfocados al control PWM (salidas)
    void activarPwm(); // Activa el control PWM pines 5 y 5 enfocados al control PWM (salidas)
    void setVelocity(uint8_t m , uint8_t v); //Configura la velocidad del motor
    void configurarVelocidad(uint8_t m , uint8_t v);//Configura la velocidad del motor
    void onMotor1(uint8_t d = FORWARD);         // Método para encender el motor 1
    void onMotor2(uint8_t d = FORWARD);        // Método para encender el motor 2
    void onMotors(uint8_t d, uint8_t v = 255); // Método para hacer los dos motores
    void offMotors(void); //apagar motores
    void encenderMotor1(uint8_t d = FORWARD);         // Método para encender el motor 1
    void encenderMotor2(uint8_t d = FORWARD);        // Método para encender el motor 2
    void encenderMotores(uint8_t d = FORWARD, uint8_t v = 255); // Método para hacer los dos motores
    void apagarMotores(); //apaga los motores
    void enableServo(); //activa la salida para el control del servomotor
    void activarServo(void); //activa la salida para el control del servomotor
    void servoPosition(uint8_t p); //Posiciona el servomotor
    void posicionServo(uint8_t p);//Posiciona el servomotor
    void ledRGBSetColor(uint8_t r, uint8_t g, uint8_t b); //Enciende el led con el color requerido
    void ledRGBEncenderColor(uint8_t r, uint8_t g, uint8_t b); //Enciende el led con el color requerido
    uint8_t readButton(); //Lee el estado del boton en la placa
    uint8_t leerBoton(); //Lee el estado del boton en la placa

private:
    uint8_t _pwm; // pwm motores
    uint8_t _md; // direción del motor
    uint8_t _motor; // index del motor
    uint8_t _servoPos; // posiciión del servo motor
    
    void neopixel_reset();
    void sendByte(uint8_t byte);
    void neopixel_sendBit(bool bitVal);
};

#endif
