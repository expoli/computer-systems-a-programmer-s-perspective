#include <stdio.h>
#include "limits.h"

/**
 * Determine whether arguments can be added without overflow
 * @param x
 * @param y
 * @return
 */
int tadd_ok(int x, int y) {
    int s = x + y;
    if (x < 0 && y < 0 && s >= 0)
        return 0;
    if (x > 0 && y > 0 && s <= 0)
        return 0;
    return 1;
}

/**
 * Determine whether arguments can be subtracted without overflow
 * WARNING: This code is buggy
 * @param x
 * @param y
 * @return
 */
int tsub_ok(int x, int y) {
    return tadd_ok(x, -y);
}

/**
 * When y is the INT_MIN this function will work wrong.
 * @return
 */
int main() {
    printf("%d\n", tsub_ok(INT_MIN, 1));
    printf("%d\n", tsub_ok(0, INT_MIN));
    return 0;
}
