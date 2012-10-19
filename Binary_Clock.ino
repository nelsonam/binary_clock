

#include <Time.h>

int sec;
int minte;
int hr;
int munit = 0;
int hunit = 0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop()
{
  //this is just setting the time manually, cause I can't get it to dynamically update right now
  setTime(4,23,30,19,10,2012);
  time_t t = now();
  hr = hour(t);
  minte = minute(t);
  sec = second(t);
  static unsigned long lastTick = 0; // set up a local variable to hold the last time we moved forward one second
  // move forward one second every 1000 milliseconds

  if (millis() - lastTick >= 1000) 
  {
    lastTick = millis();
    sec++;
  }
  
  if(sec >= 60)
  {
    minte++;
    sec = 0;
  }
  
  // move forward one hr every 60 minutes
  if (minte >= 60)
  {
    hr++;
    minte = 0; // reset minutes to zero
  }

  if (hr >= 24) 
  {
    hr=0;
    minte = 0; // reset minutes to zero
  }
  
  munit = minte%10; //sets the variable munit and hunit for the unit digits
  hunit = hr%10;
  
      //this converts to binary
      digitalWrite(2, (minte &        B1)); // -------X Decimal value 1
      digitalWrite(3, (minte &       B10)); // ------X- Decimal value 2
      digitalWrite(4, (minte &      B100)); // -----X-- Decimal value 4
      digitalWrite(5, (minte &     B1000)); // ----X--- Decimal value 8
      digitalWrite(6, (minte &    B10000)); // ---X---- Decimal value 16
      digitalWrite(7, (minte &   B100000)); // --X----- Decimal value 32
      
      digitalWrite(8, (hr &        B1)); // -------X Decimal value 1
      digitalWrite(9, (hr &       B10)); // ------X- Decimal value 2
      digitalWrite(10, (hr &      B100)); // -----X-- Decimal value 4
      digitalWrite(11, (hr &     B1000)); // ----X--- Decimal value 8
      digitalWrite(12, (hr &    B10000)); // ---X---- Decimal value 16
  
  
}


