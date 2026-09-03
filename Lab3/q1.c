#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], fix[100];
    int mode;

    printf("Enter first string: ");
    gets(str);

    printf("1. Size, 2. Concat, 3. Compare, 4. Insert Substring, 5.Delete Substring\n");
    scanf("%d", &mode);

    int i=0;
    while (str[i]!='\0'){
            i++;
    }

    if (mode==1){
        printf("Size is %d",i);
    }

    if (mode==2){
        char str2[100];
        int j;

        printf("Enter second string: ");
        gets(fix);
        gets(str2);

        while (str2[j]!='\0'){
            str[j+i]=str2[j];
            j++;
        }

        printf ("Concat string:\n");
        printf(str);
    }

    if(mode==3){
        char str2[100];
        int i=0, diff=0;

        printf("Enter second string: ");
        gets(fix);
        gets(str2);

        while (str[i]!='0' && str2[i]!='\0' && str[i]==str2[i]){
            i++;
        }

        printf("Difference:\n");
        printf("%d",str[i]-str2[i]);
    }

    if (mode==4){
        char str2[100], temp[100];
        int i=0, pos, k=0;

        printf("Enter substring: ");
        gets(fix);
        gets(str2);

        printf("Enter position: ");
        scanf("%d", &pos);

        while (str[i]!='\0' && i<pos){
            temp[i]=str[i];
            i++;
        }

        while (str2[k]!='\0'){
            temp[k+i]=str2[k];
            k++;
        }

        int m=0;
        while (str[i]!='\0'){
            temp[i+k+m]=str[i+m];
            m++;
        }
        temp[i+k+m+1]='\0';

        printf("New string:\n");
        printf(temp);
    }

    if (mode==5){
        char res[100];
        int i=0, pos, len, j=0;

        printf("Enter position: ");
        scanf("%d", &pos);
        printf("Enter length: ");
        scanf("%d", &len);

        while (i<pos && str[i]!='\0'){
            res[j]=str[i];
            i++;
            j++;
        }

        i=pos+len;
        while (str[i]!='\0'){
            res[j]=str[i];
            i++;
            j++;
        }
        res[j]='\0';

        printf("New string:\n");
        printf(res);
    }
}
