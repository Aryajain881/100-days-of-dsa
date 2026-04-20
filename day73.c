#include<stdio.h>
#include<string.h>
char firstNonRepeating(char* s) {
    int char_count[256] = {0};
    int i, n = strlen(s);
    for(i=0; i<n; i++)
    { char_count[(unsigned char)s[i]]++; }
    for(i=0; i<n; i++)
    { if(char_count[(unsigned char)s[i]] == 1)\
      { return s[i]; }
    }
    return '$';
}
int main() {
    char s[] = "geeksforgeeks";
    printf("%c", firstNonRepeating(s));
    return 0;
}
