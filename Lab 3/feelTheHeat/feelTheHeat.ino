const int sensorPin = A0;
//const float baseLineTemp;

const int blueLEDPin = 10;
const int greenLEDPin = 9;
const int redLEDPin = 11;

int redValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int blueSensorValue = 0;

const int allReadings = 5;

int readings[allReadings];
int readInd = 0;
int total = 0;
int avgSensorVal = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open a serial port

  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);

  for(int thisReading = 0; thisReading < allReadings; thisReading++){
    readings[thisReading] = 0;  
  }
  
  }

void loop() {    
  // put your main code here, to run repeatedly:

//  analogWrite(redLEDPin, 0);
//  analogWrite(blueLEDPin, 255);
  
  delay(1000);

//Sensor Value  
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

//Normalized Sensor Value
  Serial.print(", Normalized Sensor Value: ");
  Serial.print(avgSensorVal);

//Voltage  
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

//Temperature
  Serial.print(", degrees C: ");
  //convert the voltage to temperature in degrees
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

//Getting the Over Threshhold
  Serial.print(", Over Treshhold: ");
  //the amount is over the "base" room temp
  float newVoltage = (avgSensorVal / 1024.0) * 5.0;
  float newTemp = (newVoltage - .5) * 100;
  float overThresh = temperature - newTemp;
  //Serial.println(newTemp);
  Serial.println(overThresh);

//Collecting the Normalized Sensor Value
  total = total - readings[readInd];
  readings[readInd] = analogRead(sensorPin);
  total = total + readings[readInd];
  readInd = readInd + 1;
  if(readInd >= allReadings){
    readInd = 0;
  }
  avgSensorVal = total / allReadings;

}

