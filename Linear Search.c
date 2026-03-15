#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main() {

    FILE *file;
    int *arr;
    int n = 0, key, result;
    clock_t start, end;
    double time_taken;

    file = fopen("input_data_of_1000000.txt", "r");
    if(file == NULL) {
        printf("File not found\n");
        return 1;
    }

    arr = (int*)malloc(2000000 * sizeof(int));

    while(fscanf(file, "%d", &arr[n]) == 1)
        n++;

    fclose(file);

    printf("Enter key: ");
    scanf("%d", &key);

    start = clock();
    result = linearSearch(arr, n, key);
    end = clock();

    if(result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not Found\n");

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time = %f seconds\n", time_taken);

    free(arr);
}
