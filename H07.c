#include <stdio.h>
int alpha(int alphabet)
{
    printf("%c", alphabet);
    return 0;
}

int main()
{
    int i, j, N, M, complexCount;
    char input, alphabet = 'A';
    scanf("%d\n%d", &N, &M);
    complexCount = 0;
    if (N < 1 || N > 2)
    {
        return printf("error");
    }
    else if (M < 2 || M > 9)
    {
        return printf("error");
    }

    if (N == 1)
    {
        for (i = M; i >= 1; i--)
        {
            for (j = 1; j <= i - 1; j++)
            {
                printf("#");
            }
            printf("*");

            if (i < M)
            {
                alpha(alphabet);
                printf("*");
                if (complexCount > 0)
                {
                    alpha(alphabet);
                    printf("*");
                }
                if (complexCount > 1)
                {
                    alpha(alphabet);
                    printf("*");
                }
                if (complexCount > 2)
                {
                    alpha(alphabet);
                    printf("*");
                }
                if (complexCount > 3)
                {
                    alpha(alphabet);
                    printf("*");
                }
                if (complexCount > 4)
                {
                    alpha(alphabet);
                    printf("*");
                }
                if (complexCount > 5)
                {
                    alpha(alphabet);
                    printf("*");
                }
                if (complexCount > 6)
                {
                    alpha(alphabet);
                    printf("*");
                }
                alphabet++;

                if (alphabet == 'D')
                {
                    alphabet = 'A';
                }
                complexCount++;
            }
            for (j = 1; j <= i - 1; j++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    else if (N == 2)
    {
        for (i = 1; i <= M; i++)
        {
            for (j = 1; j <= i; j++)
            {
                printf("%d", j);
            }
            for (j = (M - (i - 1)) * 2; j >= 1; j--)
            {
                printf("*");
            }
            for (j = i; j >= 1; j--)
            {
                printf("%d", j);
            }
            printf("\n");
        }
    }

    return 0;
}
