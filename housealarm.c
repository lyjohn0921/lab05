#include <wiringPi.h>
#include <stdio.h>
#include <time.h>

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
  while (digitalRead(3)){
    toalarming();
    return;
  }
}

void toalarming(){
  time_t timestar;
  timer = time(NULL);
  while(difftime(timer,time(NULL)) < 10.00 ){
    for (i=0;i<10;i++) {
    digitalWrite (1, HIGH) ; delay (500) ;
    digitalWrite (1,  LOW) ; delay (500) ;
  }
    digitalWrite (2, HIGH) ;
    digitalWrite (1,  LOW) ;
  }
  toalarmed();
}
void toalarmed() {
  while (digitalRead(3) == 0){
    
    while(digitalRead(0) == 1){
      totriffered();
      return;
    }
    
  }
  toalarmoff();
}

void totriggered(){
  time_t timestar;
  timer = time(NULL);
  while(difftime(timer,time(NULL)) < 10.00){
    
    while(digitalRead(3) == 0){
      digitalWrite (1, HIGH) ; 
      digitalWrite (2, HIGH) ;
      digitalWrite (1,  LOW) ;
      digitalWrite (2,  LOW) ;
      delay(2000);
    }
    toalarmoff();
    return;
  }
  toalarmsounding();
}

void toalarmsounding(){
  
  while(digitalRead(3) == 0){
    digitalWrite (1, HIGH) ;
    digitalWrite (2, HIGH) ;
    digitalWrite (4, HIGH) ;
    delay(2000);
    digitalWrite (1, LOW) ;
    digitalWrite (2, LOW) ;
    digitalWrite (4, LOW) ;
  }
  toalarmoff();
}