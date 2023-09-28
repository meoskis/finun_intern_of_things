// Подключаем библиотеку Arduino
#include <Arduino.h>

// Параметры для управления реле этажей
const int firstFloorRelayPin = 2;  // Пин, подключенный к реле для первого этажа
const int secondFloorRelayPin = 3; // Пин, подключенный к реле для второго этажа
const int thirdFloorRelayPin = 4;  // Пин, подключенный к реле для третьего этажа

// Пин мастер-выключателя
const int masterSwitchPin = 5; // Пин, подключенный к мастер-выключателю

// Пины светодиодов для индикации состояния света на каждом этаже
const int firstFloorLedPin = 9;  // Пин светодиода для первого этажа
const int secondFloorLedPin = 10; // Пин светодиода для второго этажа
const int thirdFloorLedPin = 11;  // Пин светодиода для третьего этажа

void setup() {
  pinMode(firstFloorRelayPin, OUTPUT);  // Устанавливаем пины реле как выходы
  pinMode(secondFloorRelayPin, OUTPUT);
  pinMode(thirdFloorRelayPin, OUTPUT);
  pinMode(masterSwitchPin, INPUT_PULLUP); // Устанавливаем мастер-выключатель как вход с подтяжкой к HIGH
  
  // Устанавливаем пины светодиодов как выходы
  pinMode(firstFloorLedPin, OUTPUT);
  pinMode(secondFloorLedPin, OUTPUT);
  pinMode(thirdFloorLedPin, OUTPUT);
}

void loop() {
  // Читаем состояние мастер-выключателя
  int masterSwitchState = digitalRead(masterSwitchPin);

  // Включаем или выключаем свет во всем подъезде и управляем светодиодами
  if (masterSwitchState == LOW) {
    digitalWrite(firstFloorRelayPin, HIGH);   // Включаем свет на первом этаже
    digitalWrite(secondFloorRelayPin, HIGH);  // Включаем свет на втором этаже
    digitalWrite(thirdFloorRelayPin, HIGH);   // Включаем свет на третьем этаже
    
    // Включаем светодиоды для индикации состояния света
    digitalWrite(firstFloorLedPin, HIGH);
    digitalWrite(secondFloorLedPin, HIGH);
    digitalWrite(thirdFloorLedPin, HIGH);
  } else {
    digitalWrite(firstFloorRelayPin, LOW);    // Выключаем свет на первом этаже
    digitalWrite(secondFloorRelayPin, LOW);   // Выключаем свет на втором этаже
    digitalWrite(thirdFloorRelayPin, LOW);    // Выключаем свет на третьем этаже
    
    // Выключаем светодиоды для индикации состояния света
    digitalWrite(firstFloorLedPin, LOW);
    digitalWrite(secondFloorLedPin, LOW);
    digitalWrite(thirdFloorLedPin, LOW);
  }
}