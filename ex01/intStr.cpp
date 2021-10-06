#include <iostream>
#include <cstdlib>
#include "intStr.h"

char *intToStr(int seisu)
{
    int ketasu = 0, flag[100], x = 0;
    int i, j;
    char *tostr = (char *)malloc(sizeof(char) * ketasu);
    x = seisu;
    while (x > 0)
    {
        x = x / 10;
        ketasu++;
    }

    for (i = 0; i < ketasu; i++)
    {
        flag[i] = seisu % 10;
        seisu = seisu / 10;
    }

    for (j = ketasu - 1; j >= 0; j--)
    {
        *tostr = 48 + flag[j];

        tostr++;
    }
    tostr = tostr - ketasu;
    return tostr;
    
}

int strToInt(char const*moji)
{
    int i, j, toint=0;

  while(*moji != '\0')
    {
        toint = toint*10 + (*moji - '0');
        moji++;
    }
    return toint;
}
