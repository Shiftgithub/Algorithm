#include<stdio.h>
#include<time.h>
#define CLOCKS_PER_SEC 1000;
long int arr[100000];

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("index %d : %d\n ",i, arr[i]);
    printf("\n");
}


int main()
{
    long int n;
    long int i,j,save;

    double end;
    clock_t start;

    FILE *fp1;
    FILE *fp2;
    FILE *fp3;

    fp1=fopen("input.txt","r");
    fp2=fopen("sorting_list.txt","w");
    fp3=fopen("output.txt","a");

    printf("Enter Array Size( 1 to 100000 ) : ");
    scanf("%d",&n);

    printf("\nData Reading Complete .");
    printf("\nData Sorting Process Started......Please Wait.\n");

    for(i=1; i<n; i++)
    {
        fscanf(fp1,"%d",&arr[i]);
    }
    start = clock();

    quickSort(arr,0,n -1);

    printArray(arr,n);

    end =((double) clock()-start)/CLOCKS_PER_SEC;
    printf("\nData Sorting Complete .\n");

    printf("\n----------------------------------------------");
    printf("\n\nInput number : %d (And) Sorting Time : %lf\n",n,end);
    printf("\n----------------------------------------------");

    printf("\nThis information is added to file name 'sorting_list.txt'");

    fprintf(fp3,"input number : %d : Sorting Time : %lf\n\n",n,end);

    for(i=1; i<n; i++)
    {
        fprintf(fp2,"%d . %d\n",i, arr[i]);
    }

    return 0;
}


