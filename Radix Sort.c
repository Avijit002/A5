#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMax(int arr[], int n);
void radixSort(int arr[], int n);
void countSort(int arr[], int n, int exp);

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
    radixSort(arr,n);
    clock_t end=clock();

    printf("Radix Sort Time: %f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);

    free(arr);
}

int getMax(int arr[], int n){
    int mx=arr[0];
    for(int i=1;i<n;i++)
        if(arr[i]>mx)
            mx=arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp){

    int *output=malloc(n*sizeof(int));
    int count[10]={0};

    for(int i=0;i<n;i++)
        count[(arr[i]/exp)%10]++;

    for(int i=1;i<10;i++)
        count[i]+=count[i-1];

    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++)
        arr[i]=output[i];

    free(output);
}

void radixSort(int arr[], int n){

    int m=getMax(arr,n);

    for(int exp=1;m/exp>0;exp*=10)
        countSort(arr,n,exp);
}
