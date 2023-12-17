#include <Thread.h>

const int red1 = 11;
const int yellow1 = 12;
const int green1 = 13;

int tl1 = true;
const int red2 = 3;
const int yellow2 = 4;
const int green2 = 5;
int tl2 = true;
Thread lightThread1 = Thread();
Thread lightThread2 = Thread();

void setup() {
    pinMode(red1, OUTPUT); 
    pinMode(yellow1, OUTPUT); 
    pinMode(green1, OUTPUT); 
    digitalWrite(yellow1, HIGH);
    lightThread1.onRun(light1); 
    lightThread1.setInterval(1000);
    pinMode(red2, OUTPUT); 
    pinMode(yellow2, OUTPUT); 
    pinMode(green2, OUTPUT); 
    digitalWrite(yellow2, HIGH);
    lightThread2.onRun(light2); 
    lightThread2.setInterval(3000); 
}

void loop() {
    if (lightThread1.shouldRun())
        lightThread1.run();
    if (lightThread2.shouldRun())
        lightThread2.run();
}

void light1() { 
  if (digitalRead(red1) + digitalRead(green1) > 0){
    digitalWrite(red1, LOW);
    digitalWrite(yellow1, HIGH);
    digitalWrite(green1, LOW);
  }
  else {
    if (tl1 == true){
      digitalWrite(red1, LOW);
      digitalWrite(yellow1, LOW);
      digitalWrite(green1, HIGH);
      tl1 *= false;
    }
    else {
      tl1 *= false;
      digitalWrite(red1, HIGH);
      digitalWrite(yellow1, LOW);
      digitalWrite(green1, LOW);
    }
  }
}
void light2() { 
  if (digitalRead(red2) + digitalRead(green2) > 0){
    digitalWrite(red2, LOW);
    digitalWrite(yellow2, HIGH);
    digitalWrite(green2, LOW);
  }
  else {
    if (tl2 == true){
      digitalWrite(red2, LOW);
      digitalWrite(yellow2, LOW);
      digitalWrite(green2, HIGH);
      tl2 *= false;
    }
    else {
      tl2 *= false;
      digitalWrite(red2, HIGH);
      digitalWrite(yellow2, LOW);
      digitalWrite(green2, LOW);
    }
  }
  
}
