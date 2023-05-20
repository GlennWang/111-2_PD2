#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int sequence[], int left, int right);

int main()
{
    int split, strlen = 0, sequence[50];
    char index_char;
    int subsquence[100][100];
    scanf("%d ", &split);
    // 讀取帶空格字串方法

    // getchar(); // 這行為了吸收上一格的換行，不寫這行會直接結束，也可以直接在上面的%d後面加一個空格
    // 方法一
    // gets(sequence);
    // 直接就可以讀取
    // 缺點是直接讀下來不能直接處理

    // 方法二
    while ((index_char = getchar()) != '\n' && index_char != EOF)
    {
        if (index_char != ' ')
        {
            sequence[strlen] = index_char - '0';
            strlen++;
        }
    }
    // 缺點是看起來比較長
    int end = strlen - split;
    int count = 0;
    for (int start = 0; start <= end; start++)
    {
        if (check(sequence, start, start + split))
        {
            int subindex = 0;
            for (int i = start; i < start + split; i++)
            {
                subsquence[count][subindex] = sequence[i];
                subindex++;
            }
            count++;
        }
    }
    printf("%d\n", count);

    for (int element = split - 1; element >= 0; element--)
    {
        for (int subsquence_index_one = 0; subsquence_index_one < count - 1; subsquence_index_one++)
        {
            for (int subsquence_index_two = 0; subsquence_index_two < count - 1 - subsquence_index_one; subsquence_index_two++)
            {
                if (subsquence[subsquence_index_two][element] > subsquence[subsquence_index_two + 1][element])
                {
                    for (int element_index = split - 1; element_index >= 0; element_index--)
                    {
                        int temp = subsquence[subsquence_index_two][element_index];
                        subsquence[subsquence_index_two][element_index] = subsquence[subsquence_index_two + 1][element_index];
                        subsquence[subsquence_index_two + 1][element_index] = temp;
                    }
                }
            }
        }
    }

    for (int subsquence_index = 0; subsquence_index < count; subsquence_index++)
    {
        int samecount = 0;
        if (subsquence_index > 0)
        {
            for (int element = 0; element < split; element++)
            {
                if (subsquence[subsquence_index][element] == subsquence[subsquence_index - 1][element])
                {
                    samecount++;
                }
            }
        }
        if (samecount == split)
        {
            samecount = 0;
            continue;
        }
        for (int element = 0; element < split; element++)
        {
            printf("%d ", subsquence[subsquence_index][element]);
        }
        printf("\n");
    }
}

int check(int sequence[], int left, int right)
{
    for (int i = left; i < right; i++)
    {
        for (int j = left; j < right; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (sequence[i] == sequence[j])
            {
                return 0;
            }
        }
    }
    return 1;
}