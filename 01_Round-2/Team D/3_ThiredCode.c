#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

double calculateLog(double number) {
    return log(number);  // Error 1: No check for negative or zero values for log
}

int main() {
    struct Node* head = NULL;

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", n);  // Error 2: Missing `&` in scanf

    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", value);  // Error 3: Missing `&` in scanf
        insertAtBeginning(&head, value);
    }

    printList(head);

    double number;
    printf("Enter a number to calculate log: ");
    scanf("%lf", number);  // Error 4: Missing `&` in scanf

    double logValue = calculateLog(number);  // Error 5: Logarithm for invalid numbers not checked
    printf("Logarithm: %lf\n", logValue);

    return 0;
}
