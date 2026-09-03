#include <stdio.h>
int main(){
    int arr[100], key, i, n, index=-1;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array: \n");
    for (i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter number to find: ");
    scanf("%d", &key);

    for (i=0; i<n; i++){
        if (arr[i]==key){
            index=i;
        }
    }

    if (index==-1)printf("Element not in array");
    else printf("Element at index %d", index);
}
