#include<stdio.h>
#include<time.h>
#define CLOCKS_PER_SEC 1000;
long int arr[100000];
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;


	int L[n1], R[n2];


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


void mergeSort(int arr[], int l, int r)
{
	if (l < r) {

		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("index %d : %d\n ",i, A[i]);
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

    mergeSort(arr,0,n -1);
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


