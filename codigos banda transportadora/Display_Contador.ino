//Codigo hecho por Rafael Leal R
#include <LCD.h>
#include <Wire.h>   
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_SI2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);//Direccion de LCD
volatile int Variableconteo = 0;
volatile int x=0;
void setup() {
  Serial.begin(9600);
//Interrupcion
attachInterrupt(digitalPinToInterrupt(19), STOP, RISING);  
//Inicializar LCD
lcd.begin(16,2);    // Indicamos medidas de LCD
lcd.clear();//Elimina todos los simbolos del LCD
}

void loop() {
  Variableconteo++;
    if (x>0){
      lcd.setCursor(0,0);//Posiciona la primera letra despues del segmento 5 en linea 1              
      lcd.print("Contador="); 
      lcd.setCursor(10,0);
      lcd.print(Variableconteo);
      delay(3000);
      Variableconteo = 0;
      lcd.clear();//Elimina todos los simbolos del LCD
      }
 delay (1000);
 Serial.print(x);
}
void STOP (){
  x=!x; 
  }
  
