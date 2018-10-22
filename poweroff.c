#include <wiringPi.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    wiringPiSetup () ;
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    return 0;
}
