//addition of two matrices having the same dimensions:

#include <stdio.h>

int main() {
    int m, n;

    // Input number of rows and columns
    scanf("%d %d", &m, &n);

    int matrix1[m][n], matrix2[m][n], sum[m][n];

    // Input first matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input second matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Addition of matrices
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print resultant matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
