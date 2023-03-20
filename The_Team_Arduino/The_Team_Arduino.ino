

//2023 Project1
//coded by Luca Kauther-Kearney

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
  //2 second delay
  delay(2000);
// num multiplier for seconds of delay
  
}
 
void loop()
{
  int n = 120;
  delay(n * 1000);

  int arr[20];
  for (int i = 0; i < 20; i++)
  {
    int soundValue = 0; //create variable to store many different readings
    for (int x = 0; x < 500; i++) //create a for loop to read every half second
    { soundValue += analogRead(sound_sensor);  } //read the sound sensor
  
    soundValue >>= 5; //bitshift operation 
    arr[i] = soundValue; //stores value to array
    //Serial.println(soundValue); //print the value of sound sensor
  }

  //gets average
  int sum = 0;
  for (int i = 0; i < 20; i++)
  {
    sum = sum + arr[i];
  }
  int average = sum / 20;

  //makes sure average isn't 0
  if (average == 0)
  {
    average = 1;
  }

  //checks average and displayes sound lv depending on how lowd it is
  if (average <= 150)
  {
    lcd.setRGB( 0, 100, 0 );
    lcd.print("Current noise lv: quiet");
  }
  else if (average > 150 && average <= 250)
  {
    lcd.setRGB( 100, 100, 0 );
    lcd.print("Current noise lv: noisy");
  }
  else if (average > 250)
  {
    lcd.setRGB( 100, 0, 0 );
    lcd.print("Current noise lv: loud AF");
  }

}

