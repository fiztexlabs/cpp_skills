#include <Arduino.h>

#define LED_PIN 39
#define PUSH_COUNT 3

bool light_on = false;

int count = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if(digitalRead(18) == HIGH)
  {
    if(count == PUSH_COUNT - 1)
    {
      light_on = true;
      count = 0;
    }
    else
    {
      ++count;
      delay(500);
    }
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
