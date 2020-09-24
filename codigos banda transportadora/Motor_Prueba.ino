//Codigo hecho por Rafael Leal R
//Las funciones y las variables para control del l298 se saco de la pagina de naylampmechatronics.com
//Modificado por Rafael Leal R.
int LED = 13;
const int Banda = 150;
long Time = 0;
volatile int Apa = HIGH;
int PinIN1 = 7;
int PinIN2 = 8;
int ENA = 9;
volatile int ValorTR = 0;

void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  //Serial.begin(9600);
  // configuramos los pines como salida
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(ENA , OUTPUT);
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), FotoTR1, RISING);
  attachInterrupt(digitalPinToInterrupt(3), FotoTR2, RISING);
  attachInterrupt(digitalPinToInterrupt(18), FotoTR3, RISING);
  attachInterrupt(digitalPinToInterrupt(19), FotoTR4, RISING);
}

void loop() {
  MotorHorario();
  analogWrite(ENA,50); //PWM para la velocidad del motor
  if(ValorTR != 0){
    MotorStop();
    analogWrite(ENA,0); //PWM para la velocidad del motor
    Serial.println("Giro del Motor en en pausa");
    delay(5000);
    ValorTR=0;
  }
  
}
void FotoTR1 () {
  ValorTR = 1;
  digitalWrite (LED,Apa);
  Apa = !Apa;
  }
void FotoTR2 () {
  ValorTR = 2;
  digitalWrite (LED,Apa);
  Apa = !Apa;
  }
void FotoTR3 () {
  ValorTR = 3;
  digitalWrite (LED,Apa);
  Apa = !Apa;
  }
void FotoTR4 () {
  if(millis() - Time > Banda){
    ValorTR = 4;
    digitalWrite (LED,Apa);
    Apa = !Apa;
    Time = millis();
    }
  }
void MotorHorario()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
}
void MotorAntihorario()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
}

void MotorStop()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);
}
