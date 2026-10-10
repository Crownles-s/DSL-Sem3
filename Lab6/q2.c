#include <stdio.h>
#include <stdlib.h>

struct poly {
    int coeff;
    int exp;
    struct poly *next, *prev;
};

struct poly* createNode(int c, int e) {
    struct poly* newNode = (struct poly*)malloc(sizeof(struct poly));

    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = newNode->prev = NULL;

    return newNode;
}

struct poly* newTerm(struct poly *head, int c, int e) {
    if (c == 0) return head;

    struct poly* newNode = createNode(c, e);
    if (head == NULL) {
        return newNode;
    }

    struct poly* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct poly* addPoly(struct poly *p1, struct poly *p2) {
    struct poly *resHead = NULL;
    struct poly *resTail = NULL;

    while (p1 != NULL || p2 != NULL) {
        int c = 0;
        int e = 0;

        if (p1 != NULL && (p2 == NULL || p1->exp > p2->exp)) {
            c = p1->coeff;
            e = p1->exp;
            p1 = p1->next;
        }
        else if (p2 != NULL && (p1 == NULL || p2->exp > p1->exp)) {
            c = p2->coeff;
            e = p2->exp;
            p2 = p2->next;
        }
        else {
            c = p1->coeff + p2->coeff;
            e = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }

        if (c != 0) {
            struct poly *newNode = createNode(c, e);
            if (resHead == NULL) {
                resHead = newNode;
                resTail = newNode;
            }
            else {
                resTail->next = newNode;
                newNode->prev = resTail;
                resTail = newNode;
            }
        }
    }
    return resHead;
}

void display(struct poly *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct poly *temp = head;
    while (temp != NULL) {
        printf("(%d)x^%d", temp->coeff, temp->exp);

        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct poly *head1 = NULL;
    struct poly *head2 = NULL;
    int n, c, e;

    printf("Enter number of terms in P1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and exp: ");
        scanf("%d %d", &c, &e);
        head1 = newTerm(head1, c, e);
    }

    printf("Enter number of terms in P2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and exp: ");
        scanf("%d %d", &c, &e);
        head2 = newTerm(head2, c, e);
    }

    printf("Poly 1: ");
    display(head1);

    printf("Poly 2: ");
    display(head2);

    struct poly *sum = addPoly(head1, head2);

    printf("Sum Polynomial: ");
    display(sum);
}
