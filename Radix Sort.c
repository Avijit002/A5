#include <stdio.h>
#include <stdlib.h>

void radixSort(int arr[],int n);
int getMax(int arr[],int n);
void countSort(int arr[],int n,int exp);

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

    radixSort(arr,n);

    file=fopen("radix_sorted.txt","w");

    for(i=0;i<n;i++)
        fprintf(file,"%d\n",arr[i]);

    fclose(file);

    printf("Radix Sort completed\n");

    free(arr);
    return 0;
}

int getMax(int arr[],int n)
{
    int mx=arr[0],i;

    for(i=1;i<n;i++)
        if(arr[i]>mx)
            mx=arr[i];

    return mx;
}

void countSort(int arr[],int n,int exp)
{
    int *output=(int*)malloc(n*sizeof(int));
    int count[10]={0};
    int i;

    for(i=0;i<n;i++)
        count[(arr[i]/exp)%10]++;

    for(i=1;i<10;i++)
        count[i]+=count[i-1];

    for(i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(i=0;i<n;i++)
        arr[i]=output[i];

    free(output);
}

void radixSort(int arr[],int n)
{
    int m=getMax(arr,n);
    int exp;

    for(exp=1;m/exp>0;exp*=10)
        countSort(arr,n,exp);
}
