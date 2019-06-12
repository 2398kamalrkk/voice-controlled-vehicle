#include <AFMotor.h>
#include <Servo.h>
String voice;
 
AF_DCMotor motor1 (1, MOTOR12_1KHZ);
AF_DCMotor motor2 (2, MOTOR12_1KHZ);
int LED1 = A0;
int LED2 = A1;
int buzzerPin = A2;
void setup()
{
  Serial.begin(9600);
  myServo.attach(10);
  myServo.write(90);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}
 
void loop() 
{
  while (Serial.available()){ 
     delay(10);
    char c = Serial.read();
    if (c == '#') {break;}
    voice += c;
  }
  if (voice.length() > 0){
    if(voice == "*go ahead"){
      forward_car();
      }
    else if(voice == "*go back"){
      back_car();
      }
    else if(voice == "*turn right") {
      right_car();
    }
    else if(voice == "*turn left") {
      left_car();
    }
    else if(voice == "*stop") {
      stop_car();
    }
    
  voice=""; //Reset the variable after initiating
  }
}
 
void forward_car()
{
  motor1.run(FORWARD);
  motor1.setSpeed(170);
  motor2.run(FORWARD);
  motor2.setSpeed(170);
  delay(2000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
  
void back_car()
{
  motor1.run(BACKWARD);
  motor1.setSpeed(170);
  motor2.run(BACKWARD);
  motor2.setSpeed(170);
  delay(2000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
  
void right_car()
{
  myServo.write(0);
  delay(1000);
  myServo.write(90);
  delay(1000);
  motor1.run(FORWARD);
  motor1.setSpeed(170);
  motor2.run(BACKWARD);
  motor2.setSpeed(170);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
  
void left_car()
{
  myServo.write(180);
  delay(1000);
  myServo.write(90);
  delay(1000);
  motor1.run(BACKWARD);
  motor1.setSpeed(170);
  motor2.run(FORWARD);
  motor2.setSpeed(170);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
void stop_car ()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}