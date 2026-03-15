#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
void heapSort(int arr[], int n);
void radixSort(int arr[], int n);
void printArray(int arr[], int n);
void copyArray(int source[], int dest[], int n);
void writeToFile(int arr[], int n, char *filename);

// Helper Functions
void merge(int arr[], int l, int m, int r);
int partition(int arr[], int low, int high);
void heapify(int arr[], int n, int i);
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);

int main() {
    FILE *file;
    int *arr, *copy;
    int n = 0, choice, i;
    clock_t start, end;
    double time_taken;
    char inputMsg[100];

    // Open Input File
    file = fopen("input_100000.txt", "r");
    if (file == NULL) {
        printf("Error: 'input_100000.txt' not found.\n");
        return 1;
    }

    // Allocate Memory (Max 2000000)
    arr = (int *)malloc(200000 * sizeof(int));
    copy = (int *)malloc(200000 * sizeof(int));

    // Read Data
    while (fscanf(file, "%d", &arr[n]) == 1) {
        n++;
    }
    fclose(file);

    printf("Loaded %d integers from input_100000.txt\n", n);

    while (1) {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Bubble Sort (O(n^2))\n");
        printf("2. Insertion Sort (O(n^2))\n");
        printf("3. Selection Sort (O(n^2))\n");
        printf("4. Merge Sort (O(n log n))\n");
        printf("5. Quick Sort (O(n log n))\n");
        printf("6. Radix Sort (O(nk))\n");
        printf("7. Heap Sort (O(n log n))\n");
        printf("8. All (time complexity comparison between all methods)\n");
        printf("9. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        if (choice == 9) break;

        // Reset data for the sort
        copyArray(arr, copy, n);

        if (choice >= 1 && choice <= 7) {
            printf("Sorting... (Please wait)\n");
            start = clock();
            switch (choice) {
                case 1: bubbleSort(copy, n); break;
                case 2: insertionSort(copy, n); break;
                case 3: selectionSort(copy, n); break;
                case 4: mergeSort(copy, 0, n - 1); break;
                case 5: quickSort(copy, 0, n - 1); break;
                case 6: radixSort(copy, n); break;
                case 7: heapSort(copy, n); break;
            }
            end = clock();
            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Time Taken: %f seconds\n", time_taken);
            
            // Write output
            writeToFile(copy, n, "sorted_100000.txt");
            printf("Sorted data written to 'sorted_100000.txt'\n");
        } 
        else if (choice == 8) {
            printf("\n--- Running All Sorts... (Please wait) ---\n");
            
            // Bubble
            copyArray(arr, copy, n);
            printf("Bubble Sort: ");
            start = clock(); bubbleSort(copy, n); end = clock();
            printf("%f sec\n", ((double)(end - start)) / CLOCKS_PER_SEC);

            // Insertion
            copyArray(arr, copy, n);
            printf("Insertion Sort: ");
            start = clock(); insertionSort(copy, n); end = clock();
            printf("%f sec\n", ((double)(end - start)) / CLOCKS_PER_SEC);

            // Selection
            copyArray(arr, copy, n);
            printf("Selection Sort: ");
            start = clock(); selectionSort(copy, n); end = clock();
            printf("%f sec\n", ((double)(end - start)) / CLOCKS_PER_SEC);

            // Merge
            copyArray(arr, copy, n);
            printf("Merge Sort: ");
            start = clock(); mergeSort(copy, 0, n - 1); end = clock();
            printf("%f sec\n", ((double)(end - start)) / CLOCKS_PER_SEC);

            // Quick
            copyArray(arr, copy, n);
            printf("Quick Sort: ");
            start = clock(); quickSort(copy, 0, n - 1); end = clock();
            printf("%f sec\n", ((double)(end - start)) / CLOCKS_PER_SEC);

            // Radix
            copyArray(arr, copy, n);
            printf("Radix Sort: ");
            start = clock(); radixSort(copy, n); end = clock();
            printf("%f sec\n", ((double)(end - start)) / CLOCKS_PER_SEC);

            // Heap
            copyArray(arr, copy, n);
            printf("Heap Sort: ");
            start = clock(); heapSort(copy, n); end = clock();
            printf("%f sec\n", ((double)(end - start)) / CLOCKS_PER_SEC);
        }
    }

    free(arr);
    free(copy);
    return 0;
}

// Utils
void copyArray(int source[], int dest[], int n) {
    int i;
    for (i = 0; i < n; i++) dest[i] = source[i];
}

void writeToFile(int arr[], int n, char *filename) {
    FILE *f = fopen(filename, "w");
    int i;
    for (i = 0; i < n; i++) fprintf(f, "%d\n", arr[i]);
    fclose(f);
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Radix Sort
int getMax(int arr[], int n) {
    int mx = arr[0], i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int *output = (int*)malloc(n * sizeof(int));
    int i, count[10] = {0};

    for (i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++) count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) arr[i] = output[i];
    free(output);
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
