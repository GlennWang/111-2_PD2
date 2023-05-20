#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Operate(char op1, char op2, int d1[6], int d2[6], int d3[6]);
void rollforward(int d[6]);
void rollright(int d[6]);
void rollleft(int d[6]);
void swap(int d1[6], int d2[6]);

int main()
{
    int dice1[6] = {5, 1, 2, 6, 3, 4}; // 水平的index 0 1 2 3 垂直從上到下4、5
    int dice2[6] = {5, 1, 2, 6, 3, 4}; // 因此上前右的index是1、5、2
    int dice3[6] = {5, 1, 2, 6, 3, 4}; // 前5、上1、後4、下3、右2、左0
    // 1 3 6 4 2 5
    int N;
    scanf("%d ", &N);
    for (int i = 0; i < N; i++)
    {
        char Op1;
        char Op2;
        scanf("%c ", &Op1);
        scanf("%c", &Op2);
        getchar();
        Operate(Op1, Op2, dice1, dice2, dice3);
    }

    printf("%d %d %d %d %d %d\n", dice1[5], dice1[1], dice1[4], dice1[3], dice1[2], dice1[0]);
    printf("%d %d %d %d %d %d\n", dice2[5], dice2[1], dice2[4], dice2[3], dice2[2], dice2[0]);
    printf("%d %d %d %d %d %d", dice3[5], dice3[1], dice3[4], dice3[3], dice3[2], dice3[0]);
}

void Operate(char op1, char op2, int d1[6], int d2[6], int d3[6])
{
    if (op1 == 'L')
    {
        if (op2 == '1')
        {
            rollforward(d1);
        }
        if (op2 == '2')
        {
            rollleft(d1);
        }
        if (op2 == '3')
        {
            rollright(d1);
        }
        if (op2 == 'M')
        {
            swap(d1, d2);
        }
        if (op2 == 'R')
        {
            swap(d1, d3);
        }
    }
    else if (op1 == 'M')
    {
        if (op2 == '1')
        {
            rollforward(d2);
        }
        if (op2 == '2')
        {
            rollleft(d2);
        }
        if (op2 == '3')
        {
            rollright(d2);
        }
        if (op2 == 'L')
        {
            swap(d2, d1);
        }
        if (op2 == 'R')
        {
            swap(d2, d3);
        }
    }
    else if (op1 == 'R')
    {
        if (op2 == '1')
        {
            rollforward(d3);
        }
        if (op2 == '2')
        {
            rollleft(d3);
        }
        if (op2 == '3')
        {
            rollright(d3);
        }
        if (op2 == 'L')
        {
            swap(d3, d1);
        }
        if (op2 == 'M')
        {
            swap(d3, d2);
        }
    }
}
//   4
// 0 1 2 3
//   5
void rollforward(int d[6])
{
    int temp[6] = {d[0], d[4], d[2], d[5], d[3], d[1]};
    for (int i = 0; i < 6; i++)
    {
        d[i] = temp[i];
    }
}
void rollright(int d[6])
{
    int temp[6] = {d[3], d[0], d[1], d[2], d[4], d[5]};
    for (int i = 0; i < 6; i++)
    {
        d[i] = temp[i];
    }
}
void rollleft(int d[6])
{
    int temp[6] = {d[1], d[2], d[3], d[0], d[4], d[5]};
    for (int i = 0; i < 6; i++)
    {
        d[i] = temp[i];
    }
}

void swap(int d1[6], int d2[6])
{
    for (int i = 0; i < 6; i++)
    {
        int temp = d1[i];
        d1[i] = d2[i];
        d2[i] = temp;
    }
}