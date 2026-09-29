#include <Arduino.h>
#define BUTTON_PIN 4

volatile bool interruptFlag = false;
volatile unsigned long counter = 0;

void IRAM_ATTR handleInterrupt() {
  interruptFlag = true;
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleInterrupt, FALLING);
  Serial.println("Ready. Press the button.");
}

void loop() {
  if (interruptFlag) {
    interruptFlag = false;
    if (digitalRead(BUTTON_PIN) == LOW) {
      counter++;
      Serial.print("Interrupt count: ");
    Serial.println(counter);
    } else {
      Serial.println("Button released.");
    }
    
    
  }
}
