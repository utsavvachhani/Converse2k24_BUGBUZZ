#include<stdio.h>
#include<string.h>

struct Book {
    char title[100];
    char author[50];
    int pages;
    float price;
};

void displayBook(struct Book b) {
    printf("\nBook Details:\n");
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Pages: %d\n", b.pages);
    printf("Price: %.2f\n", b.price);
}

void updatePrice(struct Book *b, float new_price) {
    if(new_price <= 0) {  // Error 1: Price can’t be zero or negative
        printf("Error: Price must be greater than zero.\n");
    } else {
        b->price = new_price;
    }
}

int main() {
    struct Book book1;
    
    strcpy(book1.title, "The Catcher in the Rye");
    strcpy(book1.author, "J.D. Salinger");  // Error 2: Potential buffer overflow without size check
    
    book1.pages = 234;
    book1.price = 15.99;

    displayBook(book1);

    char choice;
    float new_price;

    printf("Do you want to update the price (y/n)? ");
    scanf(" %c", &choice);  // Error 3: No validation for choice input

    if(choice == 'y') {
        printf("Enter new price: ");
        scanf("%f", &new_price);
        
        if(new_price < 10) {  // Error 4: Arbitrary limit on price update, no real check
            printf("Error: Price too low.\n");
        } else {
            updatePrice(&book1, new_price); 
        }
    } else if(choice != 'n') {
        printf("Invalid input! Exiting.\n");  // Error 5: No handling of unexpected input
    }

    displayBook(book1);  // Error 6: Re-displays book even if input was invalid

    printf("Exiting...\n");  // Error 7: Program doesn't confirm successful price update
    return 0;  // Error 8: No proper return code for program success/failure
}
