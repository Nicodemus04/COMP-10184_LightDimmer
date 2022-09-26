#include <Arduino.h> 

void setup() { 
  
  Serial.begin(115200); //configure the USB serial monitor 
 
  //configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 
  pinMode(D5, INPUT_PULLUP); 
   
  analogWriteRange(1023); //set default PWM range
} 

int prev = HIGH; //previous button state
int cur; //current button state
int count = 0; //counter to act as a way to use the button as a switch
void loop() { 
    cur = digitalRead(D5);
    if (cur == LOW && prev == HIGH)//if previous button state is HIGH and current button state is LOW increace count
    {
      count++;
    }

    prev = cur;
    
    if (count%2 !=0 )//if count is an odd number tunrs on LED
    {
      analogWrite(D4, analogRead(A0)); //turns on LED (britness based off of variable resitor)
    } 
    else//if count is an even number turns off LED
    {
      count = 2; //prevents program from crashing due to int limit
      digitalWrite(D4, HIGH); //turns LED off
    }
    delay(1); 
} 