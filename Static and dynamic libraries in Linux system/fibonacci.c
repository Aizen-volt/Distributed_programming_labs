#include "fibonacci.h"

int fibonacci(int a) {
    if (a <= 2) {
        return 1;
    }
    return fibonacci(a-1) + fibonacci(a-2);
}