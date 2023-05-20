#include <stdio.h>
int main()
{
    char hit;
    int b1 = 0, b2 = 0, b3 = 0, outs = 0, score = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf(" %c", &hit);
        if (hit == '1')
        {
            if (b3 == 1)
            {
                score++;
            }
            b3 = b2;
            b2 = b1;
            b1 = 1;
        }
        else if (hit == '2')
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
        else if (hit == '3')
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
        else if (hit == 'H')
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
            if (outs >= 3) // 出局
            {
                b1 = b2 = b3 = 0;
                score = 0;
                outs = 0;
            }
        }
    }

    printf("%d\n", score);
    printf("%d %d %d", b1, b2, b3);
}
