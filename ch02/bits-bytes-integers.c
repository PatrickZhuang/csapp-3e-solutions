//
//  bits-bytes-integers.c
//  csapp
//
//  Created by Patrick on 2018/10/10.
//  Copyright © 2018 Patrick. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <math.h>
typedef unsigned char * pointer;

void show_bytes(pointer pointer, size_t len) {
    for (int i = 0; i < len; i++) {
        printf("%p\t%.2x\n", pointer + i, pointer[i]);
    }
    printf("\n");
}

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int is_little_endian() {
    unsigned short a = 1;
    unsigned char * p = (unsigned char *)&a;
    return p[0] == a;
}

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    unsigned char * p = (unsigned char *) &x;
    if (i >= 0 && i < sizeof(x)) {
        p[i] = b;
    }
    return x;
}

int int_shifts_are_arithmetic(void);

int main(int argc, const char * argv[]) {
    int a = 3;
    int b = ~a;
    printf("a: %d\n", a);
    printf("~a: %d\n", b);
    printf("%d\n", -a -1 == b);
    
    show_bytes((pointer) &a, sizeof(int));
    show_bytes((pointer) &b, sizeof(int));
    
    const char * str = "Hello World!\n";
    printf("%s", str);
    str = "Hello C!\n";
    printf("%s", str);
    
    int t_min = INT_MIN;
    printf("%d\t%d\n", t_min, (t_min+1)*2);
    
    printf("----无符号表示转补码表示----\n");
    unsigned char unsigned_a = -5;
    char signed_a = (char)unsigned_a;
    printf("unsigned_a: %d\nsigned_a: %d\n", unsigned_a, signed_a);
    printBits(sizeof(unsigned_a), &unsigned_a);
    printBits(sizeof(signed_a), &signed_a);
    
    printf("----float表示转补码表示----\n");
    float float_a = 5;
    int int_a = (int)float_a;
    printf("float_a: %f\nint_a: %d\n", float_a, int_a);
    printBits(sizeof(float_a), &float_a);
    printBits(sizeof(int_a), &int_a);
    
    printf("\n生成k位1111的掩码\n");
    short mask_a = (1 << 4) - 1;
    printBits(sizeof(mask_a), &mask_a);
    
    printf("----判断当前机器为大端序还是小端序----\n");
    printf("当前机器字节序为：%s\n", is_little_endian() == 1 ? "小端序":"大端序");
    
    int origin_bytes = 0x12345678;
    printf("origin_bytes: %X\ndest_bytes: %X\n", origin_bytes, replace_byte(origin_bytes, 1, 0xAB));
    
    printf("----当前机器右移是算术右移？---- %d\n", int_shifts_are_arithmetic());
    
    int right_shifts_origin = -1;
    int right_shifts_dest = right_shifts_origin >> 1;
    printBits(sizeof(int), &right_shifts_origin);
    printBits(sizeof(int), &right_shifts_dest);
    
}


int int_shifts_are_arithmetic() {
    return -1 >> 1 == -1;
}
