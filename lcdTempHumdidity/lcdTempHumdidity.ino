#include <SoftwareSerial.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include "DHT.h"

Servo myServo;

//set the DHT pin to 13
#define DHTPIN 7

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11, 12, 5, 4, 3, 2); 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2); //16 by 2 character display
 // pinMode(motorPin,OUTPUT);
  myServo.attach(13);
  //myServo.write(0);
  pinMode(8,OUTPUT);
  analogWrite(8,45);
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

//send data back to the computer
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.print(", ");
  Serial.print("Temp = ");
  Serial.println(t);

//Shut the water pipe depending on the temp and humidity
  //(t>=45&&h>50)
  if (t<=70&&h>=25){
    myServo.write(30);
  }
  delay(15);
//  if(t<=70&&h<30){
//    myServo.write(30);
//  }
}
