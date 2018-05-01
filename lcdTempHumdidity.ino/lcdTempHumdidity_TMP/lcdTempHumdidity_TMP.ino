#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include "DHT.h"

//int motorSp = 0;
//int motorPin = 9;

//set the DHT pin to 7
#define DHTPIN 7

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2); //16 by 2 character display
} 

void loop()
{
  delay(250); //wait a sec (recommended for DHT11)
  //Read the data from the sensor
  dht.read(DHTPIN);
  //clear the lcd screen
  lcd.clear();
  //set the cursor at the beginning
  lcd.setCursor(0,0);
  //Print the temperature and humidity on the LCD
  lcd.print("Humidity = ");
  float h = dht.readHumidity();
  lcd.print (h);
    //sets the cursor on the second line so that it does not go off screen
  lcd.setCursor(0,1);
  lcd.print("Temp = ");
  float t = dht.readTemperature(true);
  lcd.print(t);

 // sensorVals[0] = digitalRead(h);
 // sensorVals[1] = digitalRead(t);

  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.print(", ");
  Serial.print("Temperature = ");
  Serial.println(t);
}
