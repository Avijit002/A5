#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int modifiedLinearSearch(int arr[], int n, int key) {

    arr[n] = key;

    int i = 0;
    while(arr[i] != key)
        i++;

    if(i < n)
        return i;

    return -1;
}

int main() {

    FILE *file;
    int *arr;
    int n = 0, key, result;
    clock_t start, end;

    file = fopen("input_data_of_1000000.txt", "r");

    arr = (int*)malloc(2000000 * sizeof(int));

    while(fscanf(file,"%d",&arr[n]) == 1)
        n++;

    fclose(file);

    printf("Enter key: ");
    scanf("%d",&key);

    start = clock();
    result = modifiedLinearSearch(arr,n,key);
    end = clock();

    if(result != -1)
        printf("Found at index %d\n",result);
    else
        printf("Not Found\n");

    printf("Time = %f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);

    free(arr);
}
