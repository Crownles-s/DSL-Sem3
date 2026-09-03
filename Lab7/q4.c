#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

void push(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
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

int evaluatePostfix(char* postfix) {
    int i = 0;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (ch >= '0' && ch <= '9') {
            push(ch - '0');
        } else {
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': {
                    int res = 1;
                    for (int k = 0; k < val2; k++) res *= val1;
                    push(res);
                    break;
                }
            }
        }
    }
    return pop();
}

int main() {
    char postfix[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluated Result: %d\n", result);

    return 0;
}
