#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int ConstantSum(char eq[])
{
    int cons = 0, t = 0, mi = 0, mi1 = 0, i = 0, digit = 0;
    while (eq[i] != '\0')
    {
        if (mi == 1 && eq[i] == '-')
        {
            if (mi == 1)
                t = t * -1;
            cons += t;
            t = 0;
            mi = 1;
        }
        else if (eq[i] == '-')
        {
            if (i != 0 && (eq[i - 1] >= '0' && eq[i - 1] <= '9'))
            {
                if (mi == 1)
                    t = t * -1;
                cons += t;
                t = 0;
                mi = 1;
            }
            mi = 1;
        }
        else if (eq[i] == '^')
        {
            while (eq[i] != '+' && eq[i] != '-' && eq[i] != '=')
                i++;
            mi = 0;
            continue;
        }
        else if (eq[i] >= '0' && eq[i] <= '9')
        {
            digit = eq[i] - '0';
            t = 10 * t + digit;
        }
        else if (eq[i] >= 'a' && eq[i] <= 'z')
        {
            t = 0;
            mi = 0;
        }
        else
        {
            if (mi == 1)
                t = t * -1;
            cons += t;
            t = 0;
            mi = 0;
        }
        i++;
    }
    return cons;
}

int MaxDegree(char eq[])
{
    int i = 0, temp = 0, max = 0, digit = 0;
    while (eq[i] != '\0')
    {
        if (eq[i] == '^')
        {
            temp = 0;
            i++;
            while (eq[i] >= '0' && eq[i] <= '9')
            {
                digit = eq[i] - '0';
                temp = 10 * temp + digit;
                i++;
            }
            if (max < temp)
                max = temp;
        }
        i++;
    }
    return max;
}
int main()
{
    // char eqtemp[] = "x^12+12+x+65-x+x^134-53265+x+x^543+53188=x^12+12+x+65-x+x^134-53265+x+x^543+53188";
    char eqtemp[] = "a+10=0";
    int i = 0, ch = 0, j = 0;
    char *eq = (char *)malloc((strlen(eqtemp) + 33) * sizeof(char));
    while (eqtemp[i] != '\0')
    {
        if (eqtemp[i] == '=')
        {
            if (eqtemp[i + 1] == '0' && eqtemp[i + 2] == '\0')
            {
                eq[j] = eqtemp[i];
                i++;
                j++;
                eq[j] = eqtemp[i];
                j++;
                eq[j] = '\0';
                break;
            }
            i++;
            eq[j] = '-';
            j++;
            while (eqtemp[i] != '\0')
            {
                if (eqtemp[i] == '+')
                {
                    eq[i] = '-';
                    i++;
                    j++;
                }
                else if (eqtemp[i] == '-')
                {
                    eq[i] = '+';
                    i++;
                    j++;
                }
                else
                {
                    eq[j] = eqtemp[i];
                    i++;
                    j++;
                }
            }
            eq[j] = '=';
            j++;
            eq[j] = '0';
            j++;
            eq[j] = '\0';
            break;
        }
        else
        {
            eq[j] = eqtemp[i];
            j++;
            i++;
        }
    }
    int MaxDeg = 0, digit = 0;
    digit = 0;
    i = 0;
    int ConSum = ConstantSum(eq);
    MaxDeg = MaxDegree(eq);
    if (MaxDeg == 0)
        MaxDeg = 1;
    int *arr = (int *)malloc((MaxDeg + 1) * sizeof(int));
    for (i = 0; i <= MaxDeg; i++)
        arr[i] = 0;
    arr[0] = ConSum;
    i = 0, digit = 0;
    int power = 0, temp = 0, max = 0;
    while (eq[i] != '\0')
    {
        if (i != 0 && eq[i - 1] == '-')
            temp = 1;
        else if (i == 0 && eq[i] == '-')
            temp = 1;
        if (eq[i] >= '0' && eq[i] <= '9')
        {
            digit = eq[i] - '0';
            max = 10 * max + digit;
        }
        else if (eq[i] == '=')
        {
            arr[0] = ConSum;
            break;
        }
        else if (eq[i] == '+' || eq[i] == '-')
        {
            max = 0;
            temp = 0;
        }
        else if (eq[i] >= 'a' && eq[i] <= 'z')
        {
            i++;
            if (eq[i] == '^')
            {
                i++;
                power = 0;
                while (eq[i] >= '0' && eq[i] <= '9')
                {

                    digit = eq[i] - '0';
                    power = 10 * power + digit;
                    i++;
                }
                if (max == 0)
                    max = 1;
                if (temp == 1)
                {
                    max = max * -1;
                    temp = 0;
                }
                arr[power] += max;
                max = 0;
            }
            else if (eq[i] == '-' || eq[i] == '+' || eq[i] == '=')
            {
                power = 1;
                if (max == 0)
                    max = 1;
                if (temp == 1)
                {
                    max = max * -1;
                    temp = 0;
                }
                arr[power] += max;
                max = 0;
            }
        }
        i++;
    }
    for (i = MaxDeg; i >= 0; i--)
    {
        if (i == 0)
            printf("Constant is : %d\n", arr[i]);
        else if (arr[i] != 0)
            printf("Coefficient of X^%d is : %d\n", i, arr[i]);
    }
    return 0;
}