// A B    C
// 0 var  5
// V=IR
// R=kx^n Cicumference or length
// k is a constant
// for b labelled potentionmeter n is 1
// R=kx^1=kx
// voltage at b = IR = Ikx
// I is constant k is constant x is variable
// As we rotate the knob the disctance from A changes hence x changes
// V at B is directly proportional to x
// the more the x the more is voltage
// if you rotated the knob to A V is 5v
// '''' to B V is 0
// and it is 2.5 in the middle
// Using arduino's Analog read we can read the voltages and covert them to a number between 1 and 1023 (by 10bit ADC)
// we can use the value from analog read to do various tasks like controllinf speed of motor,brightness of light,etc



//pot->Potentiometer
//We will use analog pin not the digital ones
int potPin = A0;
//0-1023
int potValue = 0;
//let control a led
int led = 9;
int brightness = 0;


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop() {
  potValue = analogRead(potPin);
  //prints 0-1023 depending on position
  //it is o at A and 1025 at C
  Serial.println(potValue);


  //convert 0 to 1023 to 0 to 255 for controlling led(pwm signal limit)
  brightness = map(potValue, 0, 1023, 0, 255);
  analogWrite(led, brightness);

  delay(100);
}
