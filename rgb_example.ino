/*
  RGBLedExample
  Example for the RGBLED Library
  Created by Bret Stateham, November 13, 2014
  You can get the latest version from http://github.com/BretStateham/RGBLED
*/
#include <TimeLib.h>
#include <RGBLED.h>
#include "color_per_hr.h"
//#define ARD_DEBUG

void setRGB();
void ard_debug();
void digitalClockDisplay();
void printDigits(int digits);

// Declare an RGBLED instanced named rgbLed
// Red, Green and Blue LED legs are connected to PWM pins 11,9 & 6 respectively
// In this example, we have a COMMON_ANODE LED, use COMMON_CATHODE otherwise
RGBLED rgbLed(10,9,6,COMMON_ANODE); // Shared VDD
int r,g,b;

void setup() {
   // Set Predefined time
   //setTime(hours, minutes, seconds, days, months, years);
   setTime(19, 0, 0, 1, 1, 2018);

#ifdef ARD_DEBUG
  //Initialize Serial communications
  Serial.begin(115200);
  Serial.println("RGB clock started"); 
#endif
}



char c = 0;
void loop() {
if (minute() == 0 && second() == 0) {
   setRGB();
}

#ifdef ARD_DEBUG
ard_debug();
digitalClockDisplay();
rgbLed.writeRGB(r, g, b);
delay(100);
#else
delay(1000);
#endif

}

void setRGB(){
   r=hr_to_rgb[hour()].Red;
   g=hr_to_rgb[hour()].Green;
   b=hr_to_rgb[hour()].Blue;
   rgbLed.writeRGB(r, g, b);
}

void ard_debug() {
   if (Serial.available() > 0) {
      c = Serial.read();

      switch(c) {
         case 'u':
            adjustTime(-60*60); // Add 1/2 HR to clock
            setRGB();
            break;
         case 'U':
            adjustTime(60*60); // Add 1/2 HR to clock
            setRGB();
            break;
         case 'r':
            if (r > 0) r--;
            break;
         case 'R':
            if (r < 255) r++;
            break;
         case 'g':
            if (g > 0) g--;
            break;
         case 'G':
            if (g < 255) g++;
            break;
         case 'b':
            if (b > 0) b--;
            break;
         case 'B':
            if (b < 255) b++;
            break;
      }   
   }
}

void digitalClockDisplay() {
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
//    Serial.print(dayStr(weekday()));
//   Serial.print(dayShortStr(weekday()));
//  Serial.print(" ");
//  Serial.print(day());
//  Serial.print(" ");
//     Serial.print(monthStr(month()));
//     Serial.print(monthShortStr(month()));
//  Serial.print(" ");
//  Serial.print(year()); 
//  Serial.println(); 
   Serial.print("RGB Color: Red ");
   Serial.print(r);
   Serial.print(", Green ");
   Serial.print(g);
   Serial.print(", Blue ");
   Serial.println(b);
}

void printDigits(int digits) {
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

