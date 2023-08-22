// Include the DHT sensor library
#include <dht.h>

// Create an instance of the DHT sensor
dht DHT;

// Define the pin connected to the DHT11 sensor
const int DHT11_signal_pin = 2;

// Define the pins connected to the front ultrasonic sensor
const int ultraSonic_front_trig_pin = 3;
const int ultraSonic_front_echo_pin = 4;

// Define the pins connected to the left ultrasonic sensor
const int ultraSonic_left_trig_pin = 5;
const int ultraSonic_left_echo_pin = 6;

// Define the pins connected to the right and left light detectors
const int lightDetector_right_signal_pin = A0;
const int lightDetector_left_signal_pin = A3;

// Define the pin connected to the buzzer
const int buzzer_pin = 7;

// Define the pin connected to the fan
const int fan = 11;

// Define the pin connected to the LED
const int LED = 12;

// Function to read data from the DHT sensor
int* DHT_function(const int DHT_pin) {
  // Static array to hold humidity and temperature values
  static int DHT_sensor_outputput[2];

  // Read humidity and temperature from the DHT sensor
  DHT_sensor_outputput[0] = DHT.humidity;
  DHT_sensor_outputput[1] = DHT.temperature;

  // Return the array
  return DHT_sensor_outputput;
}

// Function to read data from the ultrasonic sensor
float ultra_sonic_function(int trigPin, int echoPin) {
  // Variables to hold duration and distance values
  static float duration, distance;

  // Send a short pulse to trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the time for the echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distance = (duration * .0343) / 2;

  // Return the distance
  return distance;
}

// Function to read data from the light detector
int LDR_function(int LDR_pin) { return analogRead(LDR_pin); }

// Setup function
void setup() {
  // Set the pin modes for the ultrasonic sensors, buzzer, fan, and LED
  pinMode(ultraSonic_front_trig_pin, OUTPUT);
  pinMode(ultraSonic_front_echo_pin, INPUT);
  pinMode(ultraSonic_left_trig_pin, OUTPUT);
  pinMode(ultraSonic_left_echo_pin, INPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(LED, OUTPUT);

  // Start the serial communication
  Serial.begin(9600);
}

// Main loop function
void loop() {
  // Variables to hold sensor outputs
  float front_ultrasonic_output = 0;
  float left_ultrasonic_output = 0;
  int* DHT_sensor_output;

  // Read data from the DHT sensor
  DHT_sensor_output = DHT_function(DHT11_signal_pin);

  // If the temperature is greater than 10, turn on the fan
  if (DHT_sensor_output[1] > 10) {
    digitalWrite(fan, HIGH);
  }

  // Read data from the front and left ultrasonic sensors
  front_ultrasonic_output = ultra_sonic_function(ultraSonic_front_trig_pin,
                                                 ultraSonic_front_echo_pin);
  left_ultrasonic_output =
      ultra_sonic_function(ultraSonic_left_trig_pin, ultraSonic_left_echo_pin);

  // If any of the ultrasonic sensors detect an object closer than 15 units,
  // turn on the buzzer
  if (front_ultrasonic_output <= 15 || left_ultrasonic_output <= 15) {
    digitalWrite(buzzer_pin, HIGH);
  } else {
    digitalWrite(buzzer_pin, LOW);
  }

  // Read data from the right and left light detectors
  int right_LDR_output = LDR_function(lightDetector_right_signal_pin);
  int left_LDR_output = LDR_function(lightDetector_left_signal_pin);

  // If any of the light detectors detect a light intensity greater than 150,
  // turn on the LED
  if (right_LDR_output > 150 || left_LDR_output > 150) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  // Print the sensor data to the serial monitor
  Serial.print("First Light Detector Sensor: ");
  Serial.println(right_LDR_output);
  Serial.println("************");
  Serial.print("Second Light Detector Sensor: ");
  Serial.println(left_LDR_output);
  Serial.println("_____________________________");
  Serial.print("First UltraSonic Sensor Distance: ");
  Serial.println(front_ultrasonic_output);
  Serial.println("************");
  Serial.print("Second UltraSonic Sensor Distance: ");
  Serial.println(left_ultrasonic_output);
  Serial.println("_____________________________");
  Serial.print("DHT Sensor Temperature: ");
  Serial.println(DHT_sensor_output[1]);
  Serial.println("************");
  Serial.print("DHT Sensor Humidity: ");
  Serial.println(DHT_sensor_output[0]);
  Serial.println("_____________________________");

  // Delay for a short period before the next loop
  delay(50);
}
