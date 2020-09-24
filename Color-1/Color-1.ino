#define S0 8                                  //Tomado de: http://robots-argentina.com.ar/didactica/arduino-reconocer-colores-con-el-modulo-tcs230/ editado
#define S1 9
#define S2 12
#define S3 11
#define salidaSensor 10

const int LED_G=22;
const int LED_O=24;
const int LED_Y=26;

 
// Para guardar las frecuencias de los fotodiodos
int frecuenciaRojo = 0;
int frecuenciaVerde = 0;
int frecuenciaAzul = 0;
 
void setup() {
  // Definiendo las Salidas
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(LED_G,OUTPUT);
  pinMode(LED_O,OUTPUT);
  pinMode(LED_Y,OUTPUT);
  
  // Definiendo salidaSensor como entrada
  pinMode(salidaSensor, INPUT);
  // Definiendo la escala de frecuencia a 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
   // Iniciar la comunicacion serie 

  
  Serial.begin(9600);
}
void loop() {
  // Definiendo la lectura de los fotodiodos con filtro rojo
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Leyendo la frecuencia de salida del sensor
  frecuenciaRojo = pulseIn(salidaSensor, LOW);
  // Mostrando por serie el valor para el rojo (R = Red)
  Serial.print("R = ");
  Serial.print(frecuenciaRojo);
  delay(100);
  // Definiendo la lectura de los fotodiodos con filtro verde
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Leyendo la frecuencia de salida del sensor
  frecuenciaVerde = pulseIn(salidaSensor, LOW);
  // Mostrando por serie el valor para el verde (G = Green)
  Serial.print(" G = ");
  Serial.print(frecuenciaVerde);
  delay(100);
  // Definiendo la lectura de los fotodiodos con filtro azul
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Leyendo la frecuencia de salida del sensor
  frecuenciaAzul = pulseIn(salidaSensor, LOW);
  // Mostrando por serie el valor para el azul (B = Blue)
  Serial.print(" B = ");
  Serial.println(frecuenciaAzul);
  delay(100);

if (frecuenciaRojo >= 10 &&  frecuenciaRojo <= 50){ //SELECCIÓN DE RANGOS PARA SELECCIÓN DE COLOR
  if (frecuenciaVerde >= 20 && frecuenciaVerde <= 50){
    if (frecuenciaAzul >= 30 && frecuenciaAzul <= 80){
      digitalWrite(LED_Y,HIGH);
      Serial.println("YELLOW");                       //TURN LED YELLOW
    }
  }
  else if (frecuenciaVerde >= 61 && frecuenciaVerde <= 130){
    if (frecuenciaAzul >= 60 && frecuenciaAzul <= 115){
      digitalWrite(LED_O,HIGH);
      Serial.println("ORANGE");                     //TURN LED ORANGE
    }
  }
  else {
    Serial.println("NONE");
    digitalWrite(LED_G,LOW);
    digitalWrite(LED_O,LOW);
    digitalWrite(LED_Y,LOW);
  }
}
else if (frecuenciaRojo >= 110 &&  frecuenciaRojo <= 190){
  if (frecuenciaVerde >= 60 && frecuenciaVerde <= 120){
    if (frecuenciaAzul >= 80 && frecuenciaAzul <= 150){
      digitalWrite(LED_G,HIGH);
      Serial.println("GREEN");                      //TURN LED GREEN
    }
  }
  else {
   Serial.println("NONE");
   digitalWrite(LED_G,LOW);
   digitalWrite(LED_O,LOW);
   digitalWrite(LED_Y,LOW);
  }
}
else {
  Serial.println("NONE");
  digitalWrite(LED_G,LOW);
  digitalWrite(LED_O,LOW);
  digitalWrite(LED_Y,LOW);
}
}
