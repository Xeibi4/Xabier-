
 
// include Arduino stepper motor library
#include <Stepper.h>
 
// define number of steps per revolution
#define STEPS 32
 
// define stepper motor control pins
#define IN1  12
#define IN2  11
#define IN3  10
#define IN4  9



 
// initialize stepper library
Stepper stepper(STEPS, IN4, IN2, IN3, IN1);


// joystick pot output is connected to Arduino A0
#define joystick  A0
int LED1 = 2; // the pin the LED is connected to 
int LED2 = 4; // the pin the LED is connected to  

void setup()
 
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT); // Declare the LED as an output
  pinMode (LED2, OUTPUT); // Declare the LED as an output
  
  // read analog value from the potentiometer
  int val = analogRead(joystick);
  }

  void loop ()

  {

    // read analog value from the potentiometer
      int val = analogRead(joystick) ; 
      Serial.print("X ardatza:  ");
      Serial.print(val); 

 
  // if the joystic is in the middle ===> stop the motor
  if(  (val > 512) && (val < 536) )
  {
    Serial.print("Geldirik");
    Serial.print(" ");
    Serial.print("Abiadura=     ");
  Serial.println(0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
   
  }
 
  else
  {
    // move the motor in the first direction
    while (val >= 536)
    {
      Serial.print("Eskubitara");
      Serial.print(" ");
      // map the speed between 5 and 500 rpm
      int speed_ = map(val, 536, 1023, 5, 500);
      // set motor speed
      stepper.setSpeed(speed_);
 
      // move the motor (1 step)
      stepper.step(10);
 
      val = analogRead(joystick);
      Serial.print("Abiadura=     ");
      Serial.println(speed_);

      Serial.print("X ardatza: ");
      Serial.println(val);

      digitalWrite (LED2, HIGH); 
    }
 
    // move the motor in the other direction
    while (val <= 512)
    {
      Serial.print("Ezkerretara");
      Serial.print(" ");
      // map the speed between 5 and 500 rpm
      int speed_ = map(val, 512, 0, 5, 500);
      // set motor speed
      stepper.setSpeed(speed_);
 
      // move the motor (1 step)
      stepper.step(-10);
 
      val = analogRead(joystick);
      Serial.print("Abiadura=     ");
      Serial.println(speed_);

        digitalWrite(LED1, HIGH);

          Serial.print("X ardatza: ");
      Serial.println(val);
      
  Serial.println(1);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    }
 
  }
 
}
