#include <Sleep_n0m1.h>

Sleep sleep;

#define intPin 2

void setup()
{

   Serial.begin(9600);


}

void loop()
{

  delay(100); ////delays are just for serial print, without serial they can be removed
  Serial.println("execute your code here");

  Serial.print("Sleeping Till Interrupt");

  delay(100); //delay to allow serial to fully print before sleep

  sleep.pwrDownMode(); //set sleep mode

  //Sleep till interrupt pin equals a particular state.
  //In this case "low" is state 0.
  sleep.sleepPinInterrupt(intPin,LOW); //(interrupt Pin Number, interrupt State)



}
