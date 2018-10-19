#include <stdio.h>
#include <assert.h>

int divide_power2(int x, int k)
{
    int w = sizeof(int) << 3;
    // 右移 w -1 位获得 全0或者全1的mask
    int mask = (x >> (w - 1));
    // 整数除法总是向0舍入
    // unsigned 和signed中的正数除以2的k次幂直接右移k即可
    // signed中的负数除以2的k次幂是向下舍入，需要加上偏置值bias用于向0舍入
    int bias = ((1 << k) - 1);
    bias &= mask;
    return (x + bias) >> k;
}

int main(int argc, char const *argv[])
{
    int x = 0;
    assert(divide_power2(x, 4) == 0);
    x = 31;
    assert(divide_power2(x, 4) == 1);
    x = 32;
    assert(divide_power2(x, 4) == 2);
    x = 33;
    assert(divide_power2(x, 4) == 2);
    x = -31;
    assert(divide_power2(x, 4) == -1);
    x = -32;
    assert(divide_power2(x, 4) == -2);
    x = -33;
    assert(divide_power2(x, 4) == -2);
    return 0;
}
