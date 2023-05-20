#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int x, int y);
void fractionHandling(int *Numerator, int *Denominator, char *Fraction);
void add(int n1, int d1, int n2, int d2, int *answerN, int *answerD);
void sub(int n1, int d1, int n2, int d2, int *answerN, int *answerD);
void mul(int n1, int d1, int n2, int d2, int *answerN, int *answerD);
void division(int n1, int d1, int n2, int d2, int *answerN, int *answerD);
void printAnswer(int answerN, int answerD);

int main()
{
    char *Fraction1, *Fraction2;
    int strlen = 15;
    int Numerator1, Denominator1, Numerator2, Denominator2;
    int answerNumerator, answerDenominator;
    char operator, continueComputing;
    do
    {
        Fraction1 = malloc(strlen * sizeof(char));
        Fraction2 = malloc(strlen * sizeof(char));
        scanf("%s %s %c %c", Fraction1, Fraction2, &operator, & continueComputing);
        fractionHandling(&Numerator1, &Denominator1, Fraction1);
        fractionHandling(&Numerator2, &Denominator2, Fraction2);
        free(Fraction1);
        free(Fraction2);
        if (Denominator1 == 0 || Denominator2 == 0)
            printf("error\n"); // n1/0 n1/0
        else if (operator== '/' && Denominator2 == 0)
            printf("error\n"); // n1/d1 * d2/0
        else
        {
            switch (operator)
            {
            case '+':
                add(Numerator1, Denominator1, Numerator2, Denominator2, &answerNumerator, &answerDenominator);
                break;
            case '-':
                sub(Numerator1, Denominator1, Numerator2, Denominator2, &answerNumerator, &answerDenominator);
                break;
            case '*':
                mul(Numerator1, Denominator1, Numerator2, Denominator2, &answerNumerator, &answerDenominator);
                break;
            case '/':
                division(Numerator1, Denominator1, Numerator2, Denominator2, &answerNumerator, &answerDenominator);
                break;
            }
            printAnswer(answerNumerator, answerDenominator);
        }
    } while (continueComputing == 'y');
    return 0;
}

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

void fractionHandling(int *Numerator, int *Denominator, char *Fraction)
{
    char string[15];
    int fractionlen = strlen(Fraction);
    int temp[3][1] = {0, 0, 0};
    int sign = 1;
    strcpy(string, &Fraction[0]);
    temp[0][0] = atoi(string);
    for (int i = 0; i < fractionlen; i++)
    {
        if (Fraction[i] == '(')
        {
            strcpy(string, &Fraction[0]);
            temp[2][0] = atoi(string);
            strcpy(string, &Fraction[i + 1]);
            temp[0][0] = atoi(string);
        }
        if (Fraction[i] == '/')
        {
            strcpy(string, &Fraction[i + 1]);
            temp[1][0] = atoi(string);
        }
    }
    if (temp[0][0] < 0 || temp[1][0] < 0 || temp[2][0] < 0)
    {
        sign = -1;
        temp[0][0] = abs(temp[0][0]);
        temp[1][0] = abs(temp[1][0]);
        temp[2][0] = abs(temp[2][0]);
    }
    *Numerator = sign * (temp[0][0] + (temp[2][0] * temp[1][0]));
    *Denominator = temp[1][0];
}

void add(int n1, int d1, int n2, int d2, int *answerN, int *answerD)
{
    *answerN = n1 * d2 + n2 * d1;
    *answerD = d1 * d2;
}

void sub(int n1, int d1, int n2, int d2, int *answerN, int *answerD)
{
    *answerN = n1 * d2 - n2 * d1;
    *answerD = d1 * d2;
}

void mul(int n1, int d1, int n2, int d2, int *answerN, int *answerD)
{
    *answerN = n1 * n2;
    *answerD = d1 * d2;
}

void division(int n1, int d1, int n2, int d2, int *answerN, int *answerD)
{
    if (n2 < 0)
    {
        n2 *= -1;
        d2 *= -1;
    }
    *answerN = n1 * d2;
    *answerD = d1 * n2;
}

void printAnswer(int answerN, int answerD)
{
    int hcf = gcd(abs(answerN), abs(answerD));
    answerN /= hcf;
    answerD /= hcf;
    if (answerN == 0)
        printf("0\n");
    else if (answerN == answerD)
        printf("1\n");
    else if (abs(answerN) > answerD)
    {
        int sign;
        if (answerN < 0)
        {
            sign = answerN / answerD;
            answerN *= -1;
        }
        else
            sign = answerN / answerD;
        answerN = answerN % answerD;
        if (answerN == 0)
            printf("%d\n", sign);
        else
            printf("%d(%d/%d)\n", sign, answerN, answerD);
    }
    else
        printf("%d/%d\n", answerN, answerD);
}