#include <Adafruit_NeoPixel.h>
#define PIXEL_COUNT 7
#define PIXEL_PIN 2 //D2
#define TouchSensor 3 //D3
#define TouchSensor2 4 //D3
int Sred = 0;
int Sgreen = 0;
int Sblue = 0;
int buttonState = 0;
int buttonState2 = 0;
int state = 0;
float RELLenght_milliSeconds = 0;
float pressLenght_milliSeconds = 0;
float RELLenght_milliSeconds2 = 0;
float pressLenght_milliSeconds2 = 0;
int i = 0;
int ii = 0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
//change the value's below to choose your favorite color
int red = 0;
int green = 127;
int blue = 255;

void setup() {
  Sred = red;
  Sgreen = green;
  Sblue = blue;
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TouchSensor, INPUT_PULLUP);
  digitalWrite(LED_BUILTIN, LOW);
  strip.begin();
  strip.clear();
  strip.show();
  Serial.begin(9600);
  boot();
}

void pushLed() {
  strip.clear();
  if (pressLenght_milliSeconds >= 500 && pressLenght_milliSeconds <= 1500) { //boot
    strip.setPixelColor(1,red,green,blue);
  }
  if (pressLenght_milliSeconds >= 1600 && pressLenght_milliSeconds <= 2500) { //3 om 3
    strip.setPixelColor(1,red,green,blue);
    strip.setPixelColor(2,red,green,blue);
  }
  if (pressLenght_milliSeconds >= 2600 && pressLenght_milliSeconds <= 3500) { //fill 1 3 5 2 4 6
    strip.setPixelColor(1,red,green,blue);
    strip.setPixelColor(2,red,green,blue);
    strip.setPixelColor(3,red,green,blue);
  }
  if (pressLenght_milliSeconds >= 3600 && pressLenght_milliSeconds <= 4500) { //fill clear 1 3 5 2 4 6
    strip.setPixelColor(1,red,green,blue);
    strip.setPixelColor(2,red,green,blue);
    strip.setPixelColor(3,red,green,blue);
    strip.setPixelColor(4,red,green,blue);
  }
  if (pressLenght_milliSeconds >= 4600 && pressLenght_milliSeconds <= 5500) { //win10 load
    strip.setPixelColor(1,red,green,blue);
    strip.setPixelColor(2,red,green,blue);
    strip.setPixelColor(3,red,green,blue);
    strip.setPixelColor(4,red,green,blue);
    strip.setPixelColor(5,red,green,blue);
  }
  if (pressLenght_milliSeconds >= 5600 && pressLenght_milliSeconds <= 6500) { //dual load
    strip.setPixelColor(1,red,green,blue);
    strip.setPixelColor(2,red,green,blue);
    strip.setPixelColor(3,red,green,blue);
    strip.setPixelColor(4,red,green,blue);
    strip.setPixelColor(5,red,green,blue);
    strip.setPixelColor(6,red,green,blue);
  }
  strip.show();
}

void pushLed2() {
  strip.clear();
  if (pressLenght_milliSeconds2 >= 500 && pressLenght_milliSeconds2 <= 1500) { //boot
    strip.setPixelColor(1,red,green,blue);
  }
  if (pressLenght_milliSeconds2 >= 1600 && pressLenght_milliSeconds2 <= 2500) { //3 om 3
    strip.setPixelColor(1,red,green,blue);
    strip.setPixelColor(3,red,green,blue);
  }
  if (pressLenght_milliSeconds2 >= 2600 && pressLenght_milliSeconds2 <= 3500) { //fill 1 3 5 2 4 6
    strip.setPixelColor(1,red,green,blue);
    strip.setPixelColor(3,red,green,blue);
    strip.setPixelColor(5,red,green,blue);
  }
  if (pressLenght_milliSeconds2 >= 3600 && pressLenght_milliSeconds2 <= 4500) { //fill clear 1 3 5 2 4 6
    strip.setPixelColor(1,red,green,blue);
    strip.setPixelColor(3,red,green,blue);
    strip.setPixelColor(5,red,green,blue);
    strip.setPixelColor(2,red,green,blue);
  }
  if (pressLenght_milliSeconds2 >= 4600 && pressLenght_milliSeconds2 <= 5500) { //win10 load
    strip.setPixelColor(1,red,green,blue);
    strip.setPixelColor(3,red,green,blue);
    strip.setPixelColor(5,red,green,blue);
    strip.setPixelColor(2,red,green,blue);
    strip.setPixelColor(4,red,green,blue);
  }
  if (pressLenght_milliSeconds2 >= 5600 && pressLenght_milliSeconds2 <= 6500) { //dual load
    strip.setPixelColor(1,red,green,blue);
    strip.setPixelColor(3,red,green,blue);
    strip.setPixelColor(5,red,green,blue);
    strip.setPixelColor(2,red,green,blue);
    strip.setPixelColor(4,red,green,blue);
    strip.setPixelColor(6,red,green,blue);
  }
  strip.show();
}

