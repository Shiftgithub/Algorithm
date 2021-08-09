#include<stdio.h>
int main()
{
    int index,number;
    FILE* fp1;
    FILE* fp2;
    FILE* fp3;

    fp1=fopen("input.txt","w");
    fp2=fopen("input.txt","r");
    fp3=fopen("output.txt","w");

    for (index = 0; index < 100000; index++)
    {
        number = rand() % 10000000000 + 1; // Generate Random Number

        fprintf(fp1,"%d\n", number); // save fp1 means input.txt file random number

        printf(" %d . %d\n",index,number); // print random number in tarminal

        fprintf(fp3," %d . %d\n",index, number); // save fp1 means output.txt file random number
    }


    return 0;
}
