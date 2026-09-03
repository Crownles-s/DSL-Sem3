#include <stdio.h>
int main(){
    int arr[100], i, j, n, temp, pos;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array: \n");
    for (i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    for (i=0; i<n; i++){
        pos=i;
        for (j=i+1; j<n; j++){
            if (arr[pos]>arr[j])
                pos=j;
            }
        temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
    }

    printf("\nSorted\n");
    for (i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
}
