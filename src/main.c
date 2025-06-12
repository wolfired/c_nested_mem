#include <stdio.h>
#include <stdlib.h>

#include "sun.h"

int main(int argc, char const* argv[]) {
    // for stack obj
    Sun s0;
    sun_init(&s0);
    sun_ctor(&s0, 8);
    sun_dtor(&s0);

    // for heap obj
    Sun* s1 = sun_new(8);
    sun_free(&s1);

    Sun* s2 = NULL;
    sun_make(&s2, 8);
    sun_free(&s2);

    return EXIT_SUCCESS;
}
