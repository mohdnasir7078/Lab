#include <stdio.h>
#include<math.h>
int main()
{
    printf("                    GAUSS JORDAN METHOD\n");
    int size, k, vn;
    printf("Please Enter No of Variable :");
    scanf("%d", &size);
    float m[size][size + 1];
    float div, sum = 0, mul = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j <= size; j++)
            scanf("%f", &m[i][j]);

    printf("\n          Equation is.\n");
    for (int i = 0; i < size; i++)
    {
        vn = 123 - size;
        for (int j = 0; j <= size; j++)
        {
            if (j == 0 && m[i][j] < 0)
                printf("-");
            if (j != 0 && j < size)
            {
                if (m[i][j] >= 0)
                    printf(" + ");
                else
                    printf(" - ");
            }
            if (j < size)
                printf("%0.1f%c", fabs(m[i][j]), vn);
            if (j == size - 1)
                printf(" = %0.1f", m[i][j + 1]);
            vn++;
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j && m[i][i] != 0)
            {
                div = m[j][i] / m[i][i];
                for (int k = 0; k <= size; k++)
                    m[j][k] = m[j][k] - (div * m[i][k]);
            }
        }
    }

    vn = 123 - size;
    printf("\n          Solution is.\n");
    for (int i = 0; i < size; i++)
    {
        printf("%c = %0.2f\n", vn, m[i][size] / m[i][i]);
        vn++;
    }
    return 0;
}