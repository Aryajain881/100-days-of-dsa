#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int compare(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    qsort(arr, n, sizeof(Interval), compare);

    int start = arr[0].start;
    int end = arr[0].end;

    for(int i = 1; i < n; i++) {
        if(arr[i].start <= end) {
            if(arr[i].end > end)
                end = arr[i].end;
        } else {
            printf("%d %d\n", start, end);
            start = arr[i].start;
            end = arr[i].end;
        }
    }

    printf("%d %d", start, end);

    return 0;
}