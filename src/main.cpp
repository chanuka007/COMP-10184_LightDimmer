#include <Arduino.h>
int analogNum= 1;

void setup()
{
  // configure the USB serial monitor
  Serial.begin(115200);

  // configure pin D4 as a digital output - this is the LED
  pinMode(D4, OUTPUT);

  // set default PWM range
  analogWriteRange(1024);

  pinMode(D5, INPUT_PULLUP);

  //set the light off
  digitalWrite(D4,HIGH);

}

bool toggle = false;
bool pressedIn = false;
bool unPressed = false;

void loop()
{
    //set analog num to the analog resistor value

  analogNum = analogRead(A0); 

  if(toggle){
  //Serial.println(String(analogNum));
analogWrite(D4, analogNum);

}else{
  digitalWrite(D4,HIGH);
}


  int iButton = digitalRead(D5);
  // if the button is pressed flip the pressed in boolean on
  if (iButton == 0)
  {
    pressedIn = true;
  }
  // if the button was pressed in and then unpressed turn on the unpressed toggle
  if (iButton == 1&&pressedIn)
  {
    unPressed = true;
  }
  // if the button was pressed in then unpressed flip the toggle 
if(pressedIn && unPressed){
      //Serial.println("Button pressed");
      pressedIn = false;
      unPressed = false;
      if(toggle){
        toggle=false;
      }else{
        toggle=true;
      }

      //if toggle is on then set the light to the analog value of the ressistor
}
//Serial.println(String(toggle));
delay(1);
}