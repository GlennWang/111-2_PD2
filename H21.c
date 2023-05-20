#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 500

// 函數的宣告
void process();
void scanWord(char *article, char *words[], int *num_of_words);
void replaceWord(char *article, char *wordP, char *wordQ);
void insertBeforeWord(char *article, char *wordP, char *wordQ);
void insertAfterWord(char *article, char *wordP, char *wordQ);
void deleteWord(char *article, char *wordP);
void wordFrequency(char *article);

// 主函數
int main()
{
    process();
    return 0;
}

// 讀取處理、依照題目使用的函數
void process()
{
    // article存放文章、text複製一份article使用，避免錯誤操作導致遺失。
    char article[SIZE], text[SIZE];
    char wordP[10], wordQ[10];
    gets(article); // 取得文章
    gets(wordP);   // 取得文字
    gets(wordQ);   // 取得文字

    strcpy(text, article);           // 複製文章到text
    replaceWord(text, wordP, wordQ); // 更換單字的函數，傳入text跟兩個文字。
    printf("%s\n", text);

    strcpy(text, article);
    insertBeforeWord(text, wordP, wordQ);
    printf("%s\n", text);

    strcpy(text, article);
    insertAfterWord(text, wordP, wordQ);
    printf("%s\n", text);

    strcpy(text, article);
    deleteWord(text, wordP); // 刪除的函數，傳入text跟兩個文字。
    printf("%s\n", text);

    strcpy(text, article);
    wordFrequency(text);
}

// 取出所有單字存放到words的函數
void scanWord(char *article, char *words[], int *num_of_words)
{
    // 定義變數用於掃描整個文章
    int i = 0, len = strlen(article);
    (*num_of_words) = 0;
    // 首先存下第一個單字
    words[(*num_of_words)++] = &article[i];
    for (i = 0; i < len; i++)
    {
        // 一旦article[i]的值是空格就把該值變成'\0'後i再++
        // 如此一來下一行儲存的時候[i]就會是下一個單字的字首。
        if (article[i] == ' ')
        {
            article[i++] = '\0'; // 把i變成\0再++
            words[(*num_of_words)++] = &article[i];
        }
    }
}

void replaceWord(char *article, char *wordP, char *wordQ)
{
    int i = 0, count = 0;
    char *words[SIZE], text[SIZE];
    strcpy(text, article);
    strcpy(article, "");
    scanWord(text, words, &count);

    for (i = 0; i < count; i++)
    {
        if (strcmp(words[i], wordP) == 0)
        {
            strcat(article, wordQ);
            strcat(article, " ");
        }
        else
        {
            strcat(article, words[i]);
            if (i != (count - 1))
            {
                strcat(article, " ");
            }
        }
    }
}

void insertBeforeWord(char *article, char *wordP, char *wordQ)
{
    int i = 0, count = 0;
    char *words[SIZE], text[SIZE];
    strcpy(text, article);
    strcpy(article, "");
    scanWord(text, words, &count);

    for (i = 0; i < count; i++)
    {
        if (strcmp(words[i], wordP) == 0)
        {
            strcat(article, wordQ);
            strcat(article, " ");
            strcat(article, wordP);
            strcat(article, " ");
        }
        else
        {
            strcat(article, words[i]);
            if (i != (count - 1))
            {
                strcat(article, " ");
            }
        }
    }
}

void insertAfterWord(char *article, char *wordP, char *wordQ)
{
    int i = 0, count = 0;
    char *words[SIZE], text[SIZE];
    strcpy(text, article);
    strcpy(article, "");
    scanWord(text, words, &count);

    for (i = 0; i < count; i++)
    {
        if (strcmp(words[i], wordP) == 0)
        {
            strcat(article, wordP);
            strcat(article, " ");
            strcat(article, wordQ);
            strcat(article, " ");
        }
        else
        {
            strcat(article, words[i]);
            if (i != (count - 1))
            {
                strcat(article, " ");
            }
        }
    }
}

void deleteWord(char *article, char *wordP)
{
    int i = 0, count = 0;
    char *words[SIZE], text[SIZE];
    strcpy(text, article);
    strcpy(article, "");
    scanWord(text, words, &count);

    for (i = 0; i < count; i++)
    {
        if (strcmp(words[i], wordP) != 0)
        {
            strcat(article, words[i]);
            if (i != (count - 1))
            {
                strcat(article, " ");
            }
        }
    }
}

void wordFrequency(char *article)
{
    int i = 0, j = 0, allwordCount = 0, wordCount = 0, currentCount = 0;
    char *words[SIZE], text[SIZE];
    char *word[SIZE];
    int frequency[20] = {0};
    strcpy(text, article);
    strcpy(article, "");
    scanWord(text, words, &allwordCount);
    int notin = 0;
    word[0] = words[0];
    // printf("%s\n", word[0]);
    frequency[0] += 1;
    wordCount++;
    for (i = 1; i < allwordCount; i++)
    {
        currentCount = wordCount;
        // printf("%d", wordCount);
        for (j = 0; j < currentCount; j++)
        {
            // notin = 1;
            if (strcmp(words[i], word[j]) == 0)
            {
                frequency[j]++;
                // notin = 0;
                break;
            }
            else if (j == (currentCount - 1))
            {

                word[wordCount] = words[i];
                frequency[wordCount] += 1;
                wordCount++;
                break;
            }
        }
    }
    // printf("3");

    for (i = 0; i < wordCount - 1; i++)
    {
        for (j = 0; j < wordCount - 1 - i; j++)
        {
            if (strcmp(word[j], word[j + 1]) > 0)
            {
                int temp = frequency[j];
                frequency[j] = frequency[j + 1];
                frequency[j + 1] = temp;
                char *wordtemp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = wordtemp;
            }
        }
    }
    for (i = 0; i < wordCount - 1; i++)
    {
        for (j = 0; j < wordCount - 1 - i; j++)
        {
            if (frequency[j] < frequency[j + 1])
            {
                int temp = frequency[j];
                frequency[j] = frequency[j + 1];
                frequency[j + 1] = temp;
                char *wordtemp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = wordtemp;
            }
        }
    }
    for (i = 0; i < wordCount; i++)
    {
        printf("%s,%d\n", word[i], frequency[i]);
    }
}

// void bubble_sort(int arr[], int len)
// {
//     int i, j, temp;
//     for (i = 0; i < len - 1; i++)
//     {
//         for (j = 0; j < len - 1 - i; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }