#include <stdio.h>

struct student {
    char name[50];
    int roll;
    char grade;
};

void read(struct student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name, roll no, grade for student %d:\n", i + 1);
        scanf("%s %d %c", s[i].name, &s[i].roll, &s[i].grade);
    }
}

void display(struct student s[], int n) {
    printf("\nStudent Information:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll No: %d, Grade: %c\n", s[i].name, s[i].roll, s[i].grade);
    }
}

void sort(struct student s[], int n) {
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].roll > s[j].roll) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student s[100];

    read(s, n);
    printf("\nBefore Sorting:\n");
    display(s, n);

    sort(s, n);
    printf("\nAfter Sorting by Roll No:\n");
    display(s, n);
}

