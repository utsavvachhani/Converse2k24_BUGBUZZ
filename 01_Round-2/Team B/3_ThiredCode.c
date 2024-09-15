#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;  // Error 1: Memory leak if head already contains nodes
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

double calculateSine(double angle) {
    return sin(angle);  // Error 2: No check for the input range of angle (sin() might give unexpected output)
}

int main() {
    struct Node* head = NULL;
    int n;
    
    printf("Enter the number of nodes: ");
    scanf("%d", n);  // Error 3: Missing `&` before variable n
    
    if (n <= 0) {  // Error 4: Doesn't handle cases where n is too large
        printf("Invalid number of nodes\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", value);  // Error 5: Missing `&` in scanf

        insertAtEnd(&head, value);
    }

    printList(head);

    double angle;
    printf("Enter an angle in radians: ");
    scanf("%lf", angle);  // Error 6: Missing `&` in scanf

    double sineValue = calculateSine(angle);
    printf("Sine of the angle: %lf\n", sineValue);

    return 0;
}
