#include <wiringPi.h>
#include <stdio.h>
#include <time.h>
#include "ifttt.h"

void init_alarm();
void toalarmoff();
void toalarming();
void toalarmed();
void totriggered();
void toalarmsounding();
int main (int argc, char *argv[])
{
  init_alarm();
  return 0 ;
}
void init_alarm(){
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode (1, OUTPUT) ;
  pinMode (2, OUTPUT) ;
  pinMode (3, INPUT) ;
  pinMode (4, OUTPUT) ;
  pullUpDnControl(3, PUD_UP) ;
  toalarmoff();
}

void toalarmoff(){
  digitalWrite (1, HIGH) ;
  digitalWrite (2,  LOW) ;
  digitalWrite (4,  LOW) ;
  delay(5000);
  while (digitalRead(3) == 1);
  toalarming();
}

void toalarming(){
  time_t timestar;
  timestar = time(NULL);
  while(difftime(time(NULL), timestar) < 10.00 ){
  
    digitalWrite (1, HIGH) ; delay (500) ;
    digitalWrite (1,  LOW) ; delay (500) ;
    if(digitalRead(3) == 0){
      toalarmoff();
    }
    }
    digitalWrite (2, HIGH) ;
    digitalWrite (1,  LOW) ;
  toalarmed();
}
void toalarmed() {
  while (digitalRead(3) == 1){
    while(digitalRead(0) == 0 && digitalRead(3));
    while(digitalRead(0) == 1){
      totriggered();
      return;
    }
    
  }
  toalarmoff();
}

void totriggered(){
  time_t timestar;
  timestar = time(NULL);
  while(difftime(time(NULL), timestar) < 10.00){
    
    digitalWrite (1, HIGH) ;delay(500);
    digitalWrite (2, HIGH) ;delay(500);
    digitalWrite (1,  LOW) ;delay(500);
    digitalWrite (2,  LOW) ;delay(500);
    
    if ((digitalRead(3) == 0)) {
      toalarmoff();
    }
  }
  toalarmsounding();
}

void toalarmsounding(){
  while(1){
    if(digitalRead(3) == 0){
      toalarmoff();
    }
    digitalWrite (1, HIGH) ;
    digitalWrite (2, HIGH) ;
    digitalWrite (4, HIGH) ;
    ifttt("https://maker.ifttt.com/trigger/alarm_triggered/with/key/dcZuaJf3oHEAyHhu-55bJE", "my1", "my 2", "my 33333");
    delay(2000);
    digitalWrite (1, LOW) ;
    digitalWrite (2, LOW) ;
    digitalWrite (4, LOW) ;
    
  }
  
}