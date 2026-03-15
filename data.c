#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp;
    int i;
    
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    srand(time(0));

    printf("Generating 10 Lakh (1,000,000) numbers... Please wait.\n");
    
    // Loop 1 million times
    for (i = 0; i < 100000; i++) {
        // Generate random numbers. 
        // Note: Standard rand() might repeat numbers often, which is fine for testing.
        fprintf(fp, "%d ", rand()); 
    }

    fclose(fp);
    printf("Done! 'data.txt' with 10 Lakh numbers is ready.\n");
    return 0;
}
