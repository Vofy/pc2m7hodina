#include <stdio.h>
#include <stdlib.h>

void vypis_pole(int prvky[][4], int radku)
{
    printf("Vypis matice:\n");
    for(int i = 0; i < radku; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%5d", prvky[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int maximum(int prvky[][4], int radku)
{
    int nejvyssi = 0;

    for(int i = 0; i < radku /*sizeof(prvky)/(sizeof(int) * 4)*/; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(prvky[i][j] > nejvyssi)
                nejvyssi = prvky[i][j];
        }
    }

    return nejvyssi;
}

int *suma_radku(int prvky[][4], int radku)
{
    int *soucty = calloc(radku, sizeof soucty);

    for(int i = 0; i < radku; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            soucty[i] += prvky[i][j];
        }
    }

    return soucty;
}

int main()
{
    int prvky[][4] = {1,2,8,6,1,8,6,5,8,3,8,1};
    int pocet_radku = sizeof(prvky) / (sizeof(int) * 4);

    vypis_pole(prvky, pocet_radku);

    printf("Nejvyssi cislo v matici: %d\n\n", maximum(prvky, pocet_radku));
    int *suma_radku_ptr = suma_radku(prvky, pocet_radku);

    for(int i = 0; i < 3; i++)
        printf("Soucet radku %d je: %d.\n", i, suma_radku_ptr[i]);

    return 0;
}
