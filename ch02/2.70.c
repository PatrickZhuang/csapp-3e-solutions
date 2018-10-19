#include <stdio.h>
#include <assert.h>

int fits_bits(int x, int n)
{
    size_t w = sizeof(int) << 3;
    int offset = w - n;
    return (x << offset >> offset) == x;
}

int main(int argc, char const *argv[])
{
    assert(fits_bits(7, 4) == 1);
    assert(fits_bits(8, 4) == 0);
    return 0;
}
