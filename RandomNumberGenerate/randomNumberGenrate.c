#include<stdio.h>
int main()
{
    int i,n,number;
    FILE* fp1;
    FILE* fp2;
    FILE* fp3;

    fp1=fopen("input.txt","w");
    fp2=fopen("input.txt","r");
    fp3=fopen("output.txt","w");

    printf("Enter array size :");
    scanf("%d",&n);


    for (i = 1; i <= n; i++)
    {
        number = rand() % 1000000 + 1; // Generate Random Number

        fprintf(fp1,"%d\n", number); // save fp1 means input.txt file random number

        printf(" %d . %d\n",i,number); // print random number in tarminal

        fprintf(fp3," %d . %d\n",i, number); // save fp1 means output.txt file random number
    }


    return 0;
}
