#include <Arduino.h>
#define LED_PIN 39

bool light_on = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if(digitalRead(18) == HIGH)
  {
    light_on = true;
  }

  if(light_on == true)
  {
    light_on = false;
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
  }
  else{
    digitalWrite(LED_PIN, LOW);
  }
}
