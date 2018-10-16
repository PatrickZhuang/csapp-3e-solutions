#include <stdio.h>
#include <limits.h>

int tadd_ok(int x, int y) {
    int sum = x + y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x >= 0 && y >= 0 && sum < 0;
    
    return !neg_over && !pos_over;
}

int tsub_ok(int x, int y) {
    return tadd_ok(x, -y);
}
int main() {
    int x = 1;
    int y = INT_MIN;
    printf("INT_MAX: %d\n", INT_MAX);
    printf("INT_MIN: %d\n", INT_MIN);
    printf("-INT_MIN: %d\n", -INT_MIN);
    
    tsub_ok(x,y);
}
