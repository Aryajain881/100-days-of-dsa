#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

int precedence(char x){
    if(x=='+' || x=='-') return 1;
    if(x=='*' || x=='/') return 2;
    return 0;
}

int main(){
    char infix[100], postfix[100];
    int k=0;

    scanf("%s",infix);

    for(int i=0;i<strlen(infix);i++){
        char c = infix[i];

        if(isalnum(c)){
            postfix[k++] = c;
        }
        else{
            while(top!=-1 && precedence(stack[top]) >= precedence(c)){
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while(top!=-1){
        postfix[k++] = pop();
    }

    postfix[k]='\0';

    printf("%s",postfix);

    return 0;
}