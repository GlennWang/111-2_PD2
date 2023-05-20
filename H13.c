#include <stdio.h>
#include <math.h>

int ConvertBinaryToDecimal(long long number);
long long ConvertDecimalToBinary(int number);
int DigitsNumber(long long number);
int IC(int N);
int T(int N);
int R(int N);
int C(int N);

int main()
{
    while (1)
    {
        long long n;
        scanf(" %lld", &n);
        if (n == -1)
        {
            break;
        }
        IC(ConvertBinaryToDecimal(n));
    }
    return 0;
}

int ConvertBinaryToDecimal(long long number)
{
    int decimal_number = 0;
    int i = 0;
    int remainder;
    while (number != 0)
    {
        remainder = number % 10;
        number /= 10;
        decimal_number += remainder * pow(2, i);
        ++i;
    }
    return decimal_number;
}

long long ConvertDecimalToBinary(int number)
{
    long long binary_number = 0;
    long long int i = 1;
    int remainder;
    while (number != 0)
    {
        remainder = number % 2;
        number /= 2;
        binary_number += remainder * i;
        i *= 10;
    }
    return binary_number;
}

int DigitsNumber(long long number)
{
    int digitsnumber = 0;
    while (number != 0)
    {
        number /= 10;
        ++digitsnumber;
    }
    return digitsnumber;
}

int IC(int N)
{
    T(N);
    return 0;
}

int T(int N)
{
    long long binary;
    int sum = 0;
    int digits_number;
    for (int count = 1; count < N + 1; count++)
    {
        sum += R(count);
    }
    binary = ConvertDecimalToBinary(sum);
    digits_number = DigitsNumber(binary);
    for (int zero = 0; zero < (14 - digits_number); zero++)
    {
        printf("0");
    }
    if (digits_number != 0)
    {
        printf("%lld\n", binary);
    }
    else
    {
        printf("\n");
    }
    return 0;
}

int R(int N)
{
    return C(N);
}

int C(int N)
{
    int R = 0;
    while (1)
    {
        if (N == 0 || N == 1)
        {
            return R;
        }
        else if (N % 2 == 0)
        {
            N /= 2;
            R++;
        }
        else if (N % 2 != 0)
        {
            N = ((N + 1) / 2);
            R++;
        }
    }
}