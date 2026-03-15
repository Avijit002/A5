#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n);

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
    insertionSort(arr,n);
    clock_t end=clock();

    printf("Insertion Sort Time: %f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);

    free(arr);
}

void insertionSort(int arr[], int n){
    int i,key,j;

    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}
