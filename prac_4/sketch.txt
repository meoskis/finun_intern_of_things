#include <Arduino.h>

// Параметры датчиков
int read_temp_pin = 4;    // Пин для датчика температуры
int humid_read_pin = 11;  // Пин для датчика влажности

// Переменные для хранения показаний датчиков
float temp = 0;  // Температура
float humid = 0; // Влажность

void setup() {
  // Настройка серийного порта для вывода результатов
  Serial.begin(9600);
}

void loop() {
  // Задержка
  delay(1500);

  // Считывание показаний с датчиков (от 0 до 1023)
  int read_temp = analogRead(read_temp_pin);
  // Преобразование значения в температуру
  temp = map(read_temp, 0, 1023, -50, 50);
  // Считывание показаний с датчиков (от 0 до 1023)
  int humid_read = analogRead(humid_read_pin);
  // Преобразование значения во влажность
  humid = map(humid_read, 0, 1023, 0, 100);

  // Вывод
  Serial.print("Температура: ");
  Serial.print(temp);
  Serial.print("°C, Влажность: ");
  Serial.print(humid);
  Serial.println(" %");
}