void loop() {
  while (digitalRead(TouchSensor) == HIGH && digitalRead(TouchSensor2) == LOW) {
    if (RELLenght_milliSeconds >= 500) {
      setNeo();
    }
    RELLenght_milliSeconds = 0;
    pushLed();
    delay(100);
    pushLed();
    pressLenght_milliSeconds = pressLenght_milliSeconds + 100;
    //Serial.print("high ms = ");
    //Serial.println(pressLenght_milliSeconds);
  }
  //v2
  while (digitalRead(TouchSensor2) == HIGH && digitalRead(TouchSensor) == LOW) {
    if (RELLenght_milliSeconds2 >= 500) {
      setNeo2();
    }
    RELLenght_milliSeconds2 = 0;
    pushLed2();
    delay(100);
    pushLed2();
    pressLenght_milliSeconds2 = pressLenght_milliSeconds2 + 100;
    //Serial.print("high ms = ");
    //Serial.println(pressLenght_milliSeconds2);
  }
  while (digitalRead(TouchSensor) == LOW && digitalRead(TouchSensor2) == LOW) {
    delay(100);
    RELLenght_milliSeconds = RELLenght_milliSeconds + 100;
    RELLenght_milliSeconds2 = RELLenght_milliSeconds2 + 100;
    //Serial.print("low ms = ");
    //Serial.println(RELLenght_milliSeconds);
    //Serial.print("low ms = ");
    //Serial.println(RELLenght_milliSeconds2);
  }
}

void setNeo() {
  if (pressLenght_milliSeconds >= 500 && pressLenght_milliSeconds <= 1500) { //boot
    strip.clear();
    boot();
  }
  if (pressLenght_milliSeconds >= 1600 && pressLenght_milliSeconds <= 2500) { //3 om 3
    strip.clear();
    st1();
  }
  if (pressLenght_milliSeconds >= 2600 && pressLenght_milliSeconds <= 3500) { //fill 1 3 5 2 4 6
    strip.clear();
    st2();
  }
  if (pressLenght_milliSeconds >= 3600 && pressLenght_milliSeconds <= 4500) { //fill clear 1 3 5 2 4 6
    strip.clear();
    st3();
  }
  if (pressLenght_milliSeconds >= 4600 && pressLenght_milliSeconds <= 5500) { //win10 load
    strip.clear();
    st4();
  }
  if (pressLenght_milliSeconds >= 5600 && pressLenght_milliSeconds <= 6500) { //dual load
    strip.clear();
    st5();
  }
  strip.show();
  pressLenght_milliSeconds = 0;
}

