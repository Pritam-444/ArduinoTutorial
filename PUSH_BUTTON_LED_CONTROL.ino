int BUTTON_PIN=2;
int LED_PIN=8;
int isLED_ON=0;
//we will toggle a led with button

void setup(){
  //It keep digital pin at high so that we  can connect the button and make it low to read the low input
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  //Keep led off
  pinMode(LED_PIN,OUTPUT);
  digitalWrite(LED_PIN,LOW);
}
void HandleButtonPress(){
  Serial.println("Button was pressed");
  if(isLED_ON==0){
    digitalWrite(LED_PIN,HIGH);
    isLED_ON=1;
  }
  else{
  digitalWrite(LED_PIN,LOW);
  isLED_ON=0;
  }
  //keep a delay of 500ms so that u dont get multiple click from 1 button press
  delay(500);
}

void loop(){
  if(digitalRead(BUTTON_PIN)==LOW)
  HandleButtonPress();

}
