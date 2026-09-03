#include <stdio.h>
int main(){
    int arr[100], max, i, n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array: \n");
    for (i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    max = arr[0];
    for (i=1; i<n; i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    printf("Max element is %d", max);
}
