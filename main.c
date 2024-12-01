#include <SoftwareSerial.h>
#include <Servo.h>

// HC-05 Bluetooth Module Pins
SoftwareSerial BTSerial(10, 11);  //TX, RX
String readvoice;

Servo servo;  // Create a Servo object
int ledWhite = 2;
int ledBlue = 3;
int motorPin = 6;


char toLowerCase(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + ('a' - 'A');
  }
  return c;
}


void setup() {
  // Initialize serial communication
  Serial.begin(9600);    // For Serial Monitor
  BTSerial.begin(9600);  // For HC-05

  // Initialize LEDs
  pinMode(ledWhite, OUTPUT);
  pinMode(ledBlue, OUTPUT);

  // Initialize motor
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);

  // Initialize Servo
  servo.attach(9);  // Attach servo to pin D9
  servo.write(0);   // Set initial position to "closed" (adjust based on setup)

  Serial.println("Voice-controlled system ready.");
}

void loop() {
  	while (BTSerial.available()){
    Serial.println("WOW");
  	delay(10);
  	char c = BTSerial.read();
  	readvoice += toLowerCase(c);
  	}

  if (readvoice.length() > 0) {
      Serial.println(readvoice);

  if(readvoice == "living room on")
      {
      digitalWrite(ledWhite, HIGH);
      delay(100);
      }
  else if(readvoice == "living room off")
      {
      digitalWrite(ledWhite, LOW);
      delay(100);
      }
  else if(readvoice == "kitchen on")
      {
      digitalWrite(ledBlue, HIGH);
      delay(100);
      }
  else if(readvoice == "kitchen off")
      {
      digitalWrite(ledBlue, LOW);
      delay(100);
      }
  else if(readvoice == "all lights on")
      {
      digitalWrite(ledWhite, HIGH);
      digitalWrite(ledBlue, HIGH);
      delay(100);
      }
  else if(readvoice == "all lights off")
      {
      digitalWrite(ledWhite, LOW);
      digitalWrite(ledBlue, LOW);
      delay(100);
      }
  else if(readvoice == "open garage")
      {
        servo.write(90);
        delay(100);
      }
  else if(readvoice == "close garage")
      {
        servo.write(0);
        delay(100);
      }
  readvoice="";
    }}