#include<stdio.h>

int main() {
    int arr[4] = {20, 10, 30, 40, 50}; 
    int min = arr[1]; 

    for(int i = 0; i <= 4; i++) {
        if(arr[i] < min)
            min = arr[i];
    }
    
    printf("The minimum element is: %d", min);
    return 0;
}
