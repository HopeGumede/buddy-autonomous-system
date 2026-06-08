#include <LiquidCrystal.h>

// LCD Pin Mapping: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Sensor Pins
const int trigPin = 9;
const int echoPin = 8;

// LED Indicators (Corrected to your 13, 12, 11 setup)
const int redLED = 13;
const int yellowLED = 12;
const int greenLED = 11;

// Buzzer and Motor
const int buzzer = 10;
const int motorPin = A1; 
const int potPin = A0;

long duration;
int distance;
int threshold;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
  pinMode(buzzer, OUTPUT);
  pinMode(motorPin, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Robot System");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // 1. Read threshold from potentiometer
  threshold = analogRead(potPin);
  threshold = map(threshold, 0, 1023, 20, 100);

  // 2. Pulse the Ultrasonic Sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // 3. Update Display
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print("cm   "); // Spaces clear ghost digits
  
  lcd.setCursor(0, 1);
  lcd.print("Limit: ");
  lcd.print(threshold);
  lcd.print("cm ");

  // 4. Logic Control
  if (distance > threshold) {
    // SAFE
    digitalWrite(motorPin, HIGH); 
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
  } 
  else if (distance > threshold / 2) {
    // CAUTION
    digitalWrite(motorPin, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    
    // Pulse buzzer for warning
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
  } 
  else {
    // DANGER - EMERGENCY STOP
    digitalWrite(motorPin, LOW); 
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH); 
  }

  delay(1000); // Stability delay
}