#include<stdio.h>

void sortArray(int arr[], int size) {
    int temp;
    for(int i = 0; i <= size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[5];
    for(int i = 0; i <= 5; i++) {
        arr[i] = i + 1;
    }
    
    sortArray(arr, 5);
    
    printf("Sorted array: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
