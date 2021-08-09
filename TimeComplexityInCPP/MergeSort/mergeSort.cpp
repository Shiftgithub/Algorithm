/**
*   Name: Mamun Mia Turan
*   ID  : CSE2001019039
*   Section: 19A1
*   Merge Sort Time Complexity
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define clockPerSec 1000
using namespace std;
long numbers[400000];

void merge(long arr[], long l, long m, long r){
    long i, j, k;
    long n1 = m - l + 1;
    long n2 = r - m;

    long L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long arr[], long l, long r)
{
    if (l < r) {

        long m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main(int argc, char ** argv)
{
    long amount,i=0,j,read;
    double finish;
    clock_t start;

    ofstream outputFile;
    outputFile.open("outputFile.txt",ios::out);

    ifstream is("inputFile.txt");
    is>>read;
    amount = read;

    cout<<"\n\t<<< Reading data from File ..... "<<amount<<endl;
    while(i<amount && is>>read){
        numbers[i++] = read;
    }
    cout<<"\t<<< Data reading complete !!!\n";
    cout<<"\t<<< Merge Sort process started,Please Wait...\n";

    start = clock();
    mergeSort(numbers,0,amount-1);
    finish = ((double)start)/clockPerSec;

    cout<<"\t<<< Sorting Complete ...!!!\n\n";
    cout<<"\t<<< Number of Data : "<<amount<<" ,Time needed for sorting :  "<<finish<<" sec\n";

    cout<<"\n\n\t<<< This informations are printed in file named 'outputMergeSort.txt' \n"<<endl;
    outputFile<<"Data = "<<amount<<" ,Time needed = "<<finish<<endl;
    outputFile<<"\n\n\t<<< Array after Merge Sort :\n";

    for(i=0; i<amount; i++){
        outputFile<<numbers[i]<<endl;
    }

	return 0;
}
