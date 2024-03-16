#include <stdio.h>
#include "NWD.h"
#include "NWW.h"

int main() {
    int a = 6, b = 4;
    printf("NWD: %d\nNWW: %d\n", NWD(a, b), NWW(a, b));

    return 0;
}