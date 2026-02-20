#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum[100000] = {0}; 
    int sum = 0, count = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            count++;

        if (prefixSum[sum] > 0)
            count += prefixSum[sum];

        prefixSum[sum]++;
    }

    printf("%d\n", count);
    return 0;
}