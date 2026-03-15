#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[],int low,int high);
int partition(int arr[],int low,int high);
void swap(int *a,int *b);

int main()
{
    FILE *file;
    int *arr;
    int n=0,i;

    arr=(int*)malloc(200000*sizeof(int));

    file=fopen("input_100000.txt","r");

    if(file==NULL)
    {
        printf("File not found\n");
        return 1;
    }

    while(fscanf(file,"%d",&arr[n])==1)
        n++;

    fclose(file);

    quickSort(arr,0,n-1);

    file=fopen("quick_sorted.txt","w");

    for(i=0;i<n;i++)
        fprintf(file,"%d\n",arr[i]);

    fclose(file);

    printf("Quick Sort completed\n");

    free(arr);
    return 0;
}

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1,j;

    for(j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quickSort(int arr[],int low,int high)
{
    int pi;

    if(low<high)
    {
        pi=partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
