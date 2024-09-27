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