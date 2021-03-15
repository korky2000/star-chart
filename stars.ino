#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(24, 0);
int i;
int n=0;
int i2;
int n2=0;
int i3;
int n3=0;
int bright=0;

int state = 0;
long startTime = millis();
long startTime2 = millis();
long startTime3 = millis();
long interval= 5000;
long interval2 = 5000;
long interval3 = 5000;
long endTime3;
long endTime;
boolean isIncreasing = true;
long endTime2;

void setup() {
//strip.setBrightness(50);
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  strip.show();
}

void loop() {
Serial.println(state);
  
switch (state)
{
  case 0:
  

          endTime = millis();

for(int i=0; i< strip.numPixels(); i++){
  int x = i+n;
  if (x % 3 == 0){
    strip.setPixelColor(i,255,255,255);
      Serial.println("1");

  }
  if(x % 3 == 1){
    strip.setPixelColor(i,185,185,0);
      Serial.println("1");

  }
  if (x % 3 == 2){
    strip.setPixelColor(i,255,255,255);
      Serial.println("1");

  
  }
  }

    if(endTime - startTime >= interval){
      strip.clear();
              startTime2=millis();

      state = 1;

      Serial.println("switched");

    }

strip.show();
n=n+1;
break;
case 1:

          endTime2 = millis();
  for(int i=0; i<=40; i++) { 
    strip.setPixelColor(i, 255,255,255);        
    strip.show();                          
    delay(50);
  }

  
    if(endTime2 - startTime2 >= interval2){
         startTime3=millis();
      state = 2;
    Serial.println("switched again");

    }

strip.show();
n2=n2+1;
break;

case 2:
  endTime3 = millis();
      if (endTime3 - startTime3 >= interval) {

        for (int i = 0; i < strip.numPixels(); i++) {
          int x3 = i3 + n3;
          if (x3 % 3 == 0) {
            strip.setPixelColor(i3, 255, 105, 180);
          }
          else if (x3 % 3 == 1) {
            strip.setPixelColor(i, 128, 0, 128);
          }
          else if (x3 % 3 == 2) {
            strip.setPixelColor(i, 255, 0, 0);
          }
          startTime = millis();
        }



        strip.show();
        n3 = n3 + 1;
      }
      if (n3 == 40)

      {
        n3 = 0;
      }

break;
      
}
}
