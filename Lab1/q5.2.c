#include <stdio.h>
int main(){
    int arr[100], i, j, n, temp, key;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array: \n");
    for (i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    for (i = 1; i < n; i++) {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    printf("\nSorted\n");
    for (i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
}
