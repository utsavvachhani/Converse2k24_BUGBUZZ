#include<stdio.h>

int main() {
    int mat[2][3] = {1, 2, 3, 4, 5}; 
    int max = mat[0][0];

    for(int i = 0; i <= 2; i++) {
        for(int j = 0; j < 3; j++) {
            if(mat[i][j] > maximum)
                maximum = mat[i][j];
        }
    }

    printf("The largest element is: %d", max);
    return 0;
}
