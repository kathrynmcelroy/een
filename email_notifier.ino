#include <Stepper.h> //call stepper library
#define STEPS 200 //the number of steps in one revolution

int ledPin = 13; // LED connected to digital pin 13
int val; // Value read from the serial port
int emailnumber = 1 ; //number of emails
int lastemailnumber = 0; //previous number of emails
//create instance of the stepper class, 
//specifying the number of steps and the pins it's connected to
Stepper stepper(STEPS, 8, 9, 10, 11); 

void setup()
{
 pinMode(ledPin, OUTPUT); // sets the LED digital pin as output
 Serial.begin(9600);
 Serial.flush();
 stepper.setSpeed(5); //set Stepper speed
}

void loop()
{
 // Read from serial port
 if (Serial.available())
 {
   val = Serial.read();
   Serial.println(val); //val will be the ASCii value of the letter
   
   //translate ASCii value of letters to number of emails
   if (val == 97)
   {
     emailnumber = 1;
   }
   if (val == 98)
   {
     emailnumber = 2;
   }
   if (val == 99)
   {
     emailnumber = 3;
   }
   if (val == 100)
   {
     emailnumber = 4;
   }
   if (val == 101)
   {
     emailnumber = 5;
   }
   if (val == 102)
   {
     emailnumber = 6;
   }
   if (val == 110)
   {
     emailnumber = 0;
   }
   if (val == 109)
   {
     emailnumber = 7;
   }  
   //check against the previous email number
  if (emailnumber > lastemailnumber) //if there are more email
  {
     stepper.step(-50 * (emailnumber - lastemailnumber)); 
     digitalWrite(ledPin, LOW);
  }
  
  else if (emailnumber == lastemailnumber) //if it's the same amount
  {
    digitalWrite(ledPin, LOW); //keep the LED off, you can't eat the M&Ms
   }

  else if (emailnumber < lastemailnumber) //if it's less email
  {
    digitalWrite(ledPin, HIGH); //turn the LED on, to indicate you can eat the M&Ms
   }
 lastemailnumber = emailnumber;
 digitalWrite(8, LOW);
 digitalWrite(9, LOW);
 digitalWrite(10, LOW);
 digitalWrite(11, LOW);
 }
}

