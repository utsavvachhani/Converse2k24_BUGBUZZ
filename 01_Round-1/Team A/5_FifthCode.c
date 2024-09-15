#include<stdio.h>

int main() {
    double number, result;
    char choice;
    
    printf("Do you want to calculate the square root (y/n)? ");
    scanf(" %c", &choice);

    if(choice = 'y') {  // Error 1: Assignment instead of comparison (should be ==)
        printf("Enter a number: ");
        scanf("%lf", number);  // Error 2: Missing & before variable `number`

        if(number < 0) {
            printf("Error: Square root of a negative number is not possible.\n");
            return 1;
        }

        // Attempting to find the square root without including math.h
        result = sqrt(number);  // Error 3: sqrt() requires <math.h>

        printf("The square root of %.2f is %.2f\n", number, result);
    } 
    else if(choice == 'n') {
        printf("Exiting the program.\n");
    } 
    else {
        printf("Invalid input.\n");  // Error 4: Missing else clause for incorrect input
    }

    if(result > 0) {  // Error 5: result is uninitialized if choice is 'n' or invalid
        printf("Program finished successfully.\n");
    }
    
    printf("Program finished. Press any key to exit.");
    getchar();  // Error 6: getchar() doesn't wait due to the previous scanf()'s newline.
    getchar();  // Another getchar() to capture newline after scanf().

    return 0;  // Error 7: Return value of 0 should be after program confirmation output.
}
