#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int count_around(int y, int x, int altura, int largura, int box[altura][largura])
{
    int result = 0;
    for(int yy = -1; yy <= 1; yy++)
    {
        for(int xx = -1; xx <= 1; xx++)
        {
            if(xx == 0 && yy == 0)
                continue;
            int new_y = y + yy;
            int new_x = x + xx;
            if(new_y >= 0 && new_x >= 0 && new_y < altura && new_x < largura)
            {
                result += box[new_y][new_x];
            }
        }
    }
    return result;
}


int main(int ac, char **av)
{
    if(ac != 4)
        return 1;

    int altura = atoi(av[1]);
    int largura = atoi(av[2]);
    int iter = atoi(av[3]);
    int box[altura][largura];

    for(int y = 0; y < altura; y++)
    {
        for(int x = 0; x < largura; x++)
        {
            box[y][x] = 0;           
        }
    }

    int x = 0;
    int y = 0;
    int pen = 0;
    char c;
    while(read(0,&c,1))
    {
        if(c == 'w' && y > 0)
            y--;
        else if(c == 's' && y < altura - 1)
            y++;
        else if(c == 'a' && x > 0)
            x--;
        else if(c == 'd' && x < largura - 1)
            x++;
        else if(c == 'x' && pen)
            pen = 0;
        else if(c == 'x' && !pen)
            pen = 1;
        if(pen)
            box[y][x] = 1;
    }

    int new[altura][largura];

    for(int it = 0; it < iter ; it++)
    {
        for(int y = 0; y < altura; y++)
        {
            for(int x = 0; x < largura; x++)
            {
                int n = count_around(y,x,altura,largura,box);
                
                if(box[y][x] && (n == 2 || n == 3))
                    new[y][x] = 1;
                else if(!box[y][x] && n == 3)
                    new[y][x] = 1;
                else
                    new[y][x] = 0;
            }
        }
        for(int y = 0; y < altura; y++)
        {
            for(int x = 0; x < largura; x++)
            {
                box[y][x] = new[y][x];        
            }
        }
    }
    for(int y = 0; y < altura; y++)
    {
        for(int x = 0; x < largura; x++)
        {
            putchar(box[y][x] ? '0' : ' ');       
        }
        putchar('\n');
    }

}
