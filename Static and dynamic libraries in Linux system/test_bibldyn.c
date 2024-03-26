#include <stdio.h>
#include "NWD.h"
#include "NWW.h"
#include "factorial.h"
#include "fibonacci.h"

int main() {
    int a = 6, b = 4;
    printf("NWD(%d, %d): %d\nNWW(%d, %d): %d\nFactorial(%d): %d\nFibonacci(%d): %d\n" , a, b, NWD(a, b), a, b, NWW(a, b), a, factorial(a), b, fibonacci(b));

    return 0;
}