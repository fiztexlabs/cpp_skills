#include <Arduino.h>
#include <string>
#include <vector>

#define LED_PIN 39

// мощность свечения
int power = 4096;

// буффер для приема сообщений
std::string message = "";

bool light_on = false;

// количество сохраняемых команд
const int last_commands_num = 4;

// массив, в котором сохраняются значения мощности, полученные через серийный порт
std::vector<int> commands(last_commands_num);

int k = 0;

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

    // сохраняем значения мощности в массив commands
    if (k < last_commands_num)
    {
      commands.at(k) = power;
      ++k;
    }
    else
    {
      for (int i = 1; i < last_commands_num; ++i)
      {
        commands.at(i - 1) = commands.at(i);
      }
      commands.at(last_commands_num - 1) = power;
    }

    for (int i = 0; i < last_commands_num; ++i)
    {
      Serial.println(commands.at(i));
    }

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
