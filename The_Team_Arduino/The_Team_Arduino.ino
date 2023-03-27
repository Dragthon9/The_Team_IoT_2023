//2023 Project1
//coded by Luca Kauther-Kearney

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
const int R = 0;
const int G = 0;
const int B = 0;

 
void setup() 
{
  lcd.begin(16,2);
  Serial.begin(9600); //begin Serial Communication
  lcd.setRGB( 0, 10, 0 );
  lcd.noAutoscroll();
  lcd.print("hello, world!");
  //2 second delay
  delay(2000);
  lcd.clear();
// num multiplier for seconds of delay
}
 
void loop()
{
  // i<n sets how long till next reading
  for (int i = 0; i < 10; i++)
  {
    lcd.setCursor(0, 0);
    lcd.print("last reading: ");
    lcd.setCursor(0, 1);
    lcd.print(i);
    delay(1000);
    lcd.clear();
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Begining reading:");
  delay(1000);


  int arr[80];
  
  for (int i = 0; i < 80; i++)
  {
    int soundValue = 0;//create variable to store many different readings
    soundValue += analogRead(A2); //read the sound sensor
  
    soundValue >>= 5; //bitshift operation 
    arr[i] = soundValue; //stores value to array
    delay(125);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Getting average:");

  //gets average
  int sum = 0;
  for (int i = 0; i < 80; i++)
  {
    sum = sum + arr[i];
  }
  int average = sum / 80;

  //makes sure average isn't 0
  if (average == 0)
  {
    average = 1;
  }

  //checks average and displayes sound lv depending on how lowd it is
  if (average <= 150)
  {
    lcd.setRGB( 0, 100, 0 );
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Current noise lv: quiet");
    lcd.setCursor(0, 1);
    lcd.print("quiet");
  }
  else if (average > 150 && average <= 250)
  {
    lcd.setRGB( 100, 100, 0 );
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Current noise lv:");
    lcd.setCursor(0, 1);
    lcd.print("noisy");
  }
  else if (average > 250)
  {
    lcd.setRGB( 100, 0, 0 );
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Current noise lv:");
    lcd.setCursor(0, 1);
    lcd.print("loud");
  }
  delay(5000);

}

