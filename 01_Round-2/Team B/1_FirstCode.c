#include<stdio.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

void displayStudent(struct Student s) {
    printf("\nStudent Details:\n");
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Marks: %.2f\n", s.marks);
}

void updateMarks(struct Student *s, float new_marks) {
    if(new_marks < 0 || new_marks > 100) {  // Error 1: Incorrect boundary check, should include exact values
        printf("Error: Marks should be between 0 and 100.\n");
    } else {
        s->marks = new_marks;
    }
}

int main() {
    struct Student s1;
    
    printf("Enter student name: ");
    scanf("%s", s1.name);  // Error 2: No length check for input, potential buffer overflow
    
    printf("Enter student age: ");
    scanf("%d", &s1.age);  // Error 3: No validation for age, should be within realistic range
    
    printf("Enter student marks: ");
    scanf("%f", &s1.marks);
    
    if(s1.marks < 0 || s1.marks > 100) {  // Error 4: Incorrect condition for checking marks
        printf("Error: Invalid marks entered.\n");
        return -1;
    }

    displayStudent(s1);

    char choice;
    float new_marks;

    printf("Do you want to update marks (y/n)? ");
    scanf(" %c", &choice);  // Error 5: No validation for choice input
    
    if(choice == 'y') {
        printf("Enter new marks: ");
        scanf("%f", new_marks);  // Error 6: Missing & before `new_marks`
        updateMarks(&s1, new_marks);  // Error 7: Passing uninitialized `new_marks`
    } else if(choice != 'n') {
        printf("Invalid input! Exiting.\n");
    }

    displayStudent(s1);

    return 0;  // Error 8: No proper return code for program success/failure
}
