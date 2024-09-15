#include<stdio.h>

struct Employee {
    char name[50];
    int age;
    float salary;
};

void displayEmployee(struct Employee e) {
    printf("\nEmployee Details:\n");
    printf("Name: %s\n", e.name);
    printf("Age: %d\n", e.age);
    printf("Salary: %.2f\n", e.salary);
}

void increaseSalary(struct Employee *e, float increment) {
    if(increment < 0) {  // Error 1: Missing check for negative increment
        printf("Error: Increment must be positive.\n");
    } else {
        e->salary += increment;
    }
}

int main() {
    struct Employee emp;
    
    printf("Enter employee name: ");
    scanf("%s", emp.name);  // Error 2: No length check for input, potential buffer overflow
    
    printf("Enter employee age: ");
    scanf("%d", &emp.age);
    
    if(emp.age < 18 || emp.age > 65) {  // Error 3: Arbitrary age limits without explanation
        printf("Error: Invalid age.\n");
        return -1;  // Error 4: Return code without proper exit handling
    }

    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);
    
    if(emp.salary < 0) {  // Error 5: No real-world salary validation
        printf("Error: Invalid salary.\n");
        return -1;
    }

    displayEmployee(emp);

    char choice;
    float increment;

    printf("Do you want to increase salary (y/n)? ");
    scanf(" %c", &choice);  // Error 6: No validation for input other than 'y' or 'n'

    if(choice == 'y') {
        printf("Enter increment amount: ");
        scanf("%f", increment);  // Error 7: Missing & before `increment`
        increaseSalary(&emp, increment);  // Error 8: Passing uninitialized `increment`
    } else if(choice != 'n') {
        printf("Invalid input! Exiting.\n");
    }

    displayEmployee(emp);

    return 0;
}
