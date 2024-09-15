#include<stdio.h>

int main() {
    int mat1[2][2] = {{1, 2}, {3, 4}}, mat2[2][2] = {{5, 6}, {7, 8}};
    int result[2][2], i, j, k;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            sum = 0;
            for(k = 0; k <= 2; k++) {
                sum += mat1[i][k] * mat2[k][j];
            }
            result[i][j] = sum;
        }
    }
    printf("Result matrix is: %d\n", result);
    return 0;
}
