#include <stdio.h>

char BullsAndCows(char secret_number[]);

int main()
{
    char secret_number[4];
    scanf("%s", secret_number);
    BullsAndCows(secret_number);
    return 0;
}

char BullsAndCows(char secret_number[])
{
    int Time = 0;
    while (Time < 6)
    {
        int X = 0;
        int Y = 0;
        char guess_number[4];
        scanf("%s", guess_number);
        for (int s_index = 0; s_index < 4; s_index++)
        {
            for (int g_index = 0; g_index < 4; g_index++)
            {
                if (guess_number[g_index] == secret_number[s_index])
                {
                    if (g_index == s_index)
                    {
                        X++;
                        if (X == 4)
                        {
                            return printf("win");
                        }
                    }
                    else if (g_index != s_index)
                    {
                        Y++;
                    }
                }
            }
        }
        printf("%dA%dB\n", X, Y);
        Time++;
    }
    return printf("loss");
}