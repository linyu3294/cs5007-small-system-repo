// Write a C program that calls an add function(long add(long a, long b).

#include <stdio.h>

long add(long x, long y){
    int result = x + y;
    return result;
}

int main() {
    long num_1 = 3;
    long num_2 = 4;
    printf("%d\n", add(3, 4));
    return 0;
}
