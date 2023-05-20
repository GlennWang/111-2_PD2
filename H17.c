#include <stdio.h>
#include <stdlib.h>

int mergeSort(int array[], int temp[], int left, int right);
int merge(int array[], int temp[], int left, int mid, int right);

int main()
{
    int array_size;
    // 讀取題目給定陣列大小
    scanf("%d ", &array_size);
    char index_char;
    // 這題應該只能用動態記憶體分配，如果直接設陣列大小應該會出錯
    int *array = (int *)malloc(sizeof(int) * array_size);
    int *temp = (int *)malloc(sizeof(int) * array_size);
    // 處理輸入帶有空格的字串
    int index = 0;
    // 只要不是換行跟EOF就會持續保持輸入狀態
    while ((index_char = getchar()) != '\n' && index_char != EOF)
    { // 如果不是空格
        if (index_char != ' ')
        { // 就把那個數字 - '0' 等於轉成數字
            array[index] = index_char - '0';
            index++;
        }
    }
    // 印出inversion數量結果
    printf("%d\n", mergeSort(array, temp, 0, array_size - 1));
    // 列印出來看看是不是排序好的
    // for (int index = 0; index < array_size; index++)
    // {
    //     printf("%d ", array[index]);
    // }
    return EXIT_SUCCESS;
}

int mergeSort(int array[], int temp[], int left, int right)
{
    int mid, inversion_count = 0;
    if (right > left)
    {
        mid = (left + right) / 2;
        // 分一半。遞迴求解。
        // 也就是說他會一直分一直分，然後一直合一直合。
        // 拆成最細，然後再全部合起來。
        inversion_count += mergeSort(array, temp, left, mid);
        inversion_count += mergeSort(array, temp, mid + 1, right);
        inversion_count += merge(array, temp, left, mid + 1, right);
    }
    return inversion_count;
}

int merge(int array[], int temp[], int left, int mid, int right)
{
    int left_subarray_index, right_subarray_index, result_index;
    int inversion_count = 0;
    // 左邊子陣列的index開頭理所當然是left
    left_subarray_index = left;
    // 右邊子陣列的index理所當然是mid，因為輸入進來的mid有先+1
    // 所以這裡不用+1
    right_subarray_index = mid;
    // 結果的陣列的index是從最左邊開始，所以也是left
    result_index = left;

    // 如果兩個子陣列的index同時小於等於邊界就不會停止
    while ((left_subarray_index <= mid - 1) && (right_subarray_index <= right))
    { // 如果左邊小於或等於右邊，就把左邊的給temp
        if (array[left_subarray_index] <= array[right_subarray_index])
        {
            temp[result_index++] = array[left_subarray_index++];
        }
        else // 如果左邊大於右邊，就把右邊的給temp
        {
            temp[result_index++] = array[right_subarray_index++];

            inversion_count = inversion_count + (mid - left_subarray_index);
        }
    }
    // 如果有剩餘的元素就複製到temp
    while (left_subarray_index <= mid - 1)
    {
        temp[result_index++] = array[left_subarray_index++];
    }
    // 如果有剩餘的元素就複製到temp
    while (right_subarray_index <= right)
    {
        temp[result_index++] = array[right_subarray_index++];
    }
    // 排序結果給弄上去
    for (int index = left; index <= right; index++)
    {
        array[index] = temp[index];
    }

    return inversion_count;
}