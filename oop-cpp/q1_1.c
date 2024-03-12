#include <stdio.h>
#include <math.h>

double f(double x) {
    return x / 2.0 * (1 + x + 0.04 * pow(x, 3));
}

int main() {
    double x;
    printf("Enter a value for x: ");
    scanf("%lf", &x);

    double result = f(x);

    printf("f(%.2lf) = %.6lf\n", x, result);

    return 0;
}
