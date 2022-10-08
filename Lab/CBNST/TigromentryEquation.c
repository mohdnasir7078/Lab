#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int MaxDeg = 0, Constent = 0, check = 0;

typedef struct mul
{
    int multigfun;
    int coffi;
    int degree;
} mul;

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
        else if (eq[i] == '*' || (eq[i] >= 'a' && eq[i] <= 'z'))
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

void MaxDegree(char eq[])
{
    int i = 0, temp = 0, max = 1, digit = 0;
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
    MaxDeg = max;
}

void fn(char ch)
{
    if (ch == 'a')
        printf("sinx");
    else if (ch == 'b')
        printf("cosx");
    else if (ch == 'c')
        printf("tanx");
    else if (ch == 'd')
        printf("cotx");
    else if (ch == 'e')
        printf("secx");
    else if (ch == 'f')
        printf("cosecx");
    else if (ch == 'g')
        printf("logx");
    else if (ch == 'h')
        printf("e");
    else if (ch == 'i')
        printf("x");
}

void PrintCoff(int arr[9][MaxDeg + 1], mul info[9][MaxDeg + 1])
{
    char fun, fun1;
    for (int i = 0; i < 9; i++)
    {
        fun = i + 'a';
        for (int j = MaxDeg; j >= 0; j--)
        {
            if (arr[i][j] != 0)
            {
                if (fun == 'a' && j == 1)
                    printf("Coefficient of sinx is :%d\n", arr[i][j]);
                else if (fun == 'a' && j != 1)
                    printf("Coefficient of sin^%dx is :%d\n", j, arr[i][j]);
                else if (fun == 'b' && j == 1)
                    printf("Coefficient of cosx is :%d\n", arr[i][j]);
                else if (fun == 'b' && j != 0)
                    printf("Coefficient of cos^%dx is :%d\n", j, arr[i][j]);
                else if (fun == 'c' && j == 1)
                    printf("Coefficient of tanx is :%d\n", arr[i][j]);
                else if (fun == 'c' && j != 1)
                    printf("Coefficient of tan^%dx is :%d\n", j, arr[i][j]);
                else if (fun == 'd' && j == 1)
                    printf("Coefficient of secx is :%d\n", arr[i][j]);
                else if (fun == 'd' && j != 1)
                    printf("Coefficient of sec^%dx is :%d\n", j, arr[i][j]);
                else if (fun == 'e' && j == 1)
                    printf("Coefficient of cot is :%d\n", arr[i][j]);
                else if (fun == 'e' && j != 1)
                    printf("Coefficient of cot^%dx is :%d\n", j, arr[i][j]);
                else if (fun == 'f' && j == 1)
                    printf("Coefficient of cosecx is :%d\n", arr[i][j]);
                else if (fun == 'f' && j != 1)
                    printf("Coefficient of cosecx^%dx is :%d\n", j, arr[i][j]);
                else if (fun == 'g' && j == 1)
                    printf("Coefficient of logx is :%d\n", arr[i][j]);
                else if (fun == 'g' && j != 1)
                    printf("Coefficient of log^%dx is :%d\n", j, arr[i][j]);
                else if (fun == 'h' && j == 1)
                    printf("Coefficient of e is :%d\n", arr[i][j]);
                else if (fun == 'h' && j != 1)
                    printf("Coefficient of e^%d is :%d\n", j, arr[i][j]);
                else if (fun == 'i' && j == 1)
                    printf("Coefficient of x is :%d\n", arr[i][j]);
                else if (fun == 'i' && j != 1)
                    printf("Coefficient of x^%d is :%d\n", j, arr[i][j]);
            }
        }
    }
    if (check == 1)
    {
        for (int i = 0; i < 9; i++)
        {
            fun = i + 'a';
            for (int j = 0; j <= MaxDeg; j++)
            {
                fun1 = info[i][j].multigfun + 'a';
                if (info[i][j].degree != 0)
                {
                    if (info[info[i][j].multigfun][j].degree != 0)
                    {
                        info[i][j].coffi += info[info[i][j].multigfun][j].coffi;
                        info[info[i][j].multigfun][j].degree = 0;
                    }
                    if (fun == 'a' && info[i][j].degree == 1)
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*sinx) is :%d\n", info[i][j].coffi);
                    }
                    else if (fun == 'a')
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*sin^%dx) is :%d\n", info[i][j].degree, info[i][j].coffi);
                    }
                    else if (fun == 'b' && info[i][j].degree == 1)
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*cosx) is :%d\n", info[i][j].coffi);
                    }
                    else if (fun == 'b')
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*cos^%dx) is :%d\n", info[i][j].degree, info[i][j].coffi);
                    }
                    else if (fun == 'c' && info[i][j].degree == 1)
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*tanx) is :%d\n", info[i][j].coffi);
                    }
                    else if (fun == 'c')
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*tan^%dx) is :%d\n", info[i][j].degree, info[i][j].coffi);
                    }
                    else if (fun == 'd' && info[i][j].degree == 1)
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*cotx) is :%d\n", info[i][j].coffi);
                    }
                    else if (fun == 'd')
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*cot^%dx) is :%d\n", info[i][j].degree, info[i][j].coffi);
                    }
                    else if (fun == 'e' && info[i][j].degree == 1)
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*secx) is :%d\n", info[i][j].coffi);
                    }
                    else if (fun == 'e')
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*sec^%dx) is :%d\n", info[i][j].degree, info[i][j].coffi);
                    }
                    else if (fun == 'f' && info[i][j].degree == 1)
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*cosecx) is :%d\n", info[i][j].coffi);
                    }
                    else if (fun == 'f')
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*cosec^%dx) is :%d\n", info[i][j].degree, info[i][j].coffi);
                    }
                    else if (fun == 'g' && info[i][j].degree == 1)
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*logx) is :%d\n", info[i][j].coffi);
                    }
                    else if (fun == 'g')
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*log^%dx) is :%d\n", info[i][j].degree, info[i][j].coffi);
                    }
                    else if (fun == 'h' && info[i][j].degree == 1)
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*e) is :%d\n", info[i][j].coffi);
                    }
                    else if (fun == 'h')
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*e^%d) is :%d\n", info[i][j].degree, info[i][j].coffi);
                    }
                    else if (fun == 'i' && info[i][j].degree == 1)
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*x) is :%d\n", info[i][j].coffi);
                    }
                    else if (fun == 'i')
                    {
                        printf("Coefficient of (");
                        fn(fun1);
                        printf("*x^%d) is :%d\n", info[i][j].degree, info[i][j].coffi);
                    }
                }
            }
        }
    }
    printf("Constant is :%d\n", Constent);
}

