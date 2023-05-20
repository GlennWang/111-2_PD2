#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void baseballgame(char Team[], int hits, int performance[9][3]);
int swap(int index, int performance[9][3]);

int main()
{
    const int TEAMSIZE = 9;
    char hitter[9][29];
    int hits[9];
    int Hitsum;
    char Team[89];
    int performance[9][3];

    for (int i = 0; i < TEAMSIZE; i++)
    {
        scanf("%d %[^\n]", &hits[i], hitter[i]); // %d讀取個人打擊次數 4 %[^\n]讀取後面所有字串 1B SO GO FO
    }

    for (int i = 0; i < TEAMSIZE; i++)
    {
        Hitsum += hits[i]; // 把所有打擊次數給加總 方便傳入函式baseballgame判斷迴圈大小
        performance[i][0] = i + 1;
        performance[i][1] = 0;
        performance[i][2] = 0;
    }
    for (int i = 0; i < TEAMSIZE; i++)
    {
        int inputIndex = 0;
        int orderIndex = i;

        for (int j = 0; j < hits[i]; j++)
        {
            Team[orderIndex] = hitter[i][inputIndex]; // 按照打擊順序把相對應的打擊情況放入陣列
            orderIndex += TEAMSIZE;                   // 每一個人輪過之後回到第一個人所以+=TEAMSIZE
            inputIndex += 3;                          // 1B SO GO FO 取 1 S G F 每個相差3所以+=3
        }
    }
    baseballgame(Team, Hitsum, performance);
    for (int i = 0; i < TEAMSIZE - 1; i++)
    {
        for (int j = 0; j < TEAMSIZE - 1 - i; j++)
        {
            if (performance[j][2] < performance[j + 1][2])
            {
                swap(j, performance);
            }
            else if (performance[j][2] == performance[j + 1][2])
            {
                if (performance[j][1] < performance[j + 1][1])
                {
                    swap(j, performance);
                }
                else if (performance[j][1] == performance[j + 1][1])
                {
                    if (performance[j][0] > performance[j + 1][0])
                    {
                        swap(j, performance);
                    }
                }
            }
        }
    }

    for (int i = 0; i < TEAMSIZE; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", performance[i][j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}

void baseballgame(char Team[], int hits, int performance[9][3])
{
    int b1 = 0, b2 = 0, b3 = 0;
    int round = 1, outs = 0, score = 0, totalScore = 0;
    for (int i = 0, player = 0; i < hits; i++, player++)
    {
        if (player == 9)
        {
            player = 0;
        }
        if (Team[i] == '1')
        {
            performance[player][1]++;
            if (b3 == 1)
            {
                performance[player][2]++;
                score++;
            }
            b3 = b2;
            b2 = b1;
            b1 = 1;
        }
        else if (Team[i] == '2')
        {
            performance[player][1]++;
            if (b3 == 1)
            {
                performance[player][2]++;
                score++;
            }
            if (b2 == 1)
            {
                performance[player][2]++;
                score++;
            }
            b3 = b1;
            b2 = 1;
            b1 = 0;
        }
        else if (Team[i] == '3')
        {
            performance[player][1]++;
            if (b3 == 1)
            {
                performance[player][2]++;
                score++;
            }
            if (b2 == 1)
            {
                performance[player][2]++;
                score++;
            }
            if (b1 == 1)
            {
                performance[player][2]++;
                score++;
            }
            b3 = 1;
            b2 = b1 = 0;
        }
        else if (Team[i] == 'H')
        {
            performance[player][1]++;
            performance[player][2]++;
            score++;
            if (b3 == 1)
            {
                performance[player][2]++;
                score++;
            }
            if (b2 == 1)
            {
                performance[player][2]++;
                score++;
            }
            if (b1 == 1)
            {
                performance[player][2]++;
                score++;
            }
            b1 = b2 = b3 = 0;
        }
        else
        {
            outs++;
            if (outs == 3) // 出局
            {
                totalScore += score;
                round++;
                b1 = b2 = b3 = 0;
                score = 0;
                outs = 0;
            }
            // else if (outs == 3 & round > 2)
            // {
            //     totalScore += score;
            // }
        }
    }

    printf("%d\n", totalScore);
    // printf("%d %d %d\n", b1, b2, b3);
}

int swap(int index, int performance[9][3])
{
    for (int element = 0; element < 3; element++)
    {
        int temp[1][1];
        temp[0][0] = performance[index + 1][element];
        performance[index + 1][element] = performance[index][element];
        performance[index][element] = temp[0][0];
    }
    return 0;
}