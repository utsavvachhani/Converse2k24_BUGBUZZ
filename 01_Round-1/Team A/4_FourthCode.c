#include<stdio.h>

int main() {
    int sum,j;
    int i=5;

    while(i!=5){
        if(j % 2 != 0) {
            sum += j;
        }
    }

    printf("Sum of first five even numbers : %d", sum);
    return 0;
}
