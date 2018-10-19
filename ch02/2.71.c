#include <stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    int shift_left_val = (3 - bytenum) << 3;
    int shift_right_val = 3 << 3;
    return (int)word << shift_left_val >> shift_right_val;
}

int main(int argc, char const *argv[])
{
    printf("%x\n", xbyte(0xAABBCCDD, 1));
}
