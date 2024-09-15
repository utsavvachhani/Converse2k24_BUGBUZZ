#include<stdio.h>

int main() {
    char str[] = "madam";
    int len = strlen(str);
    int i, isPalindrome = 1;

    for(i = 0; i <= len / 2; i++) {
        if(str[i] != str[len - i]) {
            isPalindrome = 0;
            break;
        }
    }

    if(isPalindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}
