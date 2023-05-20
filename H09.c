#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y);
void swap(double *a, double *b);
void linearEquation();
void findingEquationsOfStraightLines();
void findingTheIntersectionPoint();
void negativeHanding(int *Numerator, int *Denominator);

int main()
{
    linearEquation();
}

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void linearEquation()
{
    int mode;
    scanf("%d\n", &mode);
    if (mode == 1)
        findingEquationsOfStraightLines();
    else if (mode == 2)
        findingTheIntersectionPoint();
}

void findingEquationsOfStraightLines()
{
    int K;
    scanf("%d\n", &K);
    int x1, y1, x2, y2;
    int mNumerator, mDenominator;
    int bNumerator, bDenominator;
    int hcf;
    for (int i = 0; i < K; i++)
    {
        scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
        mNumerator = y1 - y2;
        mDenominator = x1 - x2;
        bNumerator = (x2 * y1 - x1 * y2);
        bDenominator = (x2 - x1);
        hcf = gcd(abs(mNumerator), abs(mDenominator));
        mNumerator /= hcf;
        mDenominator /= hcf;
        negativeHanding(&mNumerator, &mDenominator);
        // printf("debug:%d %d\n", mNumerator, mDenominator);
        hcf = gcd(abs(bNumerator), abs(bDenominator));
        bNumerator /= hcf;
        bDenominator /= hcf;
        negativeHanding(&bNumerator, &bDenominator);
        // printf("debug:%d %d\n", bNumerator, bDenominator);
        printf("y = ");
        if (bNumerator == 0 || bDenominator == 0)
        {
            if (abs(mNumerator) == abs(mDenominator)) //  && abs(mNumerator / mDenominator) == 1
                if (mNumerator < 0)
                    printf("-x\n");
                else
                    printf("x\n");
            else if (mNumerator % mDenominator == 0)
                printf("%dx\n", (mNumerator / mDenominator));
            else
                printf("%d/%d\n", mNumerator, mDenominator);
        }
        else if (mNumerator == 0 || mDenominator == 0)
        {
            if (bNumerator % bDenominator == 0)
                printf("%d\n", (bNumerator / bDenominator));
            else
                printf("%d/%d\n", abs(bNumerator), bDenominator);
        }
        else
        {                                             // -1 != 1         3 / 2 = 1
            if (abs(mNumerator) == abs(mDenominator)) //  && abs(mNumerator / mDenominator) == 1
                if (mNumerator < 0)
                    printf("-x ");
                else
                    printf("x ");
            else if (mNumerator % mDenominator == 0)
                printf("%dx ", (mNumerator / mDenominator));
            else
                printf("%d/%dx ", mNumerator, mDenominator);
            if (bNumerator < 0)
                printf("- ");
            else
                printf("+ ");
            if (bNumerator % bDenominator == 0)
                printf("%d\n", (bNumerator / bDenominator));
            else
                printf("%d/%d\n", abs(bNumerator), bDenominator);
        }
    }
}
// a1y = b1x + c1
// a2y = b2x + c2
// y = b2x +c2 / a2
// a1b2x + a1c2 = a2b1x + a2c1
// x12 = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1)
void findingTheIntersectionPoint()
{
    double a1, b1, c1;
    double a2, b2, c2;
    double a3, b3, c3;
    double x12, y12, x23, y23, x13, y13;
    scanf("%lf %lf %lf", &a1, &b1, &c1);
    scanf("%lf %lf %lf", &a2, &b2, &c2);
    scanf("%lf %lf %lf", &a3, &b3, &c3);
    x12 = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);
    y12 = (-b1 * c2 + b2 * c1) / (a1 * b2 - b1 * a2);
    x23 = (a3 * c2 - a2 * c3) / (a2 * b3 - a3 * b2);
    y23 = (-b2 * c3 + b3 * c2) / (a2 * b3 - a3 * b2);
    x13 = (a3 * c1 - a1 * c3) / (a1 * b3 - a3 * b1);
    y13 = (-b1 * c3 + b3 * c1) / (a1 * b3 - a3 * b1);
    if (x12 == x23 && x23 == x13)
    {
        if (y12 > y23)
        {
            swap(&x12, &x23);
            swap(&y12, &y23);
        }
        if (y12 > y13)
        {
            swap(&x12, &x13);
            swap(&y12, &y13);
        }
        if (y23 > y13)
        {
            swap(&x23, &x13);
            swap(&y23, &y13);
        }
    }
    else
    {
        if (x12 > x23)
        {
            swap(&x12, &x23);
            swap(&y12, &y23);
        }

        if (x12 > x13)
        {
            swap(&x12, &x13);
            swap(&y12, &y13);
        }

        if (x23 > x13)
        {
            swap(&x23, &x13);
            swap(&y23, &y13);
        }
    }
    if (x12 == -0.000000)
    {
        x12 = abs(x12);
    }
    if (x23 == -0.000000)
    {
        x23 = abs(x23);
    }
    if (x13 == -0.000000)
    {
        x13 = abs(x13);
    }
    if (y12 == -0.000000)
    {
        y12 = abs(y12);
    }
    if (y23 == -0.000000)
    {
        y23 = abs(y23);
    }
    if (y13 == -0.000000)
    {
        y13 = abs(y13);
    }
    printf("(%.2f, %.2f)\n", x12, y12);
    printf("(%.2f, %.2f)\n", x23, y23);
    printf("(%.2f, %.2f)\n", x13, y13);
}

void negativeHanding(int *Numerator, int *Denominator)
{
    if (*Numerator > 0 && *Denominator < 0 || *Numerator < 0 && *Denominator < 0)
    { //-1/1 1/1
        *Numerator *= -1;
        *Denominator *= -1;
    }
}