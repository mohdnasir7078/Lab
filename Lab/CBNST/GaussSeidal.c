#include <stdio.h>
#include <math.h>
/*float m[10][10] = {{9, 2, 4, 20}, {1, -1, 4, 6}, {2, -4, 10, -15}};*/
int main()
{
    printf("                    GAUSS SEIDAL METHOD\n");
    int size = 3, k = 0, count = 0, it = 0, vn;
    printf("Please Enter No of Variable :");
    scanf("%d", &size);
    float m[size][size + 1];
    float val[size];
    for (int i = 0; i < size; i++)
        val[i] = 0;

    printf("                Input %d * %d Matrix.\n", size, size + 1);
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

    float x, y;
    for (int i = 0; i < size; i++)
    {
        it++;
        x = m[i][size];
        for (int j = 0; j < size; j++)
        {
            if (i != j)
                x -= val[j] * m[i][j];
        }
        x = (1.0 / m[i][i]) * x;
        y = fabs(x - val[i]);
        val[i] = x;
        if (y < 0.0001)
            count++;
        if (count == size - 1 && i == size - 1)
            break;
        else if (i == size - 1 && count != 3)
        {
            count = 0;
            i = -1;
        }
    }

    vn = 123 - size;
    printf("\n          Solution is.\n");
    printf("No of Iterations is :%d\n", it);
    for (int i = 0; i < size; i++)
    {
        printf("%c = %0.2f\n", vn, val[i]);
        vn++;
    }
    return 0;
}