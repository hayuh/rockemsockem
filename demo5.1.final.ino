#include <Servo.h>
Servo arm1; 
Servo arm2;
Servo arm3;
Servo arm4;

const int SERVO_ARM1 = 8;
const int SERVO_ARM2 = 7;
const int SERVO_ARM3 = 4;
const int SERVO_ARM4 = 2;

const int SWITCH_ARM1=A2;
const int SWITCH_ARM2=A3;
const int SWITCH_ARM3=A4;
const int SWITCH_ARM4=A5;

const int FORCE_SENSOR1 = A0;
const int FORCE_SENSOR2 = A1;

const int speakerPin = 11;
bool arm1_strike = false;
bool arm2_strike= false; 

int arm1State = 0; //0 is retracted, 1 is extending, 2 is retracting
int arm2State = 0; 
int arm3State = 0; //0 is retracted, 1 is extending, 2 is retracting
int arm4State = 0; 

unsigned long int arm1Timer = 0;
unsigned long int arm2Timer = 0;
unsigned long int arm3Timer = 0;
unsigned long int arm4Timer = 0;

unsigned long int toneTimer = 0;
int toneState = 0; //0 is not playing tone, 1 is playing tone
int bagState = 0;
unsigned long int bagTimer = 0;
void setup() {
  // put your setup code here, to run once:
  arm1.attach( SERVO_ARM1);
  arm2.attach(SERVO_ARM2);
  arm3.attach( SERVO_ARM3);
  arm4.attach(SERVO_ARM4);
  //bag.attach(8);
  //bag.write(0);
  arm1.write(0);
  arm2.write(180);
  arm3.write(0);
  arm4.write(180);
  Serial.begin(9600);

}


void loop() 
{
 
  
  if(digitalRead(SWITCH_ARM1) == 0 and arm1State == 0){ //arm is retractred and button is pressed 
    arm1State = 1;
    arm1Timer = millis();
    arm1.write(180);
  }
  if (arm1State == 1 and millis() - arm1Timer > 1000){
    arm1State = 2;
    arm1Timer = millis();
    arm1.write(0);
  }
  if (arm1State == 2 and millis() - arm1Timer > 1000){
    arm1State = 0;
  }

  
  if(digitalRead(SWITCH_ARM2) == 0 and arm2State == 0){ //arm is retractred and button is pressed 
    arm2State = 1;
    arm2Timer = millis();
    arm2.write(0);
  }
  if (arm2State == 1 and millis() - arm2Timer > 1000){
    arm2State = 2;
    arm2Timer = millis();
    arm2.write(180);
  }
  if (arm2State == 2 and millis() - arm2Timer > 1000){
    arm2State = 0;
  }

  if(digitalRead(SWITCH_ARM3) == 0 and arm3State == 0){ //arm is retractred and button is pressed 
    arm3State = 1;
    arm3Timer = millis();
    arm3.write(180);
  }
  if (arm3State == 1 and millis() - arm3Timer > 1000){
    arm3State = 2;
    arm3Timer = millis();
    arm3.write(0);
  }
  if (arm3State == 2 and millis() - arm3Timer > 1000){
    arm3State = 0;
  }

  if(digitalRead(SWITCH_ARM4) == 0 and arm4State == 0){ //arm is retractred and button is pressed 
    arm4State = 1;
    arm4Timer = millis();
    arm4.write(0);
  }
  if (arm4State == 1 and millis() - arm4Timer > 1000){
    arm4State = 2;
    arm4Timer = millis();
    arm4.write(180);
  }
  if (arm4State == 2 and millis() - arm4Timer > 1000){
    arm4State = 0;
  }

  if(analogRead(FORCE_SENSOR1)< 800 and toneState == 0)
  {
    tone(speakerPin, 440);
    toneTimer = millis();
    toneState = 1;
  }
  if (toneState == 1 && millis() - toneTimer > 500){
    noTone(speakerPin);
    toneState = 2;
  }
  if (toneState ==2  && analogRead(FORCE_SENSOR1) > 1000){
    toneState = 0;
  }  

  if(analogRead(FORCE_SENSOR2)< 800 and toneState == 0)
  {
    Serial.println("tone started");
    tone(speakerPin, 440);
    toneTimer = millis();
    toneState = 1;
  }
  if (toneState == 1 && millis() - toneTimer > 500){
    Serial.println("tone over");
    noTone(speakerPin);
    toneState = 2;
  }
  if (toneState ==2  && analogRead(FORCE_SENSOR2) > 1000){
    toneState = 0;
  }  
  
  

  
 
  
}
