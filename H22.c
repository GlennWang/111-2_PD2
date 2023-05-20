#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SSIZE 150
#define PSIZE 150
#define SUBSTRINGSIZE 150

void createWordSet(char stringS[], char wordSet[], int *count);
void bubble_sort(char arr[], int len);
int intersectionCharacters(char S1[], char S2[], char wordSet[]);
void findSameWord(char S1[], char S2[], char sameWord[]);

int main()
{
    char stringS[SSIZE], stringP[PSIZE];
    int n, wordCount = 0;
    int i, j;
    char wordSet[80] = "";
    int num_of_intersection_characters = 0;
    gets(stringS);
    scanf("%d ", &n);
    gets(stringP);
    createWordSet(stringS, wordSet, &wordCount);
    bubble_sort(wordSet, wordCount);

    int len = strlen(stringP);
    int seg_len = n; // 每份的長度
    int N = len / n; // 切割成N份

    char substr[SUBSTRINGSIZE][SUBSTRINGSIZE]; // 切割後的子字串

    // 依次切割字串
    // memset(substr, '\0', sizeof(substr));
    for (i = 0; i < N; i++)
    {
        strncpy(substr[i], stringP + i * seg_len, seg_len);
        substr[i][seg_len] = '\0';
    }

    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (intersectionCharacters(substr[i], substr[j], wordSet))
            {
                num_of_intersection_characters++;
            }
        }
    }

    printf("%d", num_of_intersection_characters);
}

void createWordSet(char stringS[], char wordSet[], int *count)
{
    int currentWordCount;
    wordSet[0] = stringS[0];
    (*count)++;

    for (int i = 0; i < strlen(stringS); i++)
    {
        currentWordCount = *count;
        for (int j = 0; j < currentWordCount; j++)
        {
            if (stringS[i] == wordSet[j])
            {
                break;
            }
            else if (j == (currentWordCount - 1))
            {
                wordSet[(int)*count] = stringS[i];
                (*count)++;
                break;
            }
        }
    }
    wordSet[(int)*count] = '\0';
}

void bubble_sort(char arr[], int len)
{
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int intersectionCharacters(char S1[], char S2[], char wordSet[])
{
    char sameWord[80] = "";
    // printf("s1:%s s2:%s\n", S1, S2);
    findSameWord(S1, S2, sameWord);
    bubble_sort(sameWord, strlen(sameWord));
    // printf("same:%s wordset:%s\n", sameWord, wordSet);
    if (strcmp(sameWord, wordSet) == 0)
    {
        return 1;
    }
    return 0;
}

void findSameWord(char S1[], char S2[], char sameWord[])
{
    for (int i = 0; i < strlen(S1); i++)
    {
        for (int j = 0; j < strlen(S2); j++)
        {
            if (S1[i] == S2[j])
            {
                int k;
                for (k = 0; k < strlen(sameWord); k++)
                {
                    if (S1[i] == sameWord[k])
                    {
                        break;
                    }
                }
                if (k == strlen(sameWord))
                {
                    sameWord[strlen(sameWord)] = S1[i];
                }
            }
        }
    }

    sameWord[strlen(sameWord) + 1] = '\0';
}
