#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop(){
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main(){
    char s[200];
    fgets(s,200,stdin);

    char *token = strtok(s," ");

    while(token != NULL){
        if(isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))){
            push(atoi(token));
        }
        else{
            int b = pop();
            int a = pop();

            if(token[0]=='+') push(a+b);
            else if(token[0]=='-') push(a-b);
            else if(token[0]=='*') push(a*b);
            else if(token[0]=='/') push(a/b);
        }

        token = strtok(NULL," ");
    }

    printf("%d",pop());

    return 0;
}