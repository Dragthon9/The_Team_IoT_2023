

//2023 Project1

#include <Wire.h>
#include "rgb_lcd.h"

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
}
 
void loop()
{
  int soundValue = 0; //create variable to store many different readings
  for (int i = 0; i < 32; i++) //create a for loop to read 
  { soundValue += analogRead(sound_sensor);  } //read the sound sensor
 
  soundValue >>= 5; //bitshift operation 
  Serial.println(soundValue); //print the value of sound sensor
}