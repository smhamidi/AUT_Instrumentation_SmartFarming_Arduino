#include <dht.h>

dht DHT;


const int DHT11_signal = 2;

const int sr04_1_trig = 3;
const int sr04_1_echo = 4;

const int sr04_2_trig = 5;
const int sr04_2_echo = 6;

const int LDR_1 = A0;
const int LDR_2 = A3;

const int Buzzer = 7;
const int Fan = 11;
const int LED = 12;


int* DHT_Function ( const int DHT_pin )
{
  static int DHT_output[2];
  
  int chk = DHT.read11(DHT_pin);
  DHT_output[0] = DHT.humidity;
  DHT_output[1] = DHT.temperature;
  return DHT_output;
 
}

float sr04_Function(int trigPin, int echoPin){
  static float duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  return distance;
}

int LDR_Function(int LDR_pin)
{
  return analogRead(LDR_pin);
}

void setup(){

  pinMode(sr04_1_trig,OUTPUT);
  pinMode(sr04_1_echo,INPUT);
  pinMode(sr04_2_trig,OUTPUT);
  pinMode(sr04_2_echo,INPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(Fan,OUTPUT);
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop(){

  float sonic1_out = 0;
  float sonic2_out = 0;
  int* dht_out;

  dht_out = DHT_Function(DHT11_signal);
   if(dht_out[1] > 10)
   {
     digitalWrite(Fan, HIGH);
   }

  sonic1_out = sr04_Function(sr04_1_trig,sr04_1_echo);
  sonic2_out = sr04_Function(sr04_2_trig,sr04_2_echo);
  if(sonic1_out <= 15 || sonic2_out <= 15)
  {
    digitalWrite(Buzzer, HIGH);
  }
  else
  {
    digitalWrite(Buzzer, LOW);
  }

  int First_LDR = LDR_Function(LDR_1);
  int Second_LDR = LDR_Function(LDR_2);

  if(First_LDR > 150 || Second_LDR > 150){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
  
  Serial.print("First Light Detector Sensor: ");
  Serial.println(First_LDR);
  Serial.println("************");
  Serial.print("Second Light Detector Sensor: ");
  Serial.println(Second_LDR);
  Serial.println("_____________________________");
  Serial.print("First UltraSonic Sensor Distance: ");
  Serial.println(sonic1_out);
  Serial.println("************");
  Serial.print("Second UltraSonic Sensor Distance: ");
  Serial.println(sonic2_out);
  Serial.println("_____________________________");
  Serial.print("DHT Sensor Temperature: ");
  Serial.println(dht_out[1]);
  Serial.println("************");
  Serial.print("DHT Sensor Humidity: ");
  Serial.println(dht_out[0]);
  Serial.println("_____________________________");
  Serial.print(output);
  
  delay(100);
}
