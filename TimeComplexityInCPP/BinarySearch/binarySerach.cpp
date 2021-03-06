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
#include<algorithm>
#define clockPerSec 1000
using namespace std;
long numbers[400000];

void checkSort(long arr[],long amount){
    long ascount,decount,i;
    for(i=0; i<amount-1; i++){
       if(arr[i]<arr[i+1])
            ascount++;
       else if(arr[i]>arr[i+1])
            decount++;
    }
    if(ascount != amount-1 && decount != amount-1){
            cout<<"\n\t<<< Array is not sorted ->";
    }
}
long binarySearch(long numbers[],long amount,long value){

    long beg,end,mid;

    beg=0;
    end=amount;
    mid=(beg+end)/2;

    while (beg <= end && numbers[mid] != value){
    	if(value<numbers[mid]){
    		end=mid-1;
    	}
    	else beg=mid+1;
            mid=(beg+end)/2;
        }
        return mid;
}


int main(int argc, char ** argv)
{
    long amount,i,j,value,ptr,mid;
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
    cout<<"\t<<< Data reading complete !!!\n\n";


    checkSort(numbers,amount);

    cout<<"\n\t<<< So, we are sorting all data as ascending order...\n";

    sort(numbers,numbers+amount);
    cout<<"\t<<< Ascending order Sort  complete !!!\n\n";

    cout<<"Please enter a value for search :";
    cin>>value;

    cout<<"\n\t<<<Binary Search process started,Please Wait...\n";
    fprintf(outputFile,"\t<<<:Binary Search Time Complexity :>>>\n\nValue entered for search : %ld \n\n",value);


    start = clock();


    mid = binarySearch(numbers,amount,value);


    finish = ((double)start)/clockPerSec;

    cout<<"\t<<< Search Complete ...!!!\n\n";
    cout<<"\t<<< Total number of Data :"<<amount<<endl<<endl;

    if(value==numbers[mid]){
        fprintf(outputFile,"Search Time = %lf sec",finish);
    	cout<<"\n\t<<< Search value found in array at position "<<mid+1<<" !!"<<endl; //gives the position of sorted array
        cout<<"\t<<< Time needed for searching :  "<<finish<<" sec\n";

    }
    else {
        fprintf(outputFile,"Data isn't Founded ! Try another Number.......\n");
        cout<<"Data isn't Founded ! Try another Number.......\n";
        cout<<"Time needed for searching :  "<<finish<<"sec\n";
    }

    cout<<"\n\n\t<<< This informations are printed to file named 'outputBinarySearch.txt' \n"<<endl;

	return 0;
}