int main()
{
    char eqtemp1[100];
    printf("Please Input Equation (x^2+sinx+cosx*logx+tanx*sin^2x+10):");
    scanf("%s", eqtemp1);
    char eqtemp[1000];
    int i = 0, ch = 0, j = 0;
    while (eqtemp1[i] != '\0')
    {
        if (i == 0 && eqtemp1[i] == 'x')
        {
            eqtemp[j] = 'i';
            i++;
            j++;
        }
        else if (eqtemp1[i] == 'x' && (!(eqtemp1[i - 1] >= 'a' && eqtemp1[i - 1] < 'z')))
        {
            eqtemp[j] = 'i';
            i++;
            j++;
        }
        else if (eqtemp1[i] != 'x' && (eqtemp1[i] >= 'a' && eqtemp1[i] <= 'z'))
        {
            if (eqtemp1[i] == 'e')
            {
                eqtemp[j] = 'h';
                j++;
                i += 1;
            }
            else if (eqtemp1[i] == 'l')
            {
                eqtemp[j] = 'g';
                j++;
                i += 3;
            }
            else if (eqtemp1[i] == 't')
            {
                eqtemp[j] = 'c';
                j++;
                i += 3;
            }
            else if (eqtemp1[i] == 's' && eqtemp1[i + 1] == 'i')
            {
                eqtemp[j] = 'a';
                j++;
                i += 3;
            }
            else if (eqtemp1[i] == 's' && eqtemp1[i + 1] == 'e')
            {
                eqtemp[j] = 'e';
                j++;
                i += 3;
            }
            else if (eqtemp1[i] == 'c' && eqtemp1[i + 1] == 'o' && eqtemp1[i + 2] == 't')
            {
                eqtemp[j] = 'd';
                j++;
                i += 3;
            }
            else if (eqtemp1[i] == 'c' && eqtemp1[i + 1] == 'o' && eqtemp1[i + 2] == 's')
            {
                if (eqtemp1[i + 3] == 'e')
                {
                    eqtemp[j] = 'f';
                    j++;
                    i += 5;
                }
                else
                {
                    eqtemp[j] = 'b';
                    j++;
                    i += 3;
                }
            }
        }
        else if (eqtemp1[i] != 'x')
        {
            eqtemp[j] = eqtemp1[i];
            i++;
            j++;
        }
        else
            i++;
    }
    eqtemp[j] = '\0';
    i = 0, ch = 0, j = 0;
    char *eq = (char *)malloc((strlen(eqtemp) + 3) * sizeof(char));
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
            if (eqtemp[i + 1] != '-')
            {
                eq[j] = '-';
                j++;
            }
            i++;
            while (eqtemp[i] != '\0')
            {
                if (eqtemp[i] == '+')
                {
                    eq[j] = '-';
                    i++;
                    j++;
                }
                else if (eqtemp[i] == '-')
                {
                    eq[j] = '+';
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

    /*printf("%s\n", eq);*/

    Constent = ConstantSum(eq);
    MaxDegree(eq);
    int arr[9][MaxDeg + 1];
    mul info[9][MaxDeg + 1];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j <= MaxDeg; j++)
        {
            arr[i][j] = 0;
            info[i][j].multigfun = 0;
            info[i][j].coffi = 0;
            info[i][j].degree = 0;
        }
    }
    int digit = 0, coff = 0, deg = 0, index = 0, pos = 0;
    int Minsign = 0;
    i = 0;
    while (eq[i] != '\0')
    {
        if (i != 0 && eq[i - 1] == '-')
            Minsign = 1;
        else if (i == 0 && eq[i] == '-')
            Minsign = 1;
        if (eq[i] >= '0' && eq[i] <= '9')
        {
            digit = eq[i] - '0';
            coff = coff * 10 + digit;
        }
        else if (eq[i] == '=')
        {
            break;
        }
        else if (eq[i] == '+' || eq[i] == '-')
        {

            coff = 0;
            Minsign = 0;
        }
        else if (eq[i] >= 'a' && eq[i] <= 'z')
        {
            i++;
            if (eq[i] == '*')
            {
                index = i;
                i += 2;
                if (eq[i] == '^')
                {
                    i++;
                    deg = 0;
                    while (eq[i] >= '0' && eq[i] <= '9')
                    {

                        digit = eq[i] - '0';
                        deg = 10 * deg + digit;
                        i++;
                    }
                    if (coff == 0)
                        coff = 1;
                    if (Minsign == 1)
                    {
                        coff = coff * -1;
                        Minsign = 0;
                    }
                    pos = eq[index + 1] - 'a';
                    int pos1 = eq[index - 1] - 'a';
                    info[pos][deg].multigfun = pos1;
                    info[pos][deg].coffi += coff;
                    info[pos][deg].degree = deg;
                    check = 1;
                    coff = 0;
                }
                else if (eq[i] == '-' || eq[i] == '+' || eq[i] == '=')
                {
                    ch = eq[i - 1];
                    deg = 1;
                    if (coff == 0)
                        coff = 1;
                    if (Minsign == 1)
                    {
                        coff = coff * -1;
                        Minsign = 0;
                    }
                    pos = eq[index + 1] - 'a';
                    int pos1 = eq[index - 1] - 'a';
                    info[pos][deg].multigfun = pos1;
                    info[pos][deg].coffi += coff;
                    info[pos][deg].degree = deg;
                    check = 1;
                    coff = 0;
                }
            }
            else if (eq[i] == '^')
            {
                ch = eq[i - 1];
                i++;
                deg = 0;
                while (eq[i] >= '0' && eq[i] <= '9')
                {

                    digit = eq[i] - '0';
                    deg = 10 * deg + digit;
                    i++;
                }
                if (coff == 0)
                    coff = 1;
                if (Minsign == 1)
                {
                    coff = coff * -1;
                    Minsign = 0;
                }
                pos = ch - 'a';
                arr[pos][deg] += coff;
                coff = 0;
            }
            else if (eq[i] == '-' || eq[i] == '+' || eq[i] == '=')
            {
                ch = eq[i - 1];
                deg = 1;
                if (coff == 0)
                    coff = 1;
                if (Minsign == 1)
                {
                    coff = coff * -1;
                    Minsign = 0;
                }
                pos = ch - 'a';
                arr[pos][deg] += coff;
                coff = 0;
            }
        }
        i++;
    }
    PrintCoff(arr, info);
    return 0;
}