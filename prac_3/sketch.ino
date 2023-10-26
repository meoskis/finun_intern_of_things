#include <LiquidCrystal_I2C.h>  // Библиотека для работы с дисплеем
#include <Wire.h>               // Библиотека для работы с шиной с шиной I2C

// Настройка дисплея
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Значения для переменной X
int x[20] = {0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 6.5, 7.0, 7.5, 8.0, 8.5, 9.0, 9.5, 10.0};
// Значения для переменной Y
int y[20] = {1.2, 2.0, 2.8, 3.5, 4.3, 5.0, 5.8, 6.5, 7.3, 8.0, 8.7, 9.5, 10.2, 11.0, 11.8, 12.5, 13.3, 14.0, 14.8, 15.5};
// Количество исследуемых точек
int n = 20;

void setup() {
  // Инициализация дисплея
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  lcd.home();
  lcd.print("Regression model");
  lcd.setCursor(0, 1);
  lcd.print("by Nikita Kudryashov");
}

void loop() {
  // Расчет коэффициентов регрессии
  int sumX = 0;
  int sumY = 0;
  int sumXY = 0;
  int sumX2 = 0;
  for (int i = 0; i < n; i++) {
    sumX += x[i];
    sumY += y[i];
    sumXY += x[i] * y[i];
    sumX2 += x[i] * x[i];
  }
  
  // Расчет регрессионых коэфициентов
  float b0 = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
  float b1 = (sumY - b0 * sumX) / n;

  // Вывод коэффициентов на дисплей
  lcd.setCursor(0, 2);
  lcd.print("f(x)=");
  lcd.print(b0);
  lcd.print("+");
  lcd.print(b1);
  lcd.print("x");


  while (1) {
    // Программа завершена
  }
}