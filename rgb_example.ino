/*
  RGBLedExample
  Example for the RGBLED Library
  Created by Bret Stateham, November 13, 2014
  You can get the latest version from http://github.com/BretStateham/RGBLED
*/
#include <TimeLib.h>
#include <RGBLED.h>
#include "color_per_hr.h"

void digitalClockDisplay();
void printDigits(int digits);

// Declare an RGBLED instanced named rgbLed
// Red, Green and Blue LED legs are connected to PWM pins 11,9 & 6 respectively
// In this example, we have a COMMON_ANODE LED, use COMMON_CATHODE otherwise
RGBLED rgbLed(8,9,10,COMMON_ANODE); // Shared VDD

void setup() {
  //Initialize Serial communications
  Serial.begin(115200);
  Serial.println("RGB clock started"); 
   // Set Predefined time
   //setTime(hours, minutes, seconds, days, months, years);
   setTime(19, 0, 0, 1, 1, 2018);
}

char c = 0;
void loop() {

  //Set the RGBLED to show GREEN only
//  rgbLed.writeRGB(0,255,0);
//  printRgbValues();
//  delay(delayMs);
   if (Serial.available() > 0) {
      c = Serial.read();
      if( c == 'u'){
         adjustTime(60*60); // Add 1/2 HR to clock
   }   
}

digitalClockDisplay();
rgbLed.writeRGB(hr_to_rgb[hour()].Red, hr_to_rgb[hour()].Green, hr_to_rgb[hour()].Blue);
delay(1000);

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
   Serial.print(hr_to_rgb[hour()].Red);
   Serial.print(", Green ");
   Serial.print(hr_to_rgb[hour()].Green);
   Serial.print(", Blue ");
   Serial.println(hr_to_rgb[hour()].Blue);
}

void printDigits(int digits) {
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

