#include<stdio.h>
#include<string.h>

#define MAX 50

struct Stack {
    char arr[MAX];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, char ch) {
    if (stack->top == MAX - 1) {
        printf("Stack full\n");
    } else {
        stack->arr[stack->top];  // Error 1: Missing increment before assigning
    }
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack empty\n");
        return '\0';  // Error 2: Null char return might be confusing in some cases
    }
    return stack->arr[stack->top--];
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }

    for (int i = 0; i < len; i++) {
        char ch = pop(&stack);
        if (str[i] != ch) {  // Error 3: Comparison without checking if `ch` is valid
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);  // Error 4: No length validation, might overflow buffer

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
