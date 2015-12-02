#include <stdio.h>
#include <stdlib.h>
#include "HsFFI.h"
#include "Foo_stub.h"

HsBool hask_init(void)
{
    int argc = 0;
    char *argv[] = { NULL } ; // { "+RTS", "-A1G", "-H1G", NULL };
    char **pargv = argv;

    hs_init(&argc, &pargv);

    return HS_BOOL_TRUE;
}

void hask_end(void)
{
    hs_exit();
}

void go(int i)
{
    printf("#%d - Launching RTS...\n", i);
    hask_init(); // starts the RTS
    printf("#%d - RTS started! Calling Haskell function...\n", i);
    // 'f' is the Haskell function exported to C
    f(i);
    printf("#%d - Killing RTS now...\n", i);
    hask_end(); // kills the RTS
    printf("#%d - RTS killed!\n", i);
}

int main(int argc, char** argv)
{
    setbuf(stdout, NULL);

    go(0); go(1);

    return 0;
}
           
