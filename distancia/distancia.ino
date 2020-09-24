// AUTOR fsancac @tecnorik
//modificaciones Rolando Duitama

#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_SI2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
const int Trigger2 = 12;   //Pin digital 2 para el Trigger del sensor
const int Echo2= 13;
const int Buzzer = 9; // pin digital buzzer



void setup() {
  lcd.begin(16, 2);
  lcd.home ();
  //-------------------------------------------------- senrsor 1
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  pinMode(Buzzer, OUTPUT);
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  
  //--------------------------------------------------sensor 2
  pinMode(Trigger2, OUTPUT);
  pinMode(Echo2, INPUT);
  digitalWrite(Trigger2, LOW);
  Serial.begin(9600); //iniciailzamos la comunicación
}

void loop()
{

  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
  long ref=16;
  long mide;

  digitalWrite(Trigger, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(Trigger, LOW);
  
//--------------------------------------------------------------
 
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;    //escalamos el tiempo a una distancia en cm
  lcd.setCursor(1, 0);
  lcd.print("sensor1:"); 
  mide=ref-d;
  lcd.print(mide); 
  lcd.print("cm    ");
  lcd.println();

//-------------------------------------------------------------------  
long t2; //timepo que demora en llegar el eco
long d2; //distancia en centimetros
long ref2=17;
long mide2;
  
digitalWrite(Trigger2, HIGH);
delayMicroseconds(10); 
digitalWrite(Trigger2, LOW);

t2 = pulseIn(Echo2, HIGH); //obtenemos el ancho del pulso
d2 = t2/59; 
lcd.setCursor(1, 2);
lcd.print("sensor2:");
mide2=ref2-d2;
lcd.print(mide2);  //Enviamos serialmente el valor de la distancia
lcd.print("cm    ");
lcd.println();
  
 
 if (mide<=7&& mide>6 ){
  tone (9,300,400);// 9 es el pin del buzzer y 300 la feceuncia
  delay(1000);
   }
else{
   noTone (9);
   delay(200);
   
 }     

 if (mide2<=7&& mide2>6 ){
  tone (9,300,400);// 9 es el pin del buzzer y 300 la feceuncia
  delay(1000);
   }
else{
   noTone (9);
   delay(200);
   
 }     
 
 delay(100);          //Hacemos una pausa de 100ms

        }
