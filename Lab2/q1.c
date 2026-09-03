#include <stdio.h>
#include <stdlib.h>
int minimum(int n, int arr[]){
    int min;

    min = arr[0];
    for (int i=1; i<n; i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }

    return min;
}


int main()
{
    int n, i, *arr, min;
    printf("Enter size: ");
    scanf("%d",&n);

     arr=(int*)malloc(n*sizeof(int));

    printf("Enter Array:\n");
    for (i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    min = minimum(n,arr);
    printf("\nSmallest is %d",min);
}
