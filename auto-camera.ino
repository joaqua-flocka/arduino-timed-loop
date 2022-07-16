
#include<millisDelay.h>

int switchValue = 0;
unsigned long DELAY_TIME = 3600000;
unsigned long delayStart = 0; //time that the delay started
bool delayRunning = false;    //true if still waiting for delay to finish
bool takePic = true;         //keep track of camera state

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);         //open serial port, set the baud rate to 9600 bps
  pinMode (7,OUTPUT);
  takePic = true;
  delayStart = millis();
  delayRunning = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (delayRunning && ((millis() - delayStart) >= DELAY_TIME)) {
    delayStart += DELAY_TIME;  //prevents drift in delays

    takePic = true;
    
    if (takePic){
      digitalWrite(7, HIGH);   //turn LED on
      takePic = false;
    }
    
    else {
      digitalWrite(7, LOW);    //turn LED off
    }
  }
  
  if (millis() - delayStart == 1000){
      //Serial.print(millis());
      digitalWrite(7, LOW);
  }

}
