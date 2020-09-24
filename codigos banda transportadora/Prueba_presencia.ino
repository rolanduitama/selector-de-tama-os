//Codigo hecho por Rafael Leal R
//*
volatile int ValorTR = 0;
int n = ValorTR;

void setup() {
  Serial.begin(9600); 
  attachInterrupt(digitalPinToInterrupt(2), FotoTR1, RISING);
  attachInterrupt(digitalPinToInterrupt(3), FotoTR2, RISING);
  attachInterrupt(digitalPinToInterrupt(18), FotoTR3, RISING);
  attachInterrupt(digitalPinToInterrupt(19), FotoTR4, RISING);
}

void loop() {
  if (n != ValorTR)
    {Serial.print("ValorTR = " );                       
     Serial.println(ValorTR);
     ValorTR = 0;
     n = ValorTR; 
      }
     
}
void FotoTR1 () {
  ValorTR = 1;
  }
void FotoTR2 () {
  ValorTR = 2;
  }
void FotoTR3 () {
  ValorTR = 3;
  }
void FotoTR4 () {
  ValorTR = 4;
  }
//*/
/*
const int emuPin = 10; 
const int LEDPin = 13;
const int intPin = 3;
volatile int state = LOW;
 
void setup() {
   pinMode(emuPin, OUTPUT);
   pinMode(LEDPin, OUTPUT);
   //pinMode(intPin, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(intPin), blink, RISING);
}
 
void loop() {
   //esta parte es para emular la salida
   digitalWrite(emuPin, HIGH);
   delay(150);
   digitalWrite(emuPin, LOW);
   delay(150);
}
 
void blink() {
   state = !state;
   digitalWrite(LEDPin, state);
}
*/
