#include<stdio.h>
#include<math.h>

#define MAX 100

struct Queue {
    int arr[MAX];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

int isFull(struct Queue *q) {
    return q->rear == MAX;  // Error 1: Boundary condition should be `MAX - 1`
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = value;  // Error 2: No check if queue is full before incrementing rear
    }
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;  // Error 3: Returning -1 might clash with legitimate values in queue
    } else {
        int value = q->arr[q->front];
        if (q->front == q->rear) {  // Error 4: Incorrect condition to reset queue
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
        return value;
    }
}

int main() {
    struct Queue q;
    initQueue(&q);

    printf("Enter a number: ");
    int num;
    scanf("%d", num);  // Error 5: Missing `&` for scanf

    double sqrtValue = sqrt(num);  // Error 6: No check for negative input to `sqrt`
    printf("Square root: %lf\n", sqrtValue);

    enqueue(&q, num);
    enqueue(&q, sqrtValue);  // Error 7: Floating-point number enqueued in an integer queue

    int dequeuedValue = dequeue(&q);
    printf("Dequeued value: %d\n", dequeuedValue);

    return 0;
}
