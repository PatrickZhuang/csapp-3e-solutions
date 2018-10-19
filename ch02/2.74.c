#include <stdio.h>
#include <assert.h>
#include <limits.h>

int tsub_ok(int x, int y)
{
    int sub = x - y;
    int mask = INT_MIN;
    // y == INT_MIN 正溢出 -INT_MIN == INT_MIN
    // x > 0, y < 0 sub < 0 正溢出
    // x < 0, y > 0 sub > 0 负溢出
    int overflow = y == INT_MIN;
    int pos_over = !(x & mask) && (y & mask) && (sub & mask);
    int neg_over = (x & mask) && !(y & mask) && !(sub & mask);
    return !(overflow || pos_over || neg_over);
}

int main(int argc, char const *argv[])
{
    assert(tsub_ok(INT_MAX, 1) == 1);
    assert(tsub_ok(INT_MAX, -1) == 0);
    assert(tsub_ok(INT_MIN, -1) == 1);
    assert(tsub_ok(INT_MIN, 1) == 0);
    return 0;
}
