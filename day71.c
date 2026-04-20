#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define EMPTY -1
void insert(int table[], int m, int key) {
    int h_k = key % m, i;
    for(i=0; i<m; i++)
    { int pos = (h_k + i * i) % m;
      if(table[pos] == EMPTY)
      { table[pos] = key;
        return;
      }
    }
}
void search(int table[], int m, int key) {
    int h_k = key % m, i;
    for(i=0; i<m; i++)
    { int pos = (h_k + i * i) % m;
      if(table[pos] == key)
      { printf("FOUND\n");
        return;
      }
      if(table[pos] == EMPTY) break;
    }
    printf("NOT FOUND\n");
}
int main() {
    int m, n, i;
    if(scanf("%d %d", &m, &n) != 2) return 0;
    int *table = (int *)malloc(m * sizeof(int));
    for(i=0; i<m; i++) table[i] = EMPTY;
    char op[10];
    int val;
    for(i=0; i<n; i++)
    { scanf("%s %d", op, &val);
      if(strcmp(op, "INSERT") == 0)
      { insert(table, m, val); }
      else if (strcmp(op, "SEARCH") == 0)
      { search(table, m, val); }
    }
    free(table);
    return 0;
}
