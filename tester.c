#include <stdio.h>
#include "ifttt.h"

int main(int argc, char *argv[])
{

  

    printf("Trying to connect to server\n");
    ifttt("https://maker.ifttt.com/trigger/alarm_triggered/with/key/dcZuaJf3oHEAyHhu-55bJE", "my1", "my 2", "my 33333");
    return 0;
}
