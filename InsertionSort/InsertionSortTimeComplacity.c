#include<stdio.h>
#include<time.h>
#define CLOCKS_PER_SEC 1000;
long int arr[100000];
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j,key;
     for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("index %d : %d\n",i,arr[i]);
    }
}

// Driver code
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

    bubbleSort(arr,n); // bubble sorting here
    printArray(arr,n);
    end =((double) clock()-start)/CLOCKS_PER_SEC;
    printf("\nData Sorting Complete .\n");

    printf("\n----------------------------------------------");
    printf("\n\nInput number : %d (And) Sorting Time : %lf\n",n,end);
    printf("\n----------------------------------------------");

    printf("\n\nThis information is added to file name 'sorting_list.txt'\n\n");

    fprintf(fp3,"input number : %d : Sorting Time : %lf\n\n",n,end);

    for(i=1; i<n; i++)
    {
        fprintf(fp2,"%d . %d\n",i, arr[i]);
    }

    return 0;
}

