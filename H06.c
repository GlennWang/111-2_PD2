#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int baseballgame(char Team[], int hits);

int main()
{
    const int TEAMSIZE = 5;
    char Ahitter[5][14], Bhitter[5][14];
    int Ahits[5], Bhits[5];
    int AHitSum, BHitSum;
    char ATeam[25], BTeam[25];
    int Ascore, Bscore;

    for (int i = 0; i < TEAMSIZE; i++)
    {
        scanf("%d %[^\n]", &Ahits[i], Ahitter[i]); // %d讀取個人打擊次數 4 %[^\n]讀取後面所有字串 1B SO GO FO
    }
    for (int i = 0; i < TEAMSIZE; i++)
    {
        scanf("%d %[^\n]", &Bhits[i], Bhitter[i]);
    }
    for (int i = 0; i < TEAMSIZE; i++)
    {
        AHitSum += Ahits[i]; // 把所有打擊次數給加總 方便傳入函式baseballgame判斷迴圈大小
        BHitSum += Bhits[i];
    }
    for (int i = 0; i < TEAMSIZE; i++)
    {
        int AinputIndex = 0;
        int AorderIndex = i;
        int BinputIndex = 0;
        int BorderIndex = i;
        for (int j = 0; j < Ahits[i]; j++)
        {
            ATeam[AorderIndex] = Ahitter[i][AinputIndex]; // 按照打擊順序把相對應的打擊情況放入陣列
            AorderIndex += TEAMSIZE;                      // 每一個人輪過之後回到第一個人所以+=TEAMSIZE
            AinputIndex += 3;                             // 1B SO GO FO 取 1 S G O 每個相差3所以+=3
        }
        for (int j = 0; j < Bhits[i]; j++)
        {
            BTeam[BorderIndex] = Bhitter[i][BinputIndex];
            BorderIndex += TEAMSIZE;
            BinputIndex += 3;
        }
    }

    Ascore = baseballgame(ATeam, AHitSum);
    Bscore = baseballgame(BTeam, BHitSum);

    if (Ascore > Bscore)
    {
        printf("A");
    }
    else if (Bscore > Ascore)
    {
        printf("B");
    }
    else
    {
        printf("Tie");
    }
    return 0;
}

int baseballgame(char Team[], int hits)
{
    int b1 = 0, b2 = 0, b3 = 0;
    int round = 1, outs = 0, score = 0, totalScore = 0;
    for (int i = 0; i < hits; i++)
    {
        if (Team[i] == '1')
        {
            if (b3 == 1)
            {
                score++;
            }
            b3 = b2;
            b2 = b1;
            b1 = 1;
        }
        else if (Team[i] == '2')
        {
            if (b3 == 1)
            {
                score++;
            }
            if (b2 == 1)
            {
                score++;
            }
            b3 = b1;
            b2 = 1;
            b1 = 0;
        }
        else if (Team[i] == '3')
        {
            if (b3 == 1)
            {
                score++;
            }
            if (b2 == 1)
            {
                score++;
            }
            if (b1 == 1)
            {
                score++;
            }
            b3 = 1;
            b2 = b1 = 0;
        }
        else if (Team[i] == 'H')
        {
            score++;
            if (b3 == 1)
            {
                score++;
            }
            if (b2 == 1)
            {
                score++;
            }
            if (b1 == 1)
            {
                score++;
            }
            b1 = b2 = b3 = 0;
        }
        else
        {
            outs++;
            if (outs == 3 & round < 3) // 出局
            {
                totalScore += score;
                round++;
                b1 = b2 = b3 = 0;
                score = 0;
                outs = 0;
            }
            else if (outs == 3 & round > 2)
            {
                totalScore += score;
            }
        }
    }

    printf("%d\n", totalScore);
    printf("%d %d %d\n", b1, b2, b3);
    return totalScore;
}
