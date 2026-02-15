#include <stdio.h>

int main() {
    int n, i, j;
    int a[100][100];
    int isIdentity = 1;

    
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j && a[i][j] != 1) {
                isIdentity = 0;
                break;
            }
            if (i != j && a[i][j] != 0) {
                isIdentity = 0;
                break;
            }
        }
    }

    
    if (isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
