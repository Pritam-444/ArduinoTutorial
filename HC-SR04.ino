// A ultrasonic sensor(HCSRO4) has 4 pins.
// 2 for power and two for data
// it has a trigger pin and a echo pin
// physically it has a transmitter and a reciever
// the transmitter emits sound waves at around 40khz and the reciever reciever the reflected waves
// to transmit a sound wave we set the trigger pin as high
// this make the transmitter emit sound and also turn the reciever high
// we usually disable the transmitter after 10 microseconds
// the echo pin gives a high reading as long as it doent recive any sound
// so if the sound reflects back from a surface or object and is recieved by the reciever, the echo pin gives low signal
// we capture the time difference between the first high and the last low lets say t
// sound travels in aprrox 332 m/s
// v=S/t where S is distance
// S=vt
// we got the time for the sound to travel to the object and back so the S we will get is double
// S(actual) =vt/2
// Now the accuracy depends upon the temperature,humidity,quality of sensor,type of surface
// We are going to assume some values for the speed of sound and continue
// lets start
int trigPin = 9;
int echoPin = 10;
int ledPin = 4;
int BuzzerPin = 5;
//I am using it in a airconditoned roomm but it may vary a lot(like 35 in summer if outside)(We may  use a temp sensor or just accept some loss in accuracy)
float temp = 27.0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);
}
float getDistanceInCM() {
  //turn off in case it was on
  digitalWrite(trigPin, LOW);
  //wait 2micros for it to turn off
  delayMicroseconds(2);
  //Turn on the transmitter
  digitalWrite(trigPin, HIGH);
  //wait 10micros
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //so we have send a pulse of sound from transmitter now its time to read the time difference from the reciever
  //30000 micros or 30ms is the max time it will wait so we are restictiong the max distance and preventing lag
  long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return -1;
  float speed = 331.0 + 0.6 * temp;
  //speed = m/s but we have duration  in micro seconds and want distance in cm so 1m = 100cm and 1s = 10^6micros = 1000000us
  //so 100/1000000=10000 then the correct unit v would be v/10000.0
  float distance = (duration / 2) * (speed / 10000.0);
  return distance;
}
void loop() {
  long distance = getDistanceInCM();
  Serial.println(distance);

  if (distance >= 4 && distance <= 30) {
    int delayTime = map(distance, 4, 30, 100, 800);
    int pitch = map(distance, 4, 30, 2000, 500);
    digitalWrite(ledPin, HIGH);
    tone(BuzzerPin, pitch);
    delay(delayTime);
    digitalWrite(ledPin, LOW);
    noTone(BuzzerPin);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(BuzzerPin);
  }

  //take reading every 500 ms and print the distance
  delay(50);
}
