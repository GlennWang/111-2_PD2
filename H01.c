#include <stdio.h>
#include <math.h>

void main()
{
    int a, b, c;
    double x1, x2;
    scanf("%d\n%d\n%d", &a, &b, &c);
    x1 = ((-b) + sqrt(b * b - 4 * a * c)) / (2.0 * a);
    x2 = ((-b) - sqrt(b * b - 4 * a * c)) / (2.0 * a);
    printf("%.1f\n%.1f", x1, x2);
}