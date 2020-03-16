// Write a C program that calls an add function(long add(long a, long b).

#include <stdio.h>

long add(long a, long b){
    int result = a + b;
    return result;
}

int main() {
    long numOne = 3;
    long numTwo = 4;
    printf("%d\n", add(3, 4));
    return 0;
}
