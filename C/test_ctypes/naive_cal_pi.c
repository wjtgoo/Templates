#include <stdio.h>
#include <math.h>
#include <time.h>

// Function to calculate Pi using series summation
double calculate_pi(int terms) {
    double pi = 0.0;

    for (int i = 0; i < terms; i++) {
        // Leibniz series: Pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
        pi += pow(-1, i) / (2.0 * i + 1.0);
    }

    return pi * 4.0; // Multiply by 4 to get Pi
}

int main() {
    int terms;

    // Ask the user for the number of terms
    // printf("Enter the number of terms for the series: ");
    // scanf("%d", &terms);
    terms = 100000000;
    // Start measuring time
    clock_t start_time = clock();

    // Calculate Pi
    double pi = calculate_pi(terms);

    // Stop measuring time
    clock_t end_time = clock();

    // Calculate elapsed time in seconds
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the result
    printf("Call naive C:\n");
    printf("out: %.15f, time used: %.4es\n", pi, elapsed_time);
    // printf("Time taken: %.6f seconds\n", elapsed_time);

    return 0;
}
