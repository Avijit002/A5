#include <stdio.h>
#include <stdlib.h>

void heapSort(int arr[],int n);
void heapify(int arr[],int n,int i);
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

    heapSort(arr,n);

    file=fopen("heap_sorted.txt","w");

    for(i=0;i<n;i++)
        fprintf(file,"%d\n",arr[i]);

    fclose(file);

    printf("Heap Sort completed\n");

    free(arr);
    return 0;
}

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void heapify(int arr[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && arr[l]>arr[largest]) largest=l;
    if(r<n && arr[r]>arr[largest]) largest=r;

    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n)
{
    int i;

    for(i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    for(i=n-1;i>0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
