#include <stdio.h>

int FindOtherQueen(int chess[100][100], int y, int x, int N);

// 搜索完一個的所有可能就把它去掉
// 對於一個點，搜索他座標
// 上(y - number) 下(y + number) 左(x - number) 右(x + number) 左上(y-number)(x-number) 右上(y-number)(x+number) 左下(y+number)(x-number) 右下(y+number)(x+number)
int main()
{
    int chess[100][100]; // y x
    int N;
    char index_char;
    int count;
    scanf("%d ", &N);
    for (int y_index = 0; y_index < N; y_index++)
    {
        int x_index = 0;
        while ((index_char = getchar()) != '\n' && index_char != EOF)
        {
            if (index_char != ' ')
            {
                chess[y_index][x_index] = index_char - '0';
                x_index++;
            }
        }
        x_index = 0;
    }

    for (int y_index = 0; y_index < N; y_index++)
    {
        for (int x_index = 0; x_index < N; x_index++)
        {
            // printf("%d ", chess[y_index][x_index]);
            if (chess[y_index][x_index] == 1)
            {
                chess[y_index][x_index] = 0;
                count += FindOtherQueen(chess, y_index, x_index, N);
            }
        }
        // printf("\n");
    }
    if (count == 0)
    {
        printf("There is no attack.");
    }
    else
    {
        printf("%d", count);
    }

    return 0;
}

int FindOtherQueen(int chess[100][100], int y, int x, int N)
{
    int current_y = y;
    int current_x = x;

    int count = 0;
    // 上
    while (y > 0 && current_y > -1)
    {
        if (chess[current_y--][current_x] == 1)
        {
            count++;
        }
    }
    current_y = y;
    // 下
    while (y < N - 1 && current_y < N)
    {
        if (chess[current_y++][current_x] == 1)
        {
            count++;
        }
    }
    current_y = y;
    // 左
    while (x > 0 && current_x > -1)
    {
        if (chess[current_y][current_x--] == 1)
        {
            count++;
        }
    }
    current_x = x;
    // 右
    while (x < N - 1 && current_x < N)
    {
        if (chess[current_y][current_x++] == 1)
        {
            count++;
        }
    }
    current_x = x;
    // 左上
    while ((y > 0 && current_y > -1) && (x > 0 && current_x > -1))
    {
        if (chess[current_y--][current_x--] == 1)
        {
            count++;
        }
    }
    current_y = y;
    current_x = x;
    // 右上
    while ((y > 0 && current_y > -1) && (x < N - 1 && current_x < N))
    {
        if (chess[current_y--][current_x++] == 1)
        {
            count++;
        }
    }
    current_y = y;
    current_x = x;
    // 左下
    while ((y < N - 1 && current_y < N) && (x > 0 && current_x > -1))
    {
        if (chess[current_y++][current_x--] == 1)
        {
            count++;
        }
    }
    current_y = y;
    current_x = x;
    // 右下
    while ((y < N - 1 && current_y < N) && (x < N - 1 && current_x < N))
    {
        if (chess[current_y++][current_x++] == 1)
        {
            count++;
        }
    }

    return count;
}