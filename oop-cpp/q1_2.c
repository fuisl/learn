#include <stdio.h>
#include <math.h>

double calculate_function(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        double term = -(pow(0.5, i)) / i;  // Calculate each term of the summation
        sum += term;                          // Add the term to the sum
    }
    return sum;
}

int main() {
    int n;
    printf("Enter a value for n: ");
    scanf("%d", &n);

    double result = calculate_function(n);

    printf("The value of the function for n = %d is: %.6lf\n", n, result);

    return 0;
}
