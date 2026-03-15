#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binarySearchRecursive(int arr[], int low, int high, int key) {

    if(low > high)
        return -1;

    int mid = (low + high) / 2;

    if(arr[mid] == key)
        return mid;

    if(arr[mid] < key)
        return binarySearchRecursive(arr, mid+1, high, key);

    return binarySearchRecursive(arr, low, mid-1, key);
}

int main() {

    FILE *file;
    int *arr;
    int n = 0, key, result;

    file = fopen("input_data_of_1000000.txt","r");

    arr = malloc(2000000*sizeof(int));

    while(fscanf(file,"%d",&arr[n]) == 1)
        n++;

    fclose(file);

    qsort(arr,n,sizeof(int),compare);

    printf("Enter key: ");
    scanf("%d",&key);

    clock_t start = clock();
    result = binarySearchRecursive(arr,0,n-1,key);
    clock_t end = clock();

    if(result != -1)
        printf("Found at index %d\n",result);
    else
        printf("Not Found\n");

    printf("Time = %f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);

    free(arr);
}
