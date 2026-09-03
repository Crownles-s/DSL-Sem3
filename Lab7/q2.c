#include <stdio.h>
#include <string.h>
#define MAX 100

char item[MAX];
int top=-1;

void push(char c){
    if (top<MAX-1){
        top++;
        item[top]=c;
    }
}

char pop(){
    if (top>=0){
        return item[top--];
    }
    return '\0';
}

void input(char s[], int i){
    if (s[i]=='(' || s[i]=='[' || s[i]=='{'){
        push(s[i]);
    }
    else if (s[i]==')'){
        if (top >= 0 && item[top] == '(') {
            pop();
        } else {
            push(s[i]);
        }
    }
    else if (s[i]==']'){
        if (top >= 0 && item[top] == '[') {
            pop();
        } else {
            push(s[i]);
        }
    }
    else if (s[i]=='}'){
        if (top >= 0 && item[top] == '{') {
            pop();
        } else {
            push(s[i]);
        }
    }
}

int check(){
    if (top == -1){
        return 1;
    }
    else return 0;
}

int main(){
    char s[100];
    int i;
    printf("Enter expression: ");
    scanf("%s", s);
    top=-1;
    for (i=0; s[i]!='\0'; i++){
            input(s,i);
    }
    int k=check();
    if (k==0) printf("Not Matching");
    else printf("Matching Parentheses");
}
