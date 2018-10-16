#include <stdio.h>
#include <assert.h>

unsigned rotate_left(unsigned x, int n)
{
    unsigned y = x << n;
    unsigned w = sizeof(unsigned) << 3;
    unsigned mask = x >> (w - (n + 1)) >> 1;
    return y | mask;
}

int main(int argc, char const *argv[])
{
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);
    assert(rotate_left(0x12345678, 0) == 0x12345678);
}
