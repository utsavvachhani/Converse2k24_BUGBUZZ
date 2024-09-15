#include<stdio.h>

#define MAX 50

struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, int value) {
    if (stack->top == MAX) {  // Error 1: Boundary condition should be `>= MAX - 1`
        printf("Stack overflow\n");
    } else {
        stack->items[stack->top++] = value;  // Error 2: Incorrect increment operator position
    }
}

int pop(struct Stack *stack) {
    if (stack->top == -1) {
        return -1;  // Error 3: Pop shouldn't return -1 without explicit handling
    }
    return stack->items[stack->top];  // Error 4: Top value is returned without decrement
}

void reverseArray(int arr[], int size) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; i < size; i++) {
        push(&stack, arr[i]);
    }

    for (int i = 0; i < size; i++) {
        arr[i] = pop(&stack);  // Error 5: Potential underflow if stack isn't handled correctly
    }
}

int main() {
    int arr[MAX], n;
    printf("Enter number of elements: ");
    scanf("%d", n);  // Error 6: Missing `&` for scanf input
    
    if (n > MAX) {  // Error 7: No check for negative values of n
        printf("Invalid input.\n");
        return -1;
    }
    
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, n);

    printf("Reversed Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
