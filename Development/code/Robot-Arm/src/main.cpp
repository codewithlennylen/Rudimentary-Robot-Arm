#include <Servo.h>
#include <Stepper.h>

int stepsPerRevolution = 2048;
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

// The Joysticks
int Vrx1 = A0;
int Vry1 = A1;
int Vrx2 = A8;
int Vry2 = A9;

int lowerArmPosition = 90;
int foreArmPosition=0;

Servo myServo1;
Servo myServo2;
Servo myServo3;

// IN1, IN3, IN2, IN4
Stepper myStepper = Stepper(stepsPerRevolution,IN1,IN3,IN2,IN4);

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);
  myServo1.attach(7);
  myServo2.attach(6);
  myServo3.attach(5);

    int newValue = map(lowerArmPosition,12,180, 180,10);
    myServo1.write(newValue);
    myServo2.write(lowerArmPosition);
    myServo3.write(foreArmPosition);
  // 5 RPM
  myStepper.setSpeed(10);
}

void loop()
{

//  myStepper.step(-stepsPerRevolution);
//  delay(100);

  // We have inverted the axis
  int Vrx1Value = analogRead(Vrx1); // y-axis
  int Vry1Value = analogRead(Vry1); // x-axis
  int Vrx2Value =analogRead(Vrx2);
  int Vry2Value =analogRead(Vry2);
  
//  Serial.println(Vry1Value);
if(Vry1Value<150){
  myStepper.step(-100);
  delay(50);
  
  }else if(Vry1Value>900){
  myStepper.step(100);
  delay(50);
  
  }


  if (Vrx1Value < 150){

    int newValue = map(lowerArmPosition,12,180, 180,10);
    myServo1.write(newValue);
    myServo2.write(lowerArmPosition);
    delay(30);
    lowerArmPosition++;
    }else if(Vrx1Value > 900){
    int newValue = map(lowerArmPosition,12,180, 180,10);
    myServo1.write(newValue);
    myServo2.write(lowerArmPosition);
    delay(30);
    lowerArmPosition--;
    }
  if (Vrx2Value <150){
   myServo3.write(foreArmPosition);
   delay(30);
   foreArmPosition++;
  }
  else if(Vrx2Value>900){
    myServo3.write(foreArmPosition);
    delay(30);
    foreArmPosition--;
 
  }


  }
 
  // Fore-arm
//  for (int i = 0; i < 150; i++)
//  {
//    
//  }
//
//  for (int i = 150; i > 0; i--)
//  {
//    myServo3.write(i);
//    delay(10);
//  }