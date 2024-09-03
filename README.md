# EasyRobot - CVR ELECTRÓNICA

EasyRobot es una tarjeta de desarrollo diseñada por CVR Electrónica que simplifica y facilita el proceso de desarrollo y ensamble de proyectos de robótica. Basada en el microcontrolador Atmega328p y compatible con Arduino UNO, EasyRobot integra todos los componentes necesarios para implementar tu proyecto de robótica de manera eficiente, ahorrando tiempo y esfuerzo en la interconexión de componentes.
Características

### Compatibilidad: 
    Totalmente compatible con el IDE de Arduino y cualquier software compatible con Arduino UNO.

# Instalación

    Descarga la librería desde el repositorio o desde el Arduino Library Manager.
    Abre el IDE de Arduino.
    Ve a Sketch -> Include Library -> Add .ZIP Library... y selecciona el archivo .zip de la librería.
    La librería ahora está lista para ser utilizada en tus proyectos.

# Ejemplos de Uso

## Control de motores

Este ejemplo demuestra cómo configurar los motores y moverlos en ambos sentidos.

```cpp

#include 

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
```
## Control de un Servo Motor

Este ejemplo muestra cómo controlar un servo motor usando EasyRobot.

```cpp

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
```

## Control de LED RGB

Controla un LED RGB Neopixel para mostrar diferentes colores.


```cpp
#include <CVR_easyrobot.h>

EasyRobot robot;
                        
void setup() {
    robot.ledRGBSetColor(RED_COLOR);
    delay(300);
    robot.ledRGBSetColor(GREEN_COLOR);
    delay(300);
    robot.ledRGBSetColor(BLUE_COLOR);
    delay(300);
}
                        
void loop() {
    for(int c=0;c<256;c++){
      robot.ledRGBSetColor(c,255-c,255);
      delay(20);
    }for(int c=0;c<256;c++){
      robot.ledRGBSetColor(255-c,c,255);
      delay(20);
    }
    for(int c=0;c<256;c++){
      robot.ledRGBSetColor(255,c,255-c);
      delay(20);
    }
    for(int c=0;c<256;c++){
      robot.ledRGBSetColor(255,255-c,c);
      delay(20);
    }
}  
```

# Documentación Completa

Consulta la documentación completa para más detalles sobre cómo usar todos los métodos disponibles en la librería: https://cvrelectronica.com/easyrobot/doc/

# Contribuciones

Si deseas contribuir al desarrollo de EasyRobot, comunicate con nosotros via email al correo electrónico develop@cvrelectronica.com. Todo aporte es muy valioso para el proyecto.

## Licencia

Esta librería está licenciada bajo la MIT License.

## Contacto

Para cualquier pregunta o sugerencia, puedes contactarnos a través de nuestro correo electrónico: develop@cvrelectronica.com