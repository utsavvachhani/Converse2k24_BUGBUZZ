#include<stdio.h>

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack->arr[++stack->top] = value; 
    }
}

int pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int findMin(struct Stack *stack) {
    int min = stack->arr[0];  // Error 1: No check for empty stack
    for (int i = 1; i <= stack->top; i++) {
        if (stack->arr[i] > min) {  // Error 2: Incorrect condition, should be `<`
            min = stack->arr[i];
        }
    }
    return min;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Stack stack;
    initStack(&stack);

    int n, arr[MAX];
    printf("Enter number of elements: ");
    scanf("%d", n);  // Error 3: Missing `&` in scanf

    if (n > MAX || n < 0) {  // Error 4: No error message for invalid n
        return -1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        push(&stack, arr[i]);  // Error 5: No check if stack is full
    }

    bubbleSort(arr, n);  // Error 6: Sorting won't affect the stack
    int minVal = findMin(&stack);  // Error 7: Stack might be empty or contain erroneous values

    printf("Minimum value in stack: %d\n", minVal);

    return 0;
}
