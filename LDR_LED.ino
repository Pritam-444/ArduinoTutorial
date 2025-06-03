int LDR_PIN=A0;
int LDR_READING=0;

int LED_PIN=7;
int brightness=0;

void setup(){
  
  Serial.begin(9600);
pinMode(LED_PIN,OUTPUT);
}
void loop(){
LDR_READING=analogRead(LDR_PIN);
  Serial.println(LDR_READING);
  brightness = map(LDR_READING,0,1023,0,255);
  analogWrite(LED_PIN,brightness);
  delay(500);
}
