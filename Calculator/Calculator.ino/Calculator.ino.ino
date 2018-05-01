#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int lPin = 0;
int rPin = 1;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2); 
  pinMode(6,OUTPUT);
  analogWrite(6,1);
  Serial.begin(9600);
  pinMode(lPin,INPUT);
  pinMode(rPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print(" Binary Calc ");
  delay(250);
  lcd.clear;
  lcd.setCursor(0,0);
  lcd.print("Input Binary Digits");
  lcd.setCursor(0,1);
  lcd.print("00000000");
  
}
