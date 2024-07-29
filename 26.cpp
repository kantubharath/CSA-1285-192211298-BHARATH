#include <stdio.h>
#include <time.h>

#define NUM_INSTRUCTIONS 1e6

void multiply(int a, int b, int *result) {
    *result = a * b;
}

int main() {
    int a, b, result;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter two integers to multiply: ");
    scanf("%d %d", &a, &b);

    start = clock();
    
    for(int i = 0; i < NUM_INSTRUCTIONS; i++) {
        multiply(a, b, &result);
    }
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Result: %d\n", result);
    printf("Time taken for %d instructions: %f seconds\n", (int)NUM_INSTRUCTIONS, cpu_time_used);
    printf("Average time per instruction: %f nanoseconds\n", (cpu_time_used / NUM_INSTRUCTIONS) * 1e9);

    return 0;
}


