/**
*   Name: Mamun Mia Turan
*   ID  : CSE2001019039
*   Section: 19A1
*   Quick Sort Time Complexity
*/
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define clockPerSec 1000
using namespace std;
long numbers[400000];

void swap(long* a, long* b) {
    long t = *a;
    *a = *b;
    *b = t;
}

long partition (long arr[], long low, long high) {
    long pivot = arr[high];
    long i = (low - 1);

    for (long j = low; j < high; j++) {

        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(long arr[], long low, long high) {
    if (low < high) {

        long pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main(int argc, char ** argv){
    long amount,i,j;
    double finish;
    clock_t start;

    FILE *inputFile, *outputFile;

    inputFile = fopen("inputFile.txt","r");
    outputFile = fopen("outputFile.txt","w");

    fscanf(inputFile,"%d",&amount);

    cout<<"\n\t<<< Reading Data Form File..... "<<endl;
    for (i=0; i<amount; i++){
        fscanf(inputFile,"%d",&numbers[i]);
    }
    cout<<"\t<<< Data Reading Complete.\n";

    cout<<"\t<<< Quick Sort process started.\n\t<<<Please Wait.....\n";

    start = clock();

    quickSort(numbers, 0, amount-1);

    finish = ((double)start)/clockPerSec;

    cout<<"\t<<< Quick Sort Complete.\n\n";
    cout<<"\t<<< Number of Data : "<<amount<<" Time needed for sorting is :  "<<finish<<endl;

    cout<<"\n\n\t<<< This information is recorded to file 'outFile.txt' \n"<<endl;
	fprintf(outputFile,"Data = %d , Time = %lf",amount,finish);
	fprintf(outputFile,"\n\n Sorted Data : \n\n");

    for(long i=0; i<amount; i++){
        fprintf(outputFile,"%d\n",numbers[i]);
    }
	return 0;
}