void setNeo2() {
  if (pressLenght_milliSeconds2 >= 500 && pressLenght_milliSeconds2 <= 1500) { //boot
    strip.clear();
    allRand();
  }
  if (pressLenght_milliSeconds2 >= 1600 && pressLenght_milliSeconds2 <= 2500) { //3 om 3
    strip.clear();
    setRed();
  }
  if (pressLenght_milliSeconds2 >= 2600 && pressLenght_milliSeconds2 <= 3500) { //fill 1 3 5 2 4 6
    strip.clear();
    setGreen();
  }
  if (pressLenght_milliSeconds2 >= 3600 && pressLenght_milliSeconds2 <= 4500) { //fill clear 1 3 5 2 4 6
    strip.clear();
    setBlue();
  }
  if (pressLenght_milliSeconds2 >= 4600 && pressLenght_milliSeconds2 <= 5500) { //win10 load
    strip.clear();
    colorReset();
  }
  if (pressLenght_milliSeconds2 >= 5600 && pressLenght_milliSeconds2 <= 6500) { //dual load
    strip.clear();
    setWhite();
  }
  strip.show();
  pressLenght_milliSeconds2 = 0;
}

void st1() {
  while (i<8) {
    i+=1;
    strip.clear();
    delay(200);
    strip.setPixelColor(2,red,green,blue);
    strip.setPixelColor(4,red,green,blue);
    strip.setPixelColor(6,red,green,blue);
    strip.show();
    strip.clear();
    delay(200);
    strip.setPixelColor(1,red,green,blue);
    strip.setPixelColor(3,red,green,blue);
    strip.setPixelColor(5,red,green,blue);
    strip.show();
  }
  i = 0;
}

