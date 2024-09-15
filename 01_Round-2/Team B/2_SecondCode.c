#include<stdio.h>

#define MAX 50

struct Stack {
    int data[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = 0;  // Error 1: Incorrect initialization, should be `-1`
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

void push(struct Stack *s, int value) {
    if (!isFull(s)) {
        s->data[s->top] = value;
        s->top++;  // Error 2: Stack overflow not handled properly
    }
}

int pop(struct Stack *s) {
    if (s->top == 0) {  // Error 3: Should check if `s->top == -1`
        printf("Stack underflow!\n");
        return -1;  // Error 4: Returning -1 might clash with valid stack values
    }
    return s->data[s->top--];  // Error 5: Post-decrement may cause returning invalid value
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {  // Error 6: Incorrect condition, should be `>`
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);  // Error 7: Missing validation for n being negative or zero

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
