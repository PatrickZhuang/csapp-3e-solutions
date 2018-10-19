#include <stdio.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    int x = 10;
    assert(x * 17 == (x << 4) + x);
    assert(x * -7 == (x - (x << 3)));
    assert(x * 60 == (x << 6) - (x << 2));
    assert(x * -112 == (x << 4) - (x << 7));
    return 0;
}
