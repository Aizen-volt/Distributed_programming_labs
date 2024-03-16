#include "NWW.h"
#include "NWD.h"

int NWW(int a, int b) {
    return a / NWD(a, b) * b;
}