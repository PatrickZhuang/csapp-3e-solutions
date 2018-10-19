#include <stdio.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    int maxbytes = 3;
    // 关键点：signed 和unsigned进行计算 sign类型会转换成unsigned类型。所以无论maxbytes值为多少，maxbytes - sizeof(int)结果都会大于等于0
    assert(maxbytes - sizeof(int) >= 0);
    printf("unsigned value: %lx\t%lu\n", maxbytes - sizeof(int), maxbytes - sizeof(int));
    printf("signed value: %lx\t%d\n", maxbytes - sizeof(int), maxbytes - (int)sizeof(int));
    return 0;
}
