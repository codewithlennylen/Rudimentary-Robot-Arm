#include <Servo.h>
#include <Stepper.h>

int stepsPerRevolution = 2048;
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;


Servo myServo1;
Servo myServo2;
Servo myServo3;

// IN1, IN3, IN2, IN4
Stepper myStepper = Stepper(stepsPerRevolution,IN1,IN3,IN2,IN4);

void setup()
{
  // put your setup code here, to run once:
  myServo1.attach(7);
  myServo2.attach(6);
  myServo3.attach(5);
//  myServo1.write(180);
//  myServo2.write(12);
  myServo3.write(0);

  // 5 RPM
  myStepper.setSpeed(10);
}

void loop()
{

//  myStepper.step(-stepsPerRevolution);
//  delay(100);
  // put your main code here, to run repeatedly:
  for (int i = 12; i < 180; i++)
  {
    int newValue = map(i,12,180, 180,10);
    myServo1.write(newValue);
    myServo2.write(i);
    delay(10);
  }

  for (int i = 180; i > 12; i--)
  {
    int newValue = map(i,12,180, 180,10);
    myServo1.write(newValue);
    myServo2.write(i);
    delay(10);
  }

  for (int i = 0; i < 150; i++)
  {
    myServo3.write(i);
    delay(10);
  }

  for (int i = 150; i > 0; i--)
  {
    myServo3.write(i);
    delay(10);
  }



}