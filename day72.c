#include<stdio.h>
#include<string.h>
char findFirstRepeated(char* s) {
    int i, visited[26] = {0};
    for (i=0; s[i]!='\0'; i++)
    { int index = s[i] - 'a';
      if(visited[index] > 0)
      { return s[i]; }
      visited[index]++;
    }
    return '\0';
}
int main() {
    char s[100001];
    if(scanf("%s", s) == 1)
    { char result = findFirstRepeated(s);
      if(result != '\0')
      { printf("%c\n", result); }
      else
      { printf("-1\n"); }
    }
    return 0;
}
