#include <stdio.h>
int main(){
    int a[100][100], b[100][100], i, j, n, m, c[100][100];

    printf("Enter size of matrices: ");
    scanf("%d %d", &n, &m);

    printf("Enter array A: \n");
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter array B: \n");
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            scanf("%d", &b[i][j]);
        }
    }

    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            if (a[i][j]>=b[i][j])
                c[i][j]=a[i][j];
            else
                c[i][j]=b[i][j];
        }
    }

    printf("\nArray C: ");
    for (i=0; i<n; i++){
        printf("\n");
        for (j=0; j<m; j++){
            printf("%d   ", c[i][j]);
        }
    }
}
