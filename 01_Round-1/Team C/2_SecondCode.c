#include<stdio.h>

int main() {
    int arr[] = {10, 5, 30, 25, 15}, n = 5, max;
    max = 0;
    for(int i = 1; i <= n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    printf("The maximum element is %f", max);
    return 0;
}
