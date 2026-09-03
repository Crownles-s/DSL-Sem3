#include <stdio.h>
int main(){
    int arr[100], i, j, n, temp;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array: \n");
    for (i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    for (i=0; i<n-1; i++){
        for (j=0; j<n; j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("\nSorted\n");
    for (i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
}
