#include <Servo.h>
#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h>

// Pin setup
const int trigPin = 9;
const int echoPin = 10;
const int greenLED = 3;
const int yellowLED = 4;
const int redLED = 5;
const int buzzer = 6;
const int shutterPin = 7;
const int rxPin = 0;  // RX pin for MP3 module
const int txPin = 1;  // TX pin for MP3 module

Servo shutterMotor;
bool shutterRaised = false; // Variable to track if the shutter has been raised

SoftwareSerial mySoftwareSerial(rxPin, txPin); // RX, TX
DFPlayerMini_Fast myMP3; // Create DFPlayerMini object

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  shutterMotor.attach(shutterPin);
  Serial.begin(9600);

  mySoftwareSerial.begin(9600); // Initialize software serial for MP3 module
  if (!myMP3.begin(mySoftwareSerial)) {
    Serial.println("MP3 module initialization failed!");
    while (true); // Stop execution if initialization fails
  }
  Serial.println("MP3 module initialized.");

  myMP3.volume(20); // Set volume level (0-30)
}

void loop() {
  long duration;
  int distance;

  // Send ultrasonic signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Receive ultrasonic signal
  duration = pulseIn(echoPin, HIGH);

  // Convert distance to cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Actions based on distance
  if (distance > 10) { // Green light stage
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    noTone(buzzer);
    shutterMotor.write(0); // Move shutter to initial position (closed)
    shutterRaised = false; // Reset the shutter status
    myMP3.stop(); // Stop any playing audio
  }
  else if (distance > 5) { // Yellow light + warning message stage
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    noTone(buzzer);
    shutterMotor.write(0); // Keep shutter in closed position
    shutterRaised = false; // Reset the shutter status
    Serial.println("Warning: Flood risk detected. Please prepare.");

    // Play the audio message (Assuming the file is the first track on the SD card)
    myMP3.play(1); // Play the first audio file on the SD card
  }
  else { // Red light + alarm + shutter operation stage
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    tone(buzzer, 1000); // Play alarm sound

    if (!shutterRaised) { // Check if the shutter has already been raised
      shutterMotor.write(90); // Raise the shutter (90 degrees is the open angle)
      shutterRaised = true; // Mark the shutter as raised
      Serial.println("Alert: Flood imminent. Shutter is being raised.");
    }

    myMP3.stop(); // Stop any playing audio
  }

  delay(1000); // Measure every second
}
