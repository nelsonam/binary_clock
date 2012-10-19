

#include <Time.h>

#define TIME_MSG_LEN  11   // time sync to PC is HEADER followed by unix time_t as ten ascii digits
#define TIME_HEADER  'T'   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

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
  //time_t t = now(); // store the current time in time variable t 
  Serial.println(now());
  //hr = hour(t);          // returns the hr for the given time t
  Serial.println(hr);
  //minte = minute(t);        // returns the minute for the given time t
  //sec = second(t);
  
}

void loop()
{
  setTime(4,23,30,19,10,2012);
  
  //Serial.println(now());
  time_t t = now();
  hr = hour(t);
  minte = minute(t);
  sec = second(t);
  static unsigned long lastTick = 0; // set up a local variable to hold the last time we moved forward one second
  // (static variables are initialized once and keep their values between function calls)
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
  /*Serial.println(sec);
  if(munit>0)
  {
     Serial.println(munit);
    Serial.println(hunit);
  }*/
  
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
  
  
  //minutes units
 /* if(munit == 1 || munit == 3 || munit == 5 || munit == 7 || munit == 9) {  digitalWrite(1, LOW);} else {  digitalWrite(1, HIGH);}
  if(munit == 2 || munit == 3 || munit == 6 || munit == 7) {digitalWrite(2, LOW);} else {digitalWrite(2,HIGH);}
  if(munit == 4 || munit == 5 || munit == 6 || munit == 7) {digitalWrite(3, LOW);} else {digitalWrite(3,HIGH);}
  if(munit == 8 || munit == 9) {digitalWrite(4, LOW);} else {digitalWrite(4,HIGH);}

  //minutes 
  if((minute >= 10 && minute < 20) || (minute >= 30 && minute < 40) || (minute >= 50 && minute < 60))  {digitalWrite(5, LOW);} else {digitalWrite(5,HIGH);}
  if(minute >= 20 && minute < 40)  {digitalWrite(6, LOW);} else {digitalWrite(6,HIGH);}
  if(minute >= 40 && minute < 60) {digitalWrite(7, LOW);} else {digitalWrite(7,HIGH);}

  //hr units
  if(hunit == 1 || hunit == 3 || hunit == 5 || hunit == 7 || hunit == 9) {digitalWrite(8, LOW);} else {digitalWrite(8,HIGH);}
  if(hunit == 2 || hunit == 3 || hunit == 6 || hunit == 7) {digitalWrite(9, LOW);} else {digitalWrite(9,HIGH);}
  if(hunit == 4 || hunit == 5 || hunit == 6 || hunit == 7) {digitalWrite(10, LOW);} else {digitalWrite(10,HIGH);}
  if(hunit == 8 || hunit == 9) {digitalWrite(11, LOW);} else {digitalWrite(11,HIGH);}

  //hr
  if(hr >= 10 && hr < 20)  {digitalWrite(12, LOW);} else {digitalWrite(12,HIGH);}
  if(hr >= 20 && hr < 24)  {digitalWrite(13, LOW);} else {digitalWrite(13,HIGH);}*/
}


