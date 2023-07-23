#include "temperatura.h"   //Incluyo los ficheros necesarios
#include "pantalla.h"

#define rele 10           //Defino e inicializo variables
#define pulsador 2        //ISR 0

volatile int estado = LOW;

float tiempo = 0;       //Para realizar las mediciones de temperatura cada cierto tiempo.
float tanterior = 0;    //Para controlar el rebote del pulsador.


void setup()
{
  Serial.begin(9600);
  lcd.init();         
  lcd.backlight();    
  dht.begin();
  pinMode(rele, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), handler_ISR_EXT, FALLING); //0>>PIN2, 1>>PIN3
}

void loop()
{  
 digitalWrite(rele, estado);

 if((millis() - tiempo) > 5000){ //Leo la temperatura en intervalos de 5seg.
    leerTemperatura();
    tiempo = millis();
  }

  mostrarTemperatura(temperatura);
  estadoLuz(estado);

}

void handler_ISR_EXT()
{                               
   if((millis()-tanterior)>200) 
  {                                
    estado = !estado;  
  }
    tanterior=millis(); 
}
