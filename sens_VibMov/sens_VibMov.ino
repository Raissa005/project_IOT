#define pinPIR 2
const int LED_PR = 3;
//const int SENSOR_PR = 2;
const int LED_VIBR = 5; 
const int SENSOR_VIBR = 4; 

bool returnMov;

void setup(){
    pinMode(pinPIR, INPUT);
    Serial.begin(115200);
    pinMode(LED_PR, OUTPUT); 
    pinMode(SENSOR_VIBR , INPUT); 
    pinMode(LED_VIBR, OUTPUT);
    digitalWrite(LED_VIBR, LOW);
}

void loop(){
  sensorMov();
  console();
  vibracao();
}

double sensorMov(){
 	returnMov = digitalRead(pinPIR); 
  
  if(!returnMov){
    digitalWrite(LED_PR, LOW);
  }else{
    digitalWrite(LED_PR, HIGH);
  }
}

void console(){
  sensorMov();
  
  Serial.print(" Movimento ");
  Serial.println(returnMov);
  //delay(1000);
}

void vibracao(){
  if(digitalRead(SENSOR_VIBR) == HIGH){ 
      digitalWrite(LED_VIBR, HIGH); 
  }else{ 
    digitalWrite(LED_VIBR, LOW); 
  }
}