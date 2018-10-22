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
  delay(2000);
  while (digitalRead(3) == 1);
  toalarming();
}

void toalarming(){
  time_t timestar;
	time_t t0;
  delay(1000);
  timestar = time(NULL);
	while(difftime(time(NULL), timestar) < 10.00 ){
	  t0 = time(NULL);
	  while(difftime(time(NULL), t0) < 0.50 && digitalRead(3) == 1){
  
	    digitalWrite (1, HIGH) ;
	  }
	  while (digitalRead(3) == 0){
	    toalarmoff();  
	    return;
    }
	
    t0 = time(NULL);
    while(difftime(time(NULL), t0) < 0.50 && digitalRead(3) == 1){

	    digitalWrite (1,  LOW) ;
	  }
    while(digitalRead(3) == 0){
      toalarmoff();
	    return;
    }  
  }
  digitalWrite (1,  LOW) ;
  digitalWrite (2,  HIGH) ;
  toalarmed();
}

void toalarmed() {
  digitalWrite(2, HIGH);
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
  time_t t0;
  timestar = time(NULL);
  while(difftime(time(NULL), timestar) < 10.00){
    t0 = time(NULL);
    while(difftime(time(NULL), t0) < 1.00 && digitalRead(3) == 1){
      digitalWrite (2,  HIGH) ;
      digitalWrite (1,  HIGH) ;
    }
    while (digitalRead(3) == 0){
      toalarmoff();  
      return;
    }
   
    t0 = time(NULL); 
    while(difftime(time(NULL), t0) < 1.00 && digitalRead(3) == 1){

      digitalWrite (1,  LOW) ;
      digitalWrite (2,  LOW) ;
    }
    while (digitalRead(3) == 0){
      toalarmoff();  
      return;
    }
  }
  toalarmsounding();
}

void toalarmsounding(){
	time_t timestar;
	ifttt("https://maker.ifttt.com/trigger/alarm_triggered/with/key/dcZuaJf3oHEAyHhu-55bJE", "my1", "my 2", "my 33333");
	while(1){
    timestar = time(NULL);
    while(difftime(time(NULL), timestar) <= 2 && digitalRead(3) == 1){
      digitalWrite (1, HIGH) ;
      digitalWrite (2, HIGH) ;
      digitalWrite (4, HIGH) ;
    }
    while(digitalRead(3) == 0){
	    toalarmoff();  
	    return;
    }
	
    timestar = time(NULL);

    while(difftime(time(NULL), timestar) <= 2 && digitalRead(3) == 1){
      digitalWrite (1, LOW) ;
      digitalWrite (2, LOW) ;
      digitalWrite (4, LOW) ;
    }
	  while(digitalRead(3) == 0){
	    toalarmoff();  
	    return;
	  }
	}

}