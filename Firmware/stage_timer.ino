#include "Countimer.h"
#include <SevenSeg.h>

Countimer timer;
SevenSeg disp(2,3,4,5,6,7,8);

const int numOfDigits=4;
int digitPins[numOfDigits]={10,12,A0,A2};

String m,s;
int mi,se;
long int mis;


void setup() {
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
    disp.setDigitPins(numOfDigits, digitPins);
  //disp.setRefreshRate(150);
  //disp.setDigitDelay(10000000);
  disp.setActivePinState(HIGH,HIGH);
  //disp.setDPPin(9);


  timer.setCounter(0, 18, 00, timer.COUNT_DOWN, onComplete);

    // Print current time every 1s on serial port by calling method refreshClock().
  timer.setInterval(refreshClock, 1000);
}
void refreshClock() {

//  disp.writeClock(timer.getCurrentMinutes(),timer.getCurrentSeconds());
  
}

void onComplete() {
  Serial.println("Complete!!!");
  while(1)
  {

   for(int i=0;i<100;i++)
     disp.write("0000");
   for(int i=0;i<100;i++)
     disp.write("----");

  }
}

void loop() {
  // Run timer
  
  timer.run();
  disp.writeClock(timer.getCurrentMinutes(),timer.getCurrentSeconds());
  
    // Now timer is running and listening for actions.
    // If you want to start the timer, you have to call start() method.
    if(!timer.isCounterCompleted()) {
      timer.start();
    }
   
}
