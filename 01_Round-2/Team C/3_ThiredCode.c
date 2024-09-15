#include<stdio.h>
#include<math.h>

#define MAX 50

struct Queue {
    int arr[MAX];
    int front, rear;
};

// Initialize the queue
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;  // Error 1: Returning -1 might clash with legitimate values in queue
    } else {
        int value = q->arr[q->front];
        q->front++;
        if (q->front > q->rear) {  // Error 2: Incorrect logic to reset the queue
            q->front = q->rear = -1;
        }
        return value;
    }
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else if (n < 0) {  // Error 3: Factorial for negative numbers isn't defined
        return 1;  // Error 4: Incorrect return value for negative input
    }
    return n * factorial(n - 1);
}

int main() {
    struct Queue q;
    initQueue(&q);

    int num;
    printf("Enter a number for factorial: ");
    scanf("%d", num);  // Error 5: Missing `&` in scanf

    enqueue(&q, num);

    int result = factorial(num);
    printf("Factorial of %d is %d\n", num, result);

    printf("Dequeuing: %d\n", dequeue(&q));  // Error 6: No validation if queue is empty

    return 0;
}
