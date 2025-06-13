#include <stdio.h>
#include <stdlib.h>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

int main(int argc, char const* argv[]) {
    printf("hello world!\n%s\n%s\n", TOSTRING(OS), TOSTRING(MO));

    return EXIT_SUCCESS;
}
