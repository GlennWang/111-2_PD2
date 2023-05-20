#include <stdio.h>
#include <math.h>

int ConvertBinaryToDecimal(long long number);
long long ConvertDecimalToBinary(int number);
int IC(int M);

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
    int i = 1;
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

int IC(int M)
{
    int numberlist[100];
    int index = 0;
    long long binary;
    while (1)
    {
        if (M == 0)
        {
            printf("0000\nNo Feedback\n");
            break;
        }
        else if (M == 1)
        {
            binary = ConvertDecimalToBinary(index);
            if ((binary - 1000) < 0)
            {
                printf("0%lld\n", binary);
            }
            else
            {
                printf("%lld\n", binary);
            }

            for (int number_index = 0; number_index < index - 1; number_index++)
            {
                printf("%d ", numberlist[number_index]);
            }
            printf("1\n");
            break;
        }
        else if (M % 2 == 0)
        {
            M /= 2;
            numberlist[index] = M;
            index++;
        }
        else if (M % 2 != 0)
        {
            M = ((M + 1) / 2);
            numberlist[index] = M;
            index++;
        }
    }
}