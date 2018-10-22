#include <stdio.h>
#include <wiringPi.h>

void inttte();
int main(){
	
	wiringPiSetup();
	pinMode(1,OUTPUT);
	pinMode(3,INPUT);
	digitalWrite(1, HIGH);
	pullUpDnControl(3, PUD_UP) ;
	delay(10000);
	wiringPiISR (3, INT_EDGE_SETUP, *inttte);
	return 0;
}
void inttte(){
        printf("interaputed");
	digitalWrite(1,LOW);
}

