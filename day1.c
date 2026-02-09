#include <stdio.h>

int main() {
    int n, pos, x;
    int arr[100];

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position and element
    printf("Enter position (1-based): ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    // Check valid position
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return 0;
    }

    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element
    arr[pos - 1] = x;
    n++;

    // Print updated array
    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
