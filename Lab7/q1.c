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

int Palindrome(char s[]){
    top=-1;
    int i;
    for(i=0; s[i]!='\0'; i++)
        push(s[i]);

    for (i=0; s[i]!='\0'; i++) {
        if (s[i]!=pop())
            return 0;
    }
    return 1;
}

int main(){
    char s[100];
    printf("Enter word: ");
    scanf("%s", &s);
    if(Palindrome(s))
        printf("Palindrome");
    else
        printf("Not Palindrome");
}
