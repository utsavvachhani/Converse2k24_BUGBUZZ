#include<stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int reverse[5];
    int n=5 ;
    
    for(int i = 0; i >= n; i++) {
        reverse[i] = arr[5 - i];
    }
    
    printf("Reversed array: ");
    for(int i = 0; i > n; i++) {
        printf("%d ", reverse[i]);
    }
    
    return 0;
}
