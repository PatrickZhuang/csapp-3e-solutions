#include <stdio.h>
#include <assert.h>

int lower_one_mask(int n)
{
    int w = sizeof(int) << 3;
    int mask = (unsigned) -1 >> (w -n);
    // 或者这样也可以, note：分两次<< 是因为C没有定义左移数大于等于type width的情况。
    // int mask = (1 << (n - 1) << 1) - 1;
    return mask;
}

int main(int argc, char const *argv[])
{
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    assert(lower_one_mask(32) == 0xFFFFFFFF);
    return 0;
}
