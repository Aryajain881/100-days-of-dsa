#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100003
typedef struct Node {
    int sum;
    int index;
    struct Node* next;
} Node;
Node* hash_table[MAX_SIZE];
int hash(int sum) {
    int h = sum % MAX_SIZE;
    return (h < 0) ? (h + MAX_SIZE) : h;
}
void insert(int sum, int index) {
    int h = hash(sum);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hash_table[h];
    hash_table[h] = newNode;
}
int find(int sum) {
    int h = hash(sum);
    Node* entry = hash_table[h];
    while (entry)
    { if(entry->sum == sum) return entry->index;
      entry = entry->next;
    }
    return -2;
}
int maxLen(int arr[], int n) {
    int max_len = 0, curr_sum = 0, i;
    for(i=0; i<MAX_SIZE; i++)
    { hash_table[i] = NULL; }
    for(i=0; i<n; i++)
    { curr_sum += arr[i];
      if(curr_sum == 0)
      { max_len = i + 1; }
      int prev_index = find(curr_sum);
      if(prev_index != -2)
      { if(max_len < (i - prev_index))
        { max_len = i - prev_index; }
      }
      else
      { insert(curr_sum, i); }
    }
    return max_len;
}
int main()
{
    int n, i;
    if(scanf("%d", &n) != 1) return 0;
    int arr[n];
    for(i=0; i<n; i++)
    { scanf("%d", &arr[i]); }
    printf("%d\n", maxLen(arr, n));
    return 0;
}
