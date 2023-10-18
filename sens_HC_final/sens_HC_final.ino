const int SENSOR_HC_TRIG = 6;
const int SENSOR_HC_ECHO = 7;
const int LED_AMAR = 2;
const int LED_VER = 4 ;
const int LED_VERM = 3;
byte BUZZER_HC = 5;

double distancia;

void setup(){
  Serial.begin(9600);
  pinMode(SENSOR_HC_TRIG,OUTPUT);
  pinMode(SENSOR_HC_ECHO,INPUT);
  pinMode(LED_VERM, OUTPUT);
  pinMode(LED_AMAR, OUTPUT);
  pinMode(LED_VER, OUTPUT);
}

void loop(){
  leds();
  tocarBuz();
  console();
}

double sensorHc() {
  digitalWrite(SENSOR_HC_TRIG , HIGH); 
  delayMicroseconds(10);
  digitalWrite(SENSOR_HC_TRIG, LOW); 
  double duracao = pulseIn(SENSOR_HC_ECHO, HIGH); 
  distancia = duracao * 0.017175;
  return distancia;
}
 

void leds(){
  sensorHc();
  if(distancia < 10){
    digitalWrite(LED_VERM, HIGH);
    digitalWrite(LED_VER, LOW);
    digitalWrite(LED_AMAR, LOW);
  }else if(distancia > 11 && distancia < 20){
   digitalWrite(LED_VERM, LOW);
   digitalWrite(LED_VER, LOW);
   digitalWrite(LED_AMAR, HIGH);
  }else if (distancia > 21){
   digitalWrite(LED_VERM, LOW);
   digitalWrite(LED_VER, HIGH);
   digitalWrite(LED_AMAR, LOW);
  } 
}

void tocarBuz(){
    sensorHc();
  if(distancia <= 10){
    tone(BUZZER_HC, 581, 851);
  } else {
    noTone(BUZZER_HC);
  }
}

void console(){
  sensorHc();
  
  Serial.print(" Distancia ");
  Serial.println(distancia);
  delay(1000);
}