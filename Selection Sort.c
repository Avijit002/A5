#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n);
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

    selectionSort(arr,n);

    file=fopen("selection_sorted.txt","w");

    for(i=0;i<n;i++)
        fprintf(file,"%d\n",arr[i]);

    fclose(file);

    printf("Selection Sort completed\n");

    free(arr);
    return 0;
}

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void selectionSort(int arr[],int n)
{
    int i,j,min;

    for(i=0;i<n-1;i++)
    {
        min=i;

        for(j=i+1;j<n;j++)
            if(arr[j]<arr[min])
                min=j;

        swap(&arr[min],&arr[i]);
    }
}
