//#include <LiquidCrystal.h>
#include <Servo.h>
const int trigPin = 6;
const int echoPin = 7;
const int trigPinFull = 4;
const int echoPinFull= 3;
int red = 9;
int green = 10;
int blue = 11;
Servo servo;

void setup()
{
    pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);
  	pinMode(trigPinFull, OUTPUT);  
	pinMode(echoPinFull, INPUT);
   	servo.attach(12);
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
	Serial.begin(9600);
    servo.write(0);
}

void loop()
{
  //dustbin opened and closed
  
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  //dustbin full
  
  long duration2, distance2;
  digitalWrite(trigPinFull, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinFull, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFull, LOW);
  duration2 = pulseIn(echoPinFull, HIGH);
  distance2 = (duration2/2) / 29.1;
  
  //Logic
  	
  	if((distance < 50)&&(distance2 > 30)){
      Serial.println("opened");
      servo.write(90);
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      digitalWrite(blue, LOW);
      Serial.println(distance);
      delay(2000);
    } else if((distance < 50)&&(distance2 < 30)){
      Serial.println("closed");
      servo.write(0);
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      digitalWrite(blue, LOW);
      Serial.println(distance);
      delay(2000);
    } else if((distance > 50)&&(distance2 > 30)){
      Serial.println("Available");
      servo.write(0);
      digitalWrite(green, LOW);
      digitalWrite(red, LOW);
      digitalWrite(blue, HIGH);
      Serial.println(distance);
      delay(2000);
    } else if ((distance > 50)&&(distance2 < 30)){
      Serial.println("closed");
      servo.write(0);
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      digitalWrite(blue, LOW);
      Serial.println(distance);
      delay(2000);
    }
delay(500);

}
