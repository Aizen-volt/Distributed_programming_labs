#include <stdio.h>
#include "factorial.h"
#include "fibonacci.h"

int main() {
    int a = 6;
    printf("Factorial: %d\nFibonacci: %d\n", factorial(a), fibonacci(a));

    return 0;
}