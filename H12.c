#include <stdio.h>
#include <string.h>

int main()
{
    char C;
    char buf_number1[50];
    char buf_number2[50];
    int number1[50];
    int number2[50];
    int result[101];
    scanf("%c %s %s", &C, buf_number1, buf_number2);
    int numberone_len = strlen(buf_number1);
    int numbertwo_len = strlen(buf_number2);
    int isgreater = numbertwo_len > numberone_len ? 1 : 0;

    for (int index = 0; index < 50; index++)
    {
        number1[index] = 0;
        number2[index] = 0;
    }
    for (int index = 0; index < 101; index++)
    {
        result[index] = 0;
    }
    for (int bufindex = (numberone_len - 1), numberindex = 0; bufindex >= 0; bufindex--, numberindex++)
    {
        number1[numberindex] = buf_number1[bufindex] - '0';
        // printf("%d", number1[numberindex]);
    }
    for (int bufindex = (numbertwo_len - 1), numberindex = 0; bufindex >= 0; bufindex--, numberindex++)
    {
        number2[numberindex] = buf_number2[bufindex] - '0';
        // printf("%d", number2[numberindex]);
    }
    if (C == '+')
    {
        int carry = 0;
        int start;
        for (int index = 0; index < 50; index++)
        {
            result[index] = number1[index] + number2[index] + carry;
            if (result[index] >= 10)
            {
                result[index] -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }
        for (int index = 49; index >= 0; index--)
        {
            if (result[index] != 0)
            {
                start = index;
                break;
            }
        }
        for (int index = start; index >= 0; index--)
        {
            printf("%d", result[index]);
        }
    }
    else if (C == '-')
    {
        int carry = 0;
        int start = 0;
        if (isgreater)
        {
            for (int index = 0; index < 50; index++)
            {
                result[index] = number2[index] - number1[index] + carry;
                if (result[index] < 0)
                {
                    result[index] += 10;
                    carry = -1;
                }
                else
                {
                    carry = 0;
                }
            }
        }
        else
        {
            for (int index = 0; index < 50; index++)
            {
                result[index] = number1[index] - number2[index] + carry;
                if (result[index] < 0)
                {
                    result[index] += 10;
                    carry = -1;
                }
                else
                {
                    carry = 0;
                }
            }
        }
        for (int index = 49; index >= 0; index--)
        {
            if (result[index] != 0)
            {
                start = index;
                break;
            }
        }
        if (isgreater)
        {
            printf("-");
        }
        if (start)
        {
            for (int index = start; index >= 0; index--)
            {
                printf("%d", result[index]);
            }
        }
        else
        {
            printf("0");
        }
    }
    else if (C == '*')
    {
        int start = 0;
        for (int indexone = 0; indexone < 50; indexone++)
        {
            for (int indextwo = 0; indextwo < 50; indextwo++)
            {
                result[indexone + indextwo] += number1[indexone] * number2[indextwo];
                if (result[indexone + indextwo] >= 10)
                {
                    result[indexone + indextwo + 1] += result[indexone + indextwo] / 10;
                    result[indexone + indextwo] = result[indexone + indextwo] % 10;
                }
            }
        }
        for (int index = 100; index >= 0; index--)
        {
            if (result[index] != 0)
            {
                start = index;
                break;
            }
        }
        for (int index = start; index >= 0; index--)
        {
            printf("%d", result[index]);
        }
    }
}