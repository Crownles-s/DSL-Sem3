#include <stdio.h>
int main(){
    int arr[100], key, i, n, flag=0, temp;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array: \n");
    for (i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter number to find: ");
    scanf("%d", &key);

    int high, low, mid;
    high = n-1;
    low = 0;
    while (flag!=1 && high!=low){
        mid = (high+low)/2;
        if (key>arr[mid])
            low = mid+1;
        else if (key<arr[mid])
            high = mid-1;
        else {
            flag=1;
        }
    }

    if (flag==0)
        printf("Element not in array");
    else
        printf("Found %d in matrix at index %d", key, mid+low );
}
