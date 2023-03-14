

//2023 Project1
//coded by Luca Kauther-Kearney

#include <Wire.h>
#include "rgb_lcd.h"
#include<iostream>

rgb_lcd lcd;
const int R = 0;
const int G = 0;
const int B = 0;

int sound_sensor = A2; //assign to pin A2
 
void setup() 
{
  Serial.begin(9600); //begin Serial Communication
  lcd.setRGB( 10, 0, 0 );
  lcd.print("hello, world!");
  //2 second delay
  delay(2000)
// num multiplier for seconds of delay
  int n = 120
  
}
 
void loop()
{
  delay(n * 1000)

  sound_lv = listen();
  if (sound_lv <= 150)
  {
    lcd.setRGB( 0, 100, 0 );
    lcd.print("Current noise lv: quiet");
  }
  else if (sound_lv > 150 && sound_lv <= 250)
  {
    lcd.setRGB( 100, 100, 0 );
    lcd.print("Current noise lv: quiet");
  }

}

int listen()
{

  int soundValue = 0; //create variable to store many different readings
  for (int i = 0; i < 32; i++) //create a for loop to read 
  { soundValue += analogRead(sound_sensor);  } //read the sound sensor
 
  soundValue >>= 5; //bitshift operation 
  //Serial.println(soundValue); //print the value of sound sensor


}









