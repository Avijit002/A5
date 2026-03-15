#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
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
    heapSort(arr,n);
    clock_t end=clock();

    printf("Heap Sort Time: %f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);

    free(arr);
}

void heapify(int arr[], int n, int i){

    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && arr[l]>arr[largest]) largest=l;
    if(r<n && arr[r]>arr[largest]) largest=r;

    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){

    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    for(int i=n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
