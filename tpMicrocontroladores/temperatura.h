#include <DHT.h> //Incluyo las librerias correspondientes.
#define DHTPIN 5
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);

float temperatura; // almacena la temperatura

void leerTemperatura(){
  
   temperatura = dht.readTemperature();
   Serial.println(temperatura); 

    if (isnan(temperatura))
  {
      Serial.println("Error en la lectura del sensor DHT11");
      return;
  }

}
