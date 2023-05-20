#include <stdio.h>

int ReadDFExpression(char df_expression[], int image[500][500], int width, int *index, int *x, int *y, int position);

int main()
{
    char DF_expression[100];
    int image[500][500];
    int width;
    int df_index = -1, x_index = 0, y_index = 0;
    int number_of_black = 0;
    scanf("%s", DF_expression);
    scanf("%d", &width);
    number_of_black = ReadDFExpression(DF_expression, image, width, &df_index, &x_index, &y_index, 4);
    if (number_of_black == 0)
    {
        return printf("all white");
    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j] == 1)
            {
                printf("%d,%d\n", i, j);
            }
        }
    }
    // for (int i = 0; i < width; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {
    //         printf("%d", image[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}
// 需要知道現在是左上右上左下右下哪邊

int ReadDFExpression(char df_expression[], int image[500][500], int width, int *index, int *x, int *y, int position)
{
    *index += 1;
    int current_x = *x;
    int current_y = *y;
    if (df_expression[*index] == '0')
    {
        for (int i = 0; i < width; i++)
        {
            if (i > 0)
            {
                *x += 1;
            }
            for (int j = 0; j < width; j++)
            {
                if (j > 0)
                {
                    *y += 1;
                }
                image[*x][*y] = 0;
            }
            *y = current_y;
        }
        *x = current_x;
        // if (position == 0)
        // {
        //     *x = current_x + width;
        //     *y = current_y;
        // }
        // else if (position == 1)
        // {
        //     *x = current_x - width;
        //     *y = current_y + width;
        // }
        // else if (position == 2)
        // {
        //     *x = current_x + width;
        //     *y = current_y;
        // }

        return 0;
    }
    else if (df_expression[*index] == '1')
    {
        for (int i = 0; i < width; i++)
        {
            if (i > 0)
            {
                *x += 1;
            }
            for (int j = 0; j < width; j++)
            {
                if (j > 0)
                {
                    *y += 1;
                }
                image[*x][*y] = 1;
            }
            *y = current_y;
        }
        *x = current_x;
        // if (position == 0)
        // {
        //     *x = current_x + width;
        //     *y = current_y;
        // }
        // else if (position == 1)
        // {
        //     *x = current_x - width;
        //     *y = current_y + width;
        // }
        // else if (position == 2)
        // {
        //     *x = current_x + width;
        //     *y = current_y;
        // }
        return width * width;
    }
    else if (df_expression[*index] == '2')
    {
        int count = 0;
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
            {
                current_x = *x;
                current_y = *y;
            }
            if (i == 1)
            {
                current_x = *x;
                current_y = *y + (width / 2);
            }
            if (i == 2)
            {
                current_x = *x + (width / 2);
                current_y = *y;
            }
            if (i == 3)
            {
                current_x = *x + (width / 2);
                current_y = *y + (width / 2);
            }
            count += ReadDFExpression(df_expression, image, width / 2, index, &current_x, &current_y, i);
        }
        return count;
    }
}