void st2() {
  while (i<4) {
    i+=1;
    strip.clear();
    delay(100);
    strip.setPixelColor(1,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(3,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(5,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(2,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(4,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(6,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(1,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(3,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(5,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(2,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(4,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(6,red,green,blue);
    strip.show();
    delay(100);
  }
  i = 0;
}

void st3() {
  while (i<4) {
    i+=1;
    strip.clear();
    delay(100);
    strip.setPixelColor(1,red,green,blue);
    strip.show();
    //
    strip.clear();
    delay(100);
    strip.setPixelColor(3,red,green,blue);
    strip.show();
    //
    strip.clear();
    delay(100);
    strip.setPixelColor(5,red,green,blue);
    strip.show();
    //
    strip.clear();
    delay(100);
    strip.setPixelColor(2,red,green,blue);
    strip.show();
    //
    strip.clear();
    delay(100);
    strip.setPixelColor(4,red,green,blue);
    strip.show();
    //
    strip.clear();
    delay(100);
    strip.setPixelColor(6,red,green,blue);
    strip.show();
    //
    strip.clear();
    delay(100);
    strip.setPixelColor(1,red,green,blue);
    strip.show();
    //
    strip.clear();
    delay(100);
    strip.setPixelColor(3,red,green,blue);
    strip.show();
    //
    strip.clear();
    delay(100);
    strip.setPixelColor(5,red,green,blue);
    strip.show();
    //
    strip.clear();
    delay(100);
    strip.setPixelColor(2,red,green,blue);
    strip.show();
    //
    strip.clear();
    delay(100);
    strip.setPixelColor(4,red,green,blue);
    strip.show();
    //
    strip.clear();
    delay(100);
    strip.setPixelColor(6,red,green,blue);
    strip.show();
    delay(100);
  }
  i = 0;
}

void st4() {
  while (i<4) {
    i+=1;
    strip.clear();
    delay(100);
    strip.setPixelColor(1,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(2,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(3,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(4,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(5,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(6,red,green,blue);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(1,0,0,0);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(2,0,0,0);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(3,0,0,0);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(4,0,0,0);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(5,0,0,0);
    strip.show();
    //
    //strip.clear();
    delay(100);
    strip.setPixelColor(6,0,0,0);
    strip.show();
    //
  }
  i = 0;
}

void st5() {
  while (i<8) {
    i+=1;
    strip.clear();
    strip.setPixelColor(1,red,green,blue);
    strip.setPixelColor(4,red,green,blue);
    strip.show();
    delay(200);
    strip.clear();
    strip.setPixelColor(2,red,green,blue);
    strip.setPixelColor(5,red,green,blue);
    strip.show();
    delay(200);
    strip.clear();
    strip.setPixelColor(3,red,green,blue);
    strip.setPixelColor(6,red,green,blue);
    strip.show();
    delay(200);
  }
  i = 0;
}

//v2
void allRand() {
  while (i < 256) {
  i+=1;
    ii = random(0,7);
    delay(25);
    strip.setPixelColor(ii,red,green,blue);
    strip.show();
    ii = random(0,7);
    delay(25);
    strip.setPixelColor(ii,0,0,0);
    strip.show();
  }
  delay(100);
  strip.clear();
  strip.show();
}

void setRed() {
  red=255;
  green=0;
  blue=0;
}

void setGreen() {
  red=0;
  green=255;
  blue=0;
}

void setBlue() {
  red=0;
  green=0;
  blue=255;
}

void colorReset() {
  red=Sred;
  green=Sgreen;
  blue=Sblue;
}

void setWhite() {
  red=255;
  green=255;
  blue=255;
}

//boot
void boot() {
  RELLenght_milliSeconds = 0;
  pressLenght_milliSeconds = 0;
  state = 0;
  buttonState = 0;
  i = 0;
  delay(100);
  strip.clear();
  strip.show();
  delay(100);
  strip.setPixelColor(1,red,green,blue);
  strip.show();
  delay(100);
  strip.setPixelColor(1,0,0,0);
  strip.setPixelColor(2,red,green,blue);
  strip.show();
  delay(100);
  strip.setPixelColor(1,red,green,blue);
  strip.setPixelColor(2,0,0,0);
  strip.setPixelColor(3,red,green,blue);
  strip.show();
  delay(100);
  strip.setPixelColor(2,red,green,blue);
  strip.setPixelColor(3,0,0,0);
  strip.setPixelColor(4,red,green,blue);
  strip.show();
  delay(100);
  strip.setPixelColor(3,red,green,blue);
  strip.setPixelColor(4,0,0,0);
  strip.setPixelColor(5,red,green,blue);
  strip.show();
  delay(100);
  strip.setPixelColor(4,red,green,blue);
  strip.setPixelColor(5,0,0,0);
  strip.setPixelColor(6,red,green,blue);
  strip.show();
  delay(100);
  strip.setPixelColor(5,red,green,blue);
  strip.setPixelColor(6,0,0,0);
  strip.show();
  delay(100);
  strip.setPixelColor(6,red,green,blue);
  strip.show();
  delay(600);
  strip.clear();
  strip.setPixelColor(1,255,0,0);
  strip.setPixelColor(2,255,0,0);
  strip.setPixelColor(3,255,0,0);
  strip.setPixelColor(4,255,0,0);
  strip.setPixelColor(5,255,0,0);
  strip.setPixelColor(6,255,0,0);
  strip.show();
  delay(100);
  strip.clear();
  strip.setPixelColor(1,0,255,0);
  strip.setPixelColor(2,0,255,0);
  strip.setPixelColor(3,0,255,0);
  strip.setPixelColor(4,0,255,0);
  strip.setPixelColor(5,0,255,0);
  strip.setPixelColor(6,0,255,0);
  strip.show();
  delay(100);
  strip.clear();
  strip.setPixelColor(1,0,0,255);
  strip.setPixelColor(2,0,0,255);
  strip.setPixelColor(3,0,0,255);
  strip.setPixelColor(4,0,0,255);
  strip.setPixelColor(5,0,0,255);
  strip.setPixelColor(6,0,0,255);
  strip.show();
  delay(100);
  strip.clear();
  strip.setPixelColor(1,255,255,255);
  strip.setPixelColor(2,255,255,255);
  strip.setPixelColor(3,255,255,255);
  strip.setPixelColor(4,255,255,255);
  strip.setPixelColor(5,255,255,255);
  strip.setPixelColor(6,255,255,255);
  strip.show();
  while (i<4) {
    i+=1;
    delay(100);
    strip.clear();
    strip.show();
    delay(100);
    strip.clear();
    strip.setPixelColor(1,red,green,blue);
    strip.setPixelColor(2,red,green,blue);
    strip.setPixelColor(3,red,green,blue);
    strip.setPixelColor(4,red,green,blue);
    strip.setPixelColor(5,red,green,blue);
    strip.setPixelColor(6,red,green,blue);
    strip.show();
  }
  i=0;
}
