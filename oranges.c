#include <cstdio>

#define IMAX 15
#define JMAX 15
int oranges[IMAX][JMAX];

void init()
{
    for (int i=0; i<IMAX; i++)
        for (int j=0; j<JMAX; j++)
            oranges[i][j] = 1;
    oranges[7][7] = 2;
}

void dump()
{
    for (int i=0; i<IMAX; i++)
    {
        for (int j=0; j<JMAX; j++)
            printf("%1d", oranges[i][j]);
        printf("\n");
    }
    getchar();
}

bool inrange(int i, int j)
{
    return ((i>-1) && (i<IMAX) && (j>-1) && (j<JMAX));
}

bool anyfresh()
{
    bool found = false;
    for (int i=0; i<IMAX; i++)
        for (int j=0; j<JMAX; j++)
            if (oranges[i][j] == 3)
                oranges[i][j] = 2;
            else if (oranges[i][j] == 1)
                found = true;
    return found;
}

void infect()
{
    for (int i=0; i<IMAX; i++)
        for (int j=0; j<JMAX; j++)
            if (oranges[i][j] == 2)
            {
                if ((inrange(i, (j-1))) && (oranges[i][(j-1)] == 1))
                    oranges[i][(j-1)] = 3;
                if ((inrange(i, (j+1))) && (oranges[i][(j+1)] == 1))
                    oranges[i][(j+1)] = 3;
                if ((inrange((i-1), j)) && (oranges[(i-1)][(j)] == 1))
                    oranges[(i-1)][j] = 3;
                if ((inrange((i+1), j)) && (oranges[(i+1)][(j)] == 1))
                    oranges[(i+1)][j] = 3;
            }
}

main()
{	
    init();
    int iter = 0;
    printf("Original\n");
    dump();
    while (anyfresh())
    {
        infect();
        iter++;
        printf("Iteration %d\n", iter);
        dump();
    }
}