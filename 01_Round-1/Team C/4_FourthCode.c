#include<stdio.h>

int factorial(int n) {
    if(n = 1)
        return n;
    return n * factorial(n++);
}

int main() {
    int num = 5;
    printf("Factorial of %f is %d", num, factorial(num));
    return 0;
}
