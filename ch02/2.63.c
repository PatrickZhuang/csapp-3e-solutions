#include <stdio.h>
#include <limits.h>

unsigned srl(unsigned x, int k)
{
    /* Performs shift arithmetically */
    unsigned xsra = (int)x >> k;
    size_t w = sizeof(int) * 8;
    int mask = (1 << (w - k)) - 1;
    return xsra & mask;
}

unsigned sra(int x, int k)
{
    /* Performs shift logically */
    int xsrl = (unsigned)x >> k;
    size_t w = sizeof(int) << 3;
    int mask = -1 << (w - k);
    /* Most significant bit */
    int msb = !(x & (INT_MIN)) - 1;
    printf("%x\n", mask);
    mask &= msb;
    printf("msb:%x\t%x\t%x\n", msb, mask, xsrl);
    // TODO
    return xsrl | mask;
}

int main(int argc, char const *argv[])
{
    printf("逻辑右移: %x\n", srl(0xff, 2));
    printf("算术右移: %x\n", sra(15, 1));
    return 0;
}