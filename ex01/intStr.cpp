#include <iostream>
#include <cstdlib>
#include "intStr.h"

char *intToStr(int seisu)
{
    int ketasu = 0, flag[100], x = 0;
    int i, j, k=0;

    x = seisu;
    while (x != 0)
    {
        x = x / 10;
        ketasu++;
    }

    char *tostr = static_cast<char*>(malloc(sizeof(char) * ketasu));

    if (seisu < 0)
    {
        seisu = seisu * -1;
        tostr[0] = '-';
        k++;
    } 


    for (i = 0; i < ketasu; i++)
    {
        flag[i] = seisu % 10;
        seisu = seisu / 10;
    }

    for (j = ketasu - 1 ; j >= 0; j--)
    {
        tostr[k] = 48 + flag[j];
        k++;
    }
    tostr[k] = '\0';
    ketasu++;
    return tostr;
}

int strToInt(char const *moji)
{
    int i, j, toint = 0, flag = 1;

    if (*moji == '-')
    {
        moji++;
        flag = flag * -1;
    }

    while (*moji != '\0')
    {
        toint = toint * 10 + (*moji - '0');
        moji++;
    }
    return toint * flag;
}
