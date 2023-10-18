const int SENSOR_HC_TRIG = 3;
const int SENSOR_HC_ECHO = 2;
const int LED_VIBR = 10; 
const int SENSOR_VIBR = 7;
const int LED_AMAR = 6;
const int LED_VER = 5 ;
const int LED_VERM = 4;
int distancia;

byte BUZZER_HC = 9;

void setup(){
  	Serial.begin(9600);
	pinMode(SENSOR_HC_TRIG,OUTPUT);
  	pinMode(SENSOR_HC_ECHO,INPUT);
    pinMode(LED_VERM, OUTPUT);
    pinMode(LED_AMAR, OUTPUT);
    pinMode(LED_VER, OUTPUT);  
    pinMode(SENSOR_VIBR , INPUT); 
  pinMode(LED_VIBR, OUTPUT); 
  digitalWrite(LED_VIBR, LOW); 
}

void loop(){
   leds();
   vibracao();
   sirene();
}

double sensorHc() {
  digitalWrite(SENSOR_HC_TRIG , HIGH); 
  delayMicroseconds(10);
  digitalWrite(SENSOR_HC_TRIG, LOW); 
  double duracao = pulseIn(SENSOR_HC_ECHO, HIGH); 
  distancia = duracao * 0.017175;

  return distancia;

  Serial.print(distancia);
  Serial.println(" cm");
}

void leds(){
  sensorHc(); 
  if(distancia < 11){
    digitalWrite(LED_VER, LOW);
    digitalWrite(LED_AMAR, LOW);
    digitalWrite(LED_VERM, HIGH);

  }
  if(distancia > 10 && distancia < 25){
    digitalWrite(LED_VERM, LOW);
    digitalWrite(LED_AMAR, LOW);
    digitalWrite(LED_VER, HIGH);
  }  
  if(distancia > 25){
   digitalWrite(LED_VERM, LOW);
   digitalWrite(LED_VER, LOW);
    digitalWrite(LED_AMAR, HIGH);

  } 
}

void vibracao(){
  sensorHc(); 
  if(digitalRead(SENSOR_VIBR) == HIGH){ 
      digitalWrite(LED_VIBR, HIGH); 
  }else{ 
    digitalWrite(LED_VIBR, LOW); 
  }
}

void sirene(){
  sensorHc(); 
  if(distancia >= 18){
    tone(BUZZER_HC, 581, 851);
  } else {
    noTone(BUZZER_HC);
  }
}