//defined led pins
int ledPins[] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3 };
int ledCount = 10;
//Turn led off
void turnLedOff() {
  for (int i = 0; i < ledCount; i++)
    digitalWrite(ledPins[i], HIGH);
}

//Patterns
//Pattern 1 Chase led from left to right then viceversa
//this pattern can also be called ping pong
 void Chase() {
   //loop creatse trail from left to right
  for (int i = 0; i < ledCount; i++) {
   //turn the prev  led  off
     turnLedOff();
     //turn the current led on
  digitalWrite(ledPins[i], LOW);
     //Delay so the effect is visible
     delay(100);
   }
   delay(100);
   //loop creates trail from right to left(fliipinf thew loop)
   for (int i = ledCount-1; i >=0; i--) {
     //turn the prev  led  off
     turnLedOff();
     //turn the current led on
     digitalWrite(ledPins[i], LOW);
     delay(100);
   }
 }///

//Pattern 2 : Fill led from left to right and vice versa
// we modifed chase to not turn off the leds and thus got fill effect
 void Fill(){
   for (int i = 0; i < ledCount; i++) {
    
     //turn the current led on
     digitalWrite(ledPins[i], LOW);
     //Delay so the effect is visible
     delay(100);
   }
   turnLedOff();
   delay(100);
   //loop creates trail from right to left(fliipinf thew loop)
   for (int i = ledCount-1; i >=0; i--) {
     //turn the current led on
     digitalWrite(ledPins[i], LOW);
       delay(100);
   }
   //reset after loop
    turnLedOff();
 }


//Pattern 3: Twinkle. We will use random funtion to turn on random leds
void Twinkle(){
while(true){
  //turn prev led off
  turnLedOff();
  //choose a random led number
  int randomLed = random(ledCount);
  //turn it on
  digitalWrite(randomLed,LOW);
  //wait 200ms
  delay(200);
}
}


void setup() {
  //First create pins
  for (int i = 0; i < ledCount; i++)
    pinMode(ledPins[i], OUTPUT);
  //turn of led
  turnLedOff();
}

void loop() {
Fill();
}
