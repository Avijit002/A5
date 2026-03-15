#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n);
void swap(int *a, int *b);
void writeToFile(int arr[], int n);

int main() {

    FILE *file;
    int *arr;
    int n = 0;
    clock_t start,end;

    file = fopen("input_100000.txt","r");

    arr = malloc(200000*sizeof(int));

    while(fscanf(file,"%d",&arr[n])==1)
        n++;

    fclose(file);

    start = clock();
    bubbleSort(arr,n);
    end = clock();

    printf("Bubble Sort Time: %f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);

    writeToFile(arr,n);

    free(arr);
}

void bubbleSort(int arr[], int n){
    int i,j;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
}

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void writeToFile(int arr[], int n){
    FILE *f=fopen("bubble_sorted.txt","w");
    for(int i=0;i<n;i++)
        fprintf(f,"%d\n",arr[i]);
    fclose(f);
}
