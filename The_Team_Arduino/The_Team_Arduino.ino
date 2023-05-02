//2023 Project1
//coded by Luca Kauther-Kearney

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
const int R = 0;
const int G = 0;
const int B = 0;

 #define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
#define BLYNK_TEMPLATE_NAME         "Device"
#define BLYNK_AUTH_TOKEN            "YourAuthToken"


#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, millis() / 1000);
}
void setup() 
{
// Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);

  lcd.begin(16,2);
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
  Blynk.run();
  timer.run(); // Initiates BlynkTimer

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
    soundValue = analogRead(A2); //read the sound sensor
  
    soundValue >>= 5; //bitshift operation 
    arr[i] = soundValue; //stores value to array
    delay(125);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Getting average:");
  delay(1000);

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
  if (average <= 50)
  {
    lcd.setRGB( 0, 100, 0 );
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Current noise lv: quiet");
    lcd.setCursor(0, 1);
    lcd.print("quiet-Av:", average);
    myTimerEvent(average);
  }
  else if (average > 50 && average <= 150)
  {
    lcd.setRGB( 100, 100, 0 );
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Current noise lv:");
    lcd.setCursor(0, 1);
    lcd.print("noisy-Av:", average);
    myTimerEvent(average);
  }
  else if (average > 150)
  {
    lcd.setRGB( 100, 0, 0 );
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Current noise lv:");
    lcd.setCursor(0, 1);
    lcd.print("loud-Av:", average);
    myTimerEvent(average);
  }
  delay(5000);

}

