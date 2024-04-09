#include <Arduino.h>
#include <string>

#define LED_PIN 39

// мощность свечения
int power = 255;

// буффер для приема сообщений
std::string message = "";

bool light_on = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
}

void loop() {

  // читаем данные из серийного порта
  if (Serial.available() > 0) 
  {
    message = "";

    while(Serial.available() > 0)
    {
      message += std::string(1, char(Serial.read()));
      delay(500);
    }
    
    power = std::stoi(message);

    Serial.print("Recieved: power = ");
    Serial.println(power);
  }


  if(digitalRead(18) == HIGH)
  {
    light_on = true;
  }

  if(light_on == true)
  {
    light_on = false;
    analogWrite(LED_PIN, power);
    delay(1000);
  }
  else{
    analogWrite(LED_PIN, 0);
  }
}
