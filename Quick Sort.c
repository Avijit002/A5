#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a,int *b);

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
    quickSort(arr,0,n-1);
    clock_t end=clock();

    printf("Quick Sort Time: %f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);

    free(arr);
}

int partition(int arr[], int low, int high){

    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[high]);

    return i+1;
}

void quickSort(int arr[], int low, int high){

    if(low<high){

        int pi=partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
