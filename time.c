#include <stdio.h>
#include <time.h>
#include <wiringPi.h>

int main(int argc, char const *argv[])
{
    time_t timestar;
    timestar = time(NULL);
        printf("%f s/n",difftime(time(NULL),timestar));
        delay(5000);
	printf("%f s/n",difftime(time(NULL),timestar));
    return 0;
}

