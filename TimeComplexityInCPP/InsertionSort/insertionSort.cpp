/**
*   Name: Mamun Mia Turan
*   ID  : CSE2001019039
*   Section: 19A1
*   Insertion Sort Time Complexity
*/
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define clockPerSec 1000
using namespace std;
long numbers[400000];

void insertionSort(long arr[], long n)
{
    long i, key, j;

    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char ** argv)
{
    long amount,i,j,save;
    double finish;
    clock_t start;

    FILE *inputFile, *outputFile;

    inputFile = fopen("inputFile.txt","r");
    outputFile = fopen("outputFile.txt","w");
    fscanf(inputFile,"%d",&amount);

    cout<<"\n\t<<< Reading data from File ..... "<<endl;
    for (i=0; i<amount; i++){
        fscanf(inputFile,"%d",&numbers[i]);
    }
    cout<<"\t<<< Data reading complete !!!\n";
    cout<<"\t<<< Insertion Sort process started\n\tPlease Wait.....\n";

    start = clock();

    insertionSort(numbers,amount);

    finish = ((double)start)/clockPerSec;

    cout<<"\t<<< Sorting Complete ...!!!\n\n";
    cout<<"\t<<< Number of Data : "<<amount<<" Time needed for sorting :  "<<finish<<" sec\n";

    cout<<"\n\n\t<<< This informations are printed in file named 'outputinsertionSort.txt' \n"<<endl;
	fprintf(outputFile,"Data = %d , Time needed = %lf sec\n",amount,finish);
	fprintf(outputFile,"\n\n\t<<< Array after Insertion Sort :\n");

    for(long i=0; i<amount; i++){
        fprintf(outputFile,"%d\n",numbers[i]);
    }
	return 0;
}
