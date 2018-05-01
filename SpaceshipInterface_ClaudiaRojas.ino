int switchState = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);
  //If there is voltage on the pin when digitalRead is called the switchState variable will get the HIGH(or 1) 
  //If there is no volatage on the pin, switchState will get the value LOW(0)
  
  if (switchState == LOW){
    //the switch is not pressed
    digitalWrite(3, HIGH); //green LED
    digitalWrite(4, LOW); //red LED
    digitalWrite(5, LOW); //red LED
    //If the switchSate is low turn green LED on and the red LED off
    //HIGH is on LOW is off
    }

    else{//the switch is pressed
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    
      delay(500); //wait for a quarter second
      //toggle the LEDs    
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      delay(1000); //wait for a quarter second
    }
  }
