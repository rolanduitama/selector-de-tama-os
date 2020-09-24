//Codigo hecho por Rafael Leal R
// Incluímos la librería para poder controlar el servo
#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo servoMotor;
 
void setup() {

  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 10
  servoMotor.attach(10);
 
  // Inicializamos al ángulo 0 el servomotor
  servoMotor.write(30);
  pinMode(14, INPUT);
  
}
 
void loop() {
  int x = LOW;
  unsigned long var = millis();
  while (millis() <= var + 10000 or x==HIGH) {
  x = !digitalRead(14);
  //Serial.println(x);
    if (x == HIGH) {
    for (int i = 179; i > 30; i--) {
    servoMotor.write(i);
    delay(3);
      }
    delay(1000);
    for (int i = 30; i <= 180; i++){
    servoMotor.write(i);
    delay(3);
      }
    }
  }
  Serial.println("PASO EL TIEMPO");
}
