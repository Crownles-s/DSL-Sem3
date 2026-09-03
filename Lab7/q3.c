#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

void push(char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        return '\0';
    }
    struct Node* temp = top;
    char val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int precedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

void toPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isOperand(ch)) {
            postfix[j++] = ch;
        }

        else if (ch == '(') {
            push(ch);
        }

        else if (ch == ')') {
            while (top != NULL && top->data != '(') {
                postfix[j++] = pop();
            }
            if (top != NULL && top->data == '(') {
                pop(); // Remove '(' from stack
            }
        }

        else {
            while (top != NULL && precedence(top->data) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }


    while (top != NULL) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter infix: ");
    scanf("%s", infix);

    toPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);
}
