#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100], merged[200];
    int i = 0, j = 0, k = 0;

    
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            merged[k++] = a[i++];
        } else {
            merged[k++] = b[j++];
        }
    }

    while (i < p) {
        merged[k++] = a[i++];
    }

    
    while (j < q) {
        merged[k++] = b[j++];
    }

    
    for (int i = 0; i < k; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
