#include<stdio.h>

int fibonacci(int n) {
    int i, first = 0, second = 1;
    for(i = 0; i < n; i++) {
        int next;
        next = first + second;
        first = second;
        second = next;
    }
    return next;
}

int main() {
    int n = 10;
    printf("Fibonacci number at position %f: %d", n, fibonacci(n));
    return 0;
}
