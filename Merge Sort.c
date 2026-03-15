#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[],int l,int r);
void merge(int arr[],int l,int m,int r);

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

    mergeSort(arr,0,n-1);

    file=fopen("merge_sorted.txt","w");

    for(i=0;i<n;i++)
        fprintf(file,"%d\n",arr[i]);

    fclose(file);

    printf("Merge Sort completed\n");

    free(arr);
    return 0;
}

void merge(int arr[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;

    int *L=(int*)malloc(n1*sizeof(int));
    int *R=(int*)malloc(n2*sizeof(int));

    for(i=0;i<n1;i++)
        L[i]=arr[l+i];

    for(j=0;j<n2;j++)
        R[j]=arr[m+1+j];

    i=0;j=0;k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }

    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[],int l,int r)
{
    int m;

    if(l<r)
    {
        m=l+(r-l)/2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}
