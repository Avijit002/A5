#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n);
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
    selectionSort(arr,n);
    clock_t end=clock();

    printf("Selection Sort Time: %f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);

    free(arr);
}

void selectionSort(int arr[], int n){
    int i,j,min;

    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[min])
                min=j;

        swap(&arr[i],&arr[min]);
    }
}

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
