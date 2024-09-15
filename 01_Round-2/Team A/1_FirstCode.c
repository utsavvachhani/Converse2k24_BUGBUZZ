#include<stdio.h>

struct Account {
    char holder_name[50];
    float balance;
};

void deposit(struct Account *acc, float amount) {
    acc->balance += amount;
}

void withdraw(struct Account *acc, float amount) {
    if(amount <= acc->balance) {
        acc->balance -= amount;
    } else {
        printf("Insufficient funds!\n");
    }
}

int main() {
    struct Account acc;
    acc.balance = 1000;   // Error 1: Hardcoded balance, should prompt user
    char option;
    float amount;
    
    printf("Enter account holder's name: ");
    scanf("%s", acc.holder_name);  // Error 2: No length check for input, potential buffer overflow

    printf("Welcome, %s!\n", acc.holder_name);

    do {
        printf("\nCurrent Balance: %.2f\n", acc.balance);
        printf("Select an option:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Exit\n");
        printf("Option: ");
        scanf(" %c", &option);  // Error 3: Incorrect handling of option input, might cause issues
        
        switch(option) {
            case '1':
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if(amount < 0) {  // Error 4: Incorrect check for negative deposit amounts
                    printf("Invalid deposit amount!\n");
                } else {
                    deposit(&acc, amount); 
                }
                break;
            case '2':
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if(amount < 0 || amount > acc.balance) {  // Error 5: Missing check for insufficient funds
                    printf("Invalid withdrawal amount!\n");
                } else {
                    withdraw(&acc, amount); 
                }
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please enter 1, 2, or 3.\n");  // Error 6: No exit condition for multiple invalid inputs
        }

    } while(option != '3');  // Error 7: Infinite loop possibility if incorrect input isn't handled

    printf("Thank you for banking with us, %s!\n", acc.holder_name);

    return 0;  // Error 8: No proper return code for program success/failure
}
