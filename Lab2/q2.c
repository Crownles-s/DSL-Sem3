#include <stdio.h>
#include <stdlib.h>
void sort(int *arr, int start, int n) {
    if (start>=n-1)
        return;

    int min=start;

    for (int i=start+1; i<n; i++) {
        if (*(arr+i) < *(arr+min)) {
            min=i;
        }
    }

    int temp=*(arr+start);
    *(arr+start)=*(arr+min);
    *(arr+min)=temp;
    sort(arr, start+1, n);
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i=0; i<n; i++) {
        scanf("%d",(arr+i));
    }

    sort(arr, 0, n);

    printf("\nSorted\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
}


