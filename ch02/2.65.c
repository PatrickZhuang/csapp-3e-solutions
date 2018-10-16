#include <stdio.h>

int odd_ones(unsigned x);

int main(int argc, char const *argv[])
{
    printf("%x\n", odd_ones(0x10101011));
    return 0;
}

int odd_ones(unsigned x)
{
    printf("%x\n", x);
    x ^= x >> 16;
    printf("%x\n", x);
    x ^= x >> 8;
    printf("%x\n", x);
    x ^= x >> 4;
    printf("%x\n", x);
    x ^= x >> 2;
    printf("%x\n", x);
    x ^= x >> 1;
    printf("%x\n", x);
    x &= 0x1;
    return x;
}
