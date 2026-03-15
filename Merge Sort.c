#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(){

    FILE *file;
    int *arr;
    int n=0;

    file=fopen("input_100000.txt","r");

    arr=malloc(200000*sizeof(int));

    while(fscanf(file,"%d",&arr[n])==1)
        n++;

    fclose(file);

    clock_t start=clock();
    mergeSort(arr,0,n-1);
    clock_t end=clock();

    printf("Merge Sort Time: %f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);

    free(arr);
}

void merge(int arr[], int l, int m, int r){

    int i=l,j=m+1,k=0;
    int *temp=malloc((r-l+1)*sizeof(int));

    while(i<=m && j<=r){
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }

    while(i<=m) temp[k++]=arr[i++];
    while(j<=r) temp[k++]=arr[j++];

    for(i=l,k=0;i<=r;i++,k++)
        arr[i]=temp[k];

    free(temp);
}

void mergeSort(int arr[], int l, int r){

    if(l<r){

        int m=(l+r)/2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}
