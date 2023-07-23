#include <Wire.h> //Incluyo las librerias necesarias
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //fijamos la direccion del LCD y aclaramos que es del tipo 16x2

 void mostrarTemperatura(float t){
   lcd.setCursor(0,0);
   lcd.print(" Sistema Hogar ");  //nos ubicamos en al posicion 0,0 del LCD
   lcd.setCursor(9,1);
   lcd.print("T: ");
   lcd.print(temperatura);
 }
 
void estadoLuz(int e){
  if(e == true){
  lcd.setCursor(0,1);  //nos ubicamos en al posicion 0,0 del LCD
  lcd.print("Luz:ON ");  //imprimimos mensaje
 }else{
  lcd.setCursor(0,1);  //nos ubicamos en al posicion 0,0 del LCD
  lcd.print("Luz:OFF");  //imprimimos mensaje
 }
}



 
