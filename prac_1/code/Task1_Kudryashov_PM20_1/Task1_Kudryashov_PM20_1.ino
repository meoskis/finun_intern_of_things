// Подключаем библиотеку Arduino
#include <Arduino.h>
// Параметры для мигания светодиода
const int ledPin = 12; // Пин, к которому подключен светодиод
const int N = 4;       // Количество миганий
const unsigned long S = 500; // Длительность мигания в миллисекундах
const unsigned long P = 100; // Пауза между миганиями в миллисекундах
void setup() {
  pinMode(ledPin, OUTPUT); // Устанавливаем пин светодиода как выход
}
void loop() {
  // Выполняем N-кратное мигание светодиода
  for (int i = 0; i < N; i++) {
    digitalWrite(ledPin, HIGH); // Включаем светодиод
    delay(S);                   // Ждем S миллисекунд
    digitalWrite(ledPin, LOW);  // Выключаем светодиод
    delay(P);                   // Пауза между миганиями
  }
  delay(1000);
}
