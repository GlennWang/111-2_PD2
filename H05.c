#include <stdio.h>
#define START 0
#define VH 1        // variable head
#define VB 2        // variable body
#define VD 3        // variable defined
#define IH 4        // integer head
#define IB 5        // integer body
#define ID 6        // integer defined
#define FI 7        // floating integer part
#define FP 8        // floating point
#define FH 9        // floating decimal head
#define FB 10       // floating decimal body
#define FD 11       // floating defined
#define PDI 12      // proper fraction division sign
#define PDH 13      // proper fraction Denominator head
#define PDB 14      // proper fraction Denominator body
#define PD 15       // proper fraction defined
#define LP 16       // left parenthesis
#define ANH 17      // algebraic fraction Numerator head
#define ANB 18      // algebraic fraction Numerator body
#define ADI 19      // algebraic fraction division sign
#define ADH 20      // algebraic fraction Denominator head
#define ADB 21      // algebraic fraction Denominator body
#define RP 22       // right parenthesis
#define AD 23       // algebraic fraction defined
#define ERROR 48763 // error
#define ED 114514   // error defined

// double getfValue(char key, int fPoint)
// {
//     int num = (key - '0');
//     double r = num;
//     for (int i = 0; i < fPoint; i++)
//         r = r / 10;
//     return r;
// }
int getState(int state, char key)
{ // 狀態轉換圖
    if (state == START && key == '0')
        return FI;
    else if (state == START && key >= '1' && key <= '9')
        return IH;
    else if (state == START && key >= 'a' && key <= 'z')
        return VH;
    else if (state == START && key >= 'A' && key <= 'Z')
        return VH;
    else if (state == START && key == '_')
        return VH;
    else if (state == VH && key >= '0' && key <= '9')
        return VB;
    else if (state == VH && key >= 'a' && key <= 'z')
        return VB;
    else if (state == VH && key >= 'A' && key <= 'Z')
        return VB;
    else if (state == VH && key == '_')
        return VB;
    else if (state == VH && key == '\n')
        return VD;
    else if (state == VB && key >= '0' && key <= '9')
        return VB;
    else if (state == VB && key >= 'a' && key <= 'z')
        return VB;
    else if (state == VB && key >= 'A' && key <= 'Z')
        return VB;
    else if (state == VB && key == '_')
        return VB;
    else if (state == VB && key == '\n')
        return VD;
    else if (state == FI && key == '.')
        return FP;
    else if (state == IH && key == '.')
        return FP;
    else if (state == IB && key == '.')
        return FP;
    else if (state == FP && key == '\n')
        return ED;
    else if (state == FP && key >= '0' && key <= '9')
        return FH;
    else if (state == FH && key >= '0' && key <= '9')
        return FB;
    else if (state == FB && key >= '0' && key <= '9')
        return FB;
    else if (state == FB && key == '\n')
        return FD;
    else if (state == FH && key == '\n')
        return FD;
    else if (state == IH && key >= '0' && key <= '9')
        return IB;
    else if (state == IH && key == '\n')
        return ID;
    else if (state == IB && key >= '0' && key <= '9')
        return IB;
    else if (state == IB && key == '\n')
        return ID;
    else if (state == FI && key == '\n')
        return ID;
    else if (state == IH && key == '/')
        return PDI;
    else if (state == IB && key == '/')
        return PDI;
    else if (state == PDI && key == '\n')
        return ED;
    else if (state == PDI && key >= '1' && key <= '9')
        return PDH;
    else if (state == PDH && key >= '0' && key <= '9')
        return PDB;
    else if (state == PDH && key == '\n')
        return PD;
    else if (state == PDB && key >= '0' && key <= '9')
        return PDB;
    else if (state == PDB && key == '\n')
        return PD;
    else if (state == IH && key == '(')
        return LP;
    else if (state == IB && key == '(')
        return LP;
    else if (state == LP && key >= '1' && key <= '9')
        return ANH;
    else if (state == ANH && key >= '0' && key <= '9')
        return ANB;
    else if (state == ANB && key >= '0' && key <= '9')
        return ANB;
    else if (state == ANH && key == '/')
        return ADI;
    else if (state == ANB && key == '/')
        return ADI;
    else if (state == ADI && key >= '1' && key <= '9')
        return ADH;
    else if (state == ADH && key >= '0' && key <= '9')
        return ADB;
    else if (state == ADB && key >= '0' && key <= '9')
        return ADB;
    else if (state == ADH && key == ')')
        return RP;
    else if (state == ADB && key == ')')
        return RP;
    else if (state == RP && key == '\n')
        return AD;
    else if (state == ERROR && key == '\n')
        return ED;
    else if (state == ERROR)
        return ERROR;
    else
        return ERROR;
}
int checkInput()
{
    char key;
    int state = START;
    int iPart = 0; // fPoint = 0;
    // float fPart = 0;
    long long int fPart = 0;
    int pDenominator = 0;
    int aNumerator = 0;
    int aDenominator = 0;
    while (1)
    {
        key = getchar();
        state = getState(state, key);
        if (state == VD)
        { // 非整數、浮點數
            printf("variable\n");
            break;
        }
        else if (state == FD)
        { // 浮點數

            printf("float\n");
            printf("%d\n", iPart);
            printf("%lld\n", fPart);
            break;
        }
        else if (state == ID)
        { // 整數
            // if (neg == -1)
            //     printf("negative ");
            printf("integer\n");
            break;
        }
        else if (state == PD)
        {
            if (iPart < pDenominator)
                printf("proper fraction\n");
            else
                printf("error\n");
            break;
        }
        else if (state == AD)
        {
            if (aNumerator < aDenominator)
                printf("algebraic fraction\n");
            else
                printf("error\n");
            break;
        }
        else if (state == IH)
            iPart = key - '0';
        // 計算整數的值
        else if (state == IB)
            iPart = iPart * 10 + key - '0';
        else if (state == FH)
            fPart = key - '0';
        else if (state == FB)
        {
            // 小數點多一位
            // fPoint++;
            // 計算小數點的值
            // fPart = fPart + getfValue(key, fPoint);
            fPart = fPart * 10 + key - '0';
        }
        else if (state == PDH)
            pDenominator = key - '0';
        else if (state == PDB)
            pDenominator = pDenominator * 10 + key - '0';
        else if (state == ANH)
            aNumerator = key - '0';
        else if (state == ANB)
            aNumerator = aNumerator * 10 + key - '0';
        else if (state == ADH)
            aDenominator = key - '0';
        else if (state == ADB)
            aDenominator = aDenominator * 10 + key - '0';
        else if (state == ED)
        {
            printf("error\n");
            break;
        }
    }
    return state;
}
int main()
{
    int N;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++)
    {
        checkInput();
    }
    return 0;
}