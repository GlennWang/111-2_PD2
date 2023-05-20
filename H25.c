#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculatef(double (*f)(double, double), double a, double p, double q, int n);
double (*getOption(int option))(double, double);
double f1(double a, double x);
double f2(double a, double x);
double myabs(double a);

int main()
{
    int option;
    double a, p, q, err;
    while (scanf("%d", &option))
    {
        if (option == 0)
        {
            break;
        }
        scanf("%lf %lf %lf %lf", &a, &p, &q, &err);
        double (*Option)(double, double) = getOption(option);
        int n = 1;
        double prevarea = calculatef(Option, a, p, q, n);
        double currarea = calculatef(Option, a, p, q, 2 * n);
        n *= 2;
        double derr = pow(10, -err);
        while (myabs(prevarea - currarea) >= derr)
        {
            n *= 2;
            prevarea = currarea;
            currarea = calculatef(Option, a, p, q, n);
        }
        printf("%.12lf\n", currarea);
    }
    return 0;
}

double calculatef(double (*f)(double, double), double a, double p, double q, int n)
{
    double area = f(a, p) + f(a, q);
    double h = (q - p) / n;
    for (double xi = p + h; xi < q; xi += h)
    {
        area += 2 * f(a, xi);
    }
    area *= (q - p);
    area /= (2 * n);
    return area;
}

double (*getOption(int option))(double, double)
{
    if (option == 1)
    {
        return f1;
    }
    else if (option == 2)
    {
        return f2;
    }
    return NULL;
}

double f1(double a, double x)
{
    return sqrt(a - x * x);
}

double f2(double a, double x)
{
    double f2 = (a * x * x * x + 7 * x) / sqrt(a + x);
    if (f2 < 0)
        f2 *= -1.0;
    return f2;
}

double myabs(double a)
{
    if (a < 0)
        return -a;
    else
        return a;
}