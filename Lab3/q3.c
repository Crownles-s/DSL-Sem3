#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

void readStudents(struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name, roll no, marks for student %d:\n", i + 1);
        scanf("%s %d %f", (s+i)->name, &(s+i)->roll_no, &(s+i)->marks);
    }
}

void displayStudents(struct Student *s, int n) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll No: %d, Marks: %.2f\n",
               (s+i)->name, (s+i)->roll_no, (s+i)->marks);
    }
}

void highestMarks(struct Student *s, int n) {
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if ((s+i)->marks > (s+pos)->marks) {
            pos = i;
        }
    }
    printf("\nStudent with highest marks:\n");
    printf("Name: %s, Roll No: %d, Marks: %.2f\n",
           (s+pos)->name, (s+pos)->roll_no, (s+pos)->marks);
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student *s = (struct Student *) malloc(n * sizeof(struct Student));
    if (s == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    readStudents(s, n);
    displayStudents(s, n);
    highestMarks(s, n);

    free(s);

    return 0;
}

