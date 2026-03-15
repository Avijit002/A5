#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Functions
int linearSearch(int arr[], int n, int key);
int modifiedLinearSearch(int arr[], int n, int key);
int binarySearchIterative(int arr[], int n, int key);
int binarySearchRecursive(int arr[], int low, int high, int key);
void sortArray(int arr[], int n);
int compare(const void *a, const void *b);

int main() {
    FILE *file;
    int *arr;
    int n = 0, key, choice, result, i;
    int isSorted = 0;
    clock_t start, end;
    double time_taken;
    long long j;

    // Open File
    file = fopen("input_data_of_1000000.txt", "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    // Allocate Data (Max 2000000)
    arr = (int *)malloc(2000000 * sizeof(int));
    
    // Read Data
    while (fscanf(file, "%d", &arr[n]) == 1) {
        n++;
    }
    fclose(file);
    
    printf("Loaded %d integers from input_data_of_1000000.txt file .\n", n);

    while (1) {
        printf("\n1. Linear Search\n");
        printf("2. Modified Linear Search\n");
        printf("3. Binary Search (Iterative)\n");
        printf("4. Binary Search (Recursive)\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        printf("Enter key: ");
        scanf("%d", &key);

        // Sort for Binary Search
        if ((choice == 3 || choice == 4) && !isSorted) {
            printf("Sorting...\n");
            sortArray(arr, n);
            isSorted = 1;
        }

        // Measure Time (Loop 1000 times for accuracy)
        start = clock();
        for (j = 0; j < 1000; j++) {
            switch (choice) {
                case 1: result = linearSearch(arr, n, key); break;
                case 2: result = modifiedLinearSearch(arr, n, key); break;
                case 3: result = binarySearchIterative(arr, n, key); break;
                case 4: result = binarySearchRecursive(arr, 0, n - 1, key); break;
            }
        }
        end = clock();

        if (result != -1) printf("Found at index: %d\n", result);
        else printf("Not Found\n");

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000;
        printf("Time: %.9f seconds\n", time_taken);
    }

    free(arr);
    return 0;
}

// Linear Search
int linearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

// Modified Linear Search (Sentinel) 
int modifiedLinearSearch(int arr[], int n, int key) {
    arr[n] = key;
    int i = 0;
    while (arr[i] != key) {
        i++;
    }
    if (i < n) return i;
    return -1;
}

// Binary Search (Iterative)
int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Binary Search (Recursive)
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) return binarySearchRecursive(arr, mid + 1, high, key);
        return binarySearchRecursive(arr, low, mid - 1, key);
    }
    return -1;
}

// Helper for Sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void sortArray(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
}
