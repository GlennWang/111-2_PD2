#include <stdio.h>
#include <string.h>

void ReverseAndAssignment(int big_number[], char buf_number[], int number_len);
void Assignment(int big_number[], int result_number[], int number_len);
int CheckBigNumberStartIndex(int big_number[]);
int CheckResultNumberStartIndex(int result_number[]);
int GreaterJudge(int big_number1[], int big_number2[]);
void Mul(int big_number1[], int big_number2[], int result_number[]);
void Div(int big_number1[], int big_number2[], int result_number[]);
int Dsub(int big_number1[], int big_number2[], int result_number[]);

void PrintBigNumber(int result_number[]);

int main()
{
    char buf_number1[50];
    char buf_number2[50];
    int number1[50] = {0};
    int number2[50] = {0};
    int result[101] = {0};
    scanf("%s %s", buf_number1, buf_number2);
    int numberone_len = strlen(buf_number1);
    int numbertwo_len = strlen(buf_number2);

    ReverseAndAssignment(number1, buf_number1, numberone_len);
    ReverseAndAssignment(number2, buf_number2, numbertwo_len);
    Div(number1, number2, result);
    PrintBigNumber(result);
}

void ReverseAndAssignment(int big_number[], char buf_number[], int number_len)
{
    for (int bufindex = (number_len - 1), numberindex = 0; bufindex >= 0; bufindex--, numberindex++)
    {
        big_number[numberindex] = buf_number[bufindex] - '0';
    }
}

void Assignment(int big_number[], int result_number[], int number_len)
{
    for (int index = 0; index < number_len + 1; index++)
    {
        result_number[index] = big_number[index];
    }
}

int CheckBigNumberStartIndex(int big_number[])
{
    for (int index = 49; index >= 0; index--)
    {
        if (big_number[index] != 0)
        {
            return index;
        }
    }
}

int CheckResultNumberStartIndex(int result_number[])
{
    for (int index = 100; index >= 0; index--)
    {
        if (result_number[index] != 0)
        {
            return index;
        }
    }
}

int GreaterJudge(int big_number1[], int big_number2[])
{
    int number1_len = CheckBigNumberStartIndex(big_number1);
    int number2_len = CheckBigNumberStartIndex(big_number2);
    // printf("%d %d\n", number1_len, number2_len);
    if (number2_len > number1_len)
    {
        return 1;
    }
    else if (number1_len > number2_len)
    {
        return 0;
    }
    else if (number1_len == number2_len)
    {
        for (int index = number1_len; index >= 0; index--)
        {
            // printf("b1 :%d b2 :%d\n", big_number1[index], big_number2[index]);
            if (big_number1[index] < big_number2[index])
            {
                return 1;
            }
            else if (big_number1[index] > big_number2[index])
            {
                return 0;
            }
        }
        return 0; // 每個數字都一樣
    }
}

int Dsub(int big_number1[], int big_number2[], int result_number[])
{
    int carry = 0;
    int isgreater = GreaterJudge(big_number1, big_number2);
    if (isgreater)
    {
        return 0;
    }
    else
    {
        for (int index = 0; index < 50; index++)
        {
            result_number[index] = big_number1[index] - big_number2[index] + carry;
            if (result_number[index] < 0)
            {
                result_number[index] += 10;
                carry = -1;
            }
            else
            {
                carry = 0;
            }
        }
        return 1;
    }
}

void Mul(int big_number1[], int big_number2[], int result_number[])
{
    for (int indexone = 0; indexone < 50; indexone++)
    {
        for (int indextwo = 0; indextwo < 50; indextwo++)
        {
            result_number[indexone + indextwo] += big_number1[indexone] * big_number2[indextwo];
            if (result_number[indexone + indextwo] >= 10)
            {
                result_number[indexone + indextwo + 1] += result_number[indexone + indextwo] / 10;
                result_number[indexone + indextwo] = result_number[indexone + indextwo] % 10;
            }
        }
    }
}

void Div(int big_number1[], int big_number2[], int result_number[])
{
    int isgreater = GreaterJudge(big_number1, big_number2);
    if (isgreater == 1)
    {
        printf("0\n");
        Assignment(big_number1, result_number, CheckBigNumberStartIndex(big_number1));
    }
    else if (isgreater == 0)
    {
        long long int count = 0;
        int stop = 1;
        int ten_million[50] = {0};
        ten_million[7] = 1;
        int temp_number[50] = {0};
        int temp_result[101] = {0};
        Assignment(big_number2, temp_number, CheckBigNumberStartIndex(big_number2));
        Mul(temp_number, ten_million, temp_result);
        while (1)
        {
            stop = Dsub(big_number1, temp_result, big_number1);
            if (stop == 0)
            {
                // printf("test\n");
                break;
            }
            count += 10000000;
        }
        while (Dsub(big_number1, big_number2, big_number1))
        {
            count++;
        }

        printf("%lld\n", count);
        Assignment(big_number1, result_number, CheckBigNumberStartIndex(big_number1));
    }
}

void PrintBigNumber(int result_number[])
{
    int start = 0;
    start = CheckResultNumberStartIndex(result_number);
    if (start)
    {
        for (int index = start; index >= 0; index--)
        {
            printf("%d", result_number[index]);
        }
    }
    else
    {
        printf("0");
    }
}