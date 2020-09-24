//Codigo hecho por Rafael Leal R
// Incluímos la librería para poder controlar servos
#include <Servo.h>
//Incluímos la libreria del LCD
#include <LCD.h>
#include <Wire.h>   
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_SI2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);//Direccion de LCD
Servo S1;
Servo S2;
Servo S3;
Servo S4;
//Pines para el Motor
int PinIN1 = 7;
int PinIN2 = 8;
int ENA = 9;

//Pines 2,3,18,19 para la lectura de los fototransistores
volatile int contador = 0;// contador final
volatile int Validarcontador = 8;//Validación del contador
volatile int ValorTR = 0; //Valor fototransistores 
volatile int VarEstado = 0; //Variable de estación

void setup() {  
Serial.begin(9600);
//pines de entrada
pinMode(14, INPUT);// Brazo mecanico
pinMode(17, INPUT);// Fototransistor 4
//Interrupciones
attachInterrupt(digitalPinToInterrupt(2), FotoTR1, RISING);
attachInterrupt(digitalPinToInterrupt(3), FotoTR2, RISING);
attachInterrupt(digitalPinToInterrupt(18), FotoTR3, RISING);
//attachInterrupt(digitalPinToInterrupt(19), FotoTR4, RISING);
attachInterrupt(digitalPinToInterrupt(19), STOP,  RISING);
// Pines para el motor
pinMode(PinIN1, OUTPUT);
pinMode(PinIN2, OUTPUT);
pinMode(ENA , OUTPUT);

// Iniciamos servos para que empiecen a trabajar con los pines 9,10,11,12
  S1.attach(10);
  S2.attach(11);
  S3.attach(12);
  S4.attach(13);
// Inicializamos al ángulo 0 de los servomotores
  S1.write(180);
  S2.write(0);
  S3.write(0);
  S4.write(0);
lcd.begin(16,2);    // Indicamos medidas de LCD
lcd.clear();//Elimina todos los simbolos del LCD
}
void loop() {
BeginBanda();
//Estaciones de la banda
  //Primera estación
  if (ValorTR == 1 and VarEstado >= 0){
    StopBanda();
    //delay(1000);
    int x = LOW;
    unsigned long var = millis();
    while (millis() <= var + 10000) {
    //MUCHO OJO AQUI SE HACE LA LECTURA DEL BRAZO, QUE SERÍA LA SEÑAL DE LOS SENSORES
    x = !digitalRead(14);
      if (x == HIGH) {
        for (int i = 179; i > 30; i--) {
        S1.write(i);
        delay(3);
        }
        delay(1000);
        for (int i = 30; i <= 180; i++){
        S1.write(i);
        delay(3);
        }
        break;
        }
    }
    ValorTR = 0;
    //contador++;
    }
  //Segunda estación
  if (ValorTR == 2 and VarEstado > 0){
    StopBanda();
    delay(1000);
    int x = LOW;
    unsigned long var = millis();
    while (millis() <= var + 10000) {
    //MUCHO OJO AQUI SE HACE LA LECTURA DEL BRAZO, QUE SERÍA LA SEÑAL DE LOS SENSORES
    x = !digitalRead(14);
      if (x == HIGH) {
        for (int i = 179; i > 30; i--) {
        S1.write(i);
        delay(3);
        }
        delay(1000);
        for (int i = 30; i <= 180; i++){
        S1.write(i);
        delay(3);
        }
        break;
    }
  }
    ValorTR = 0;
  }
  //Tercera estación
  if (ValorTR == 3 and VarEstado > 0){
    StopBanda();
    delay(1000);
    int x = LOW;
    unsigned long var = millis();
    while (millis() <= var + 10000) {
    //MUCHO OJO AQUI SE HACE LA LECTURA DEL BRAZO, QUE SERÍA LA SEÑAL DE LOS SENSORES
    x = !digitalRead(14);
      if (x == HIGH) {
        for (int i = 179; i > 30; i--) {
        S1.write(i);
        delay(3);
        }
        delay(1000);
        for (int i = 30; i <= 180; i++){
        S1.write(i);
        delay(3);
        }
        ValorTR = 0;
        break;
    }
  }
    
  // Cuarta estación sin interrupción
    BeginBanda();
     x = 1;
    while (x == 1) {
    x = digitalRead(17);  
      if (x == 0) {
        ValorTR = 4;
        StopBanda();
        //delay(1000);
        int x = LOW;
        unsigned long var = millis();
        while (millis() <= var + 10000) {
        x = !digitalRead(14);
        if (x == HIGH) {
        for (int i = 179; i > 30; i--) {
        S1.write(i);
        delay(3);
        }
        delay(1000);
        for (int i = 30; i <= 180; i++){
        S1.write(i);
        delay(3);
        }
        Validarcontador = 0;
        break;
      }
      if (Validarcontador == 8) {Validarcontador = 1;}
    }
      if (Validarcontador == 1) {contador++;}
      ValorTR = 0;
      VarEstado = 0;
      }
    }
  /*//Cuarta estación
  if (ValorTR == 4 and VarEstado > 0){
    StopBanda();
    delay(1000);
    for (int i = 179; i > 30; i--) {
    S4.write(i);
    delay(3);
  }
  delay(1000);
  for (int i = 30; i <= 180; i++){
    S4.write(i);
    delay(3);
    }
    ValorTR = 0;
    VarEstado = 0;
  }
  */
  }
  if (VarEstado > 4){
    StopBanda ();
    //Display counter
    lcd.setCursor(0,0);//Posiciona el cursor         
    lcd.print("Contador= "); 
    lcd.setCursor(10,0);
    lcd.print(contador);
    delay (60000);
    lcd.clear();//Elimina todos los simbolos del LCD
    contador = 0;
    VarEstado = 0;
    }
}
void BeginBanda(){
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  analogWrite(ENA,50); //PWM para la velocidad del motor
}


void FotoTR1 () {
  VarEstado++;
  //contador++;
  ValorTR = 1; 
} 

void FotoTR2 () {
  ValorTR = 2;
  VarEstado++;
}

void FotoTR3 () {
  ValorTR = 3;
  VarEstado++;
}

/*void FotoTR4 () {
  ValorTR = 4;
  VarEstado++;
}*/

void StopBanda () {
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);
  analogWrite(ENA,0); //PWM para la velocidad del motor
}

void STOP () {
  //digitalWrite (PinIN1, LOW);
  //digitalWrite (PinIN2, LOW);
int  Boton = digitalRead(19); 
  if (Boton==1){
    ValorTR = 0;
    VarEstado = 8;  
    }
}
