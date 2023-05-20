#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char S[1000], sub_sentence[100][100][100], temp[500], main_sentence[100][100];
    int t, number_of_words = 0, number_of_letters = 0, sentence_index = 0, i, j, word_count_list[100];
    int Isrepeated = 0, number_of_complementary_words = 0, sum_of_words = 0, number_of_next_words = 0;
    // 讀取主要字串。
    gets(S);
    // 讀取 N
    scanf(" %d ", &t);
    // 讀取 N 個字串，並且存入三維陣列
    for (i = 1; i <= t; i++)
    {
        gets(temp);
        // 遇到結尾字符才會停止
        while (temp[sentence_index] != '\0')
        {
            // 如果遇到空格
            if (temp[sentence_index] == ' ')
            {
                sub_sentence[i][number_of_words][number_of_letters] = '\0'; // 給單字加上結尾符號
                number_of_words++;                                          // 下一個單字
                number_of_letters = 0;                                      // 單字的字母數量歸零
            }
            else
            {
                sub_sentence[i][number_of_words][number_of_letters] = temp[sentence_index]; // 把當前引索的字母儲存在對應位置
                number_of_letters++;                                                        // 字母數量增加
            }
            sentence_index++; // 主字串引索
        }
        sub_sentence[i][number_of_words][number_of_letters] = '\0'; // 為最後一個單字加上結尾符號
        word_count_list[i] = number_of_words + 1;                   // 儲存當前子句子有幾個單字，方便接下來遍歷
        sentence_index = 0;                                         // 主字串引索歸零
        number_of_words = 0;                                        // 單字數量歸零
        number_of_letters = 0;                                      // 字母數量歸零
    }
    // 循環每一個子句
    for (i = 1; i <= t; i++)
    {
        // 比較其他子句，且已經比較過的不會再比一次
        for (j = i + 1; j <= t; j++)
        {
            // 循環當前子句每一個單字
            for (number_of_words = 0; number_of_words < word_count_list[i]; number_of_words++)
            {
                for (number_of_next_words = 0; number_of_next_words < word_count_list[j]; number_of_next_words++)
                {
                    if (strcmp(sub_sentence[i][number_of_words], sub_sentence[j][number_of_next_words]) == 0)
                        Isrepeated = 1;
                }
            }
            // 如果沒有重複
            if (Isrepeated == 0)
            {
                sentence_index = 0;
                number_of_words = 0;
                number_of_letters = 0;
                // 用同樣方法把主字串儲存
                while (S[sentence_index] != '\0')
                {
                    if (S[sentence_index] == ' ')
                    {
                        main_sentence[number_of_words][number_of_letters] = '\0';
                        number_of_words++;
                        number_of_letters = 0;
                    }
                    else
                    {
                        main_sentence[number_of_words][number_of_letters] = S[sentence_index];
                        number_of_letters++;
                    }
                    sentence_index++;
                }
                main_sentence[number_of_words][number_of_letters] = '\0';
                int number_of_main_sentence_words = number_of_words + 1;
                // 主字串的所有單字跟兩個子字串的單字比較
                for (number_of_words = 0; number_of_words < number_of_main_sentence_words; number_of_words++)
                {
                    for (number_of_next_words = 0; number_of_next_words < word_count_list[i]; number_of_next_words++)
                    {
                        if (strcmp(main_sentence[number_of_words], sub_sentence[i][number_of_next_words]) == 0)
                        {
                            sum_of_words += 1;
                            strcpy(main_sentence[number_of_words], main_sentence[100]);
                        }
                    }
                    for (number_of_next_words = 0; number_of_next_words < word_count_list[j]; number_of_next_words++)
                    {
                        if (strcmp(main_sentence[number_of_words], sub_sentence[j][number_of_next_words]) == 0)
                        {
                            sum_of_words += 1;
                            strcpy(main_sentence[number_of_words], main_sentence[100]);
                        }
                    }
                }
                // 如果數量相同就是互補字串
                if (sum_of_words == number_of_main_sentence_words)
                    number_of_complementary_words++;
            }
            sum_of_words = 0;
            Isrepeated = 0;
        }
    }
    printf("%d", number_of_complementary_words);
}
