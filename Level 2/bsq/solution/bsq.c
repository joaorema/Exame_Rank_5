#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define ERROR "error, invalid map\n"

typedef struct s_bsq
{
    int linhas;             
    int largura;
    char empty;
    char obstacle;
    char fill;
    char **map;
}   t_bsq;

int my_len(char *str)
{
    int i = 0;

    for(; str[i]; i++)
        ;
    return i;
}

int my_min(int a, int b, int c)
{
    if(a < b && a < c)
        return a;
    if(b < c)
        return b;
    return c;
}

void print_bsq(t_bsq *bsq)
{
    for(int y = 0; y < bsq->linhas; y++)
    {
        printf("%s\n", bsq->map[y]);
    }
}

void free_map(t_bsq *bsq, int i)
{
    for(int y = 0; y < i; y++)
        free(bsq->map[y]);
    free(bsq->map);
}

void check_map(t_bsq *bsq)
{
    for(int y = 0; y < bsq->linhas; y++)
    {
        for(int x = 0; x < bsq->largura; x++)
        {
            if(bsq->map[y][x] != bsq->empty && bsq->map[y][x] != bsq->obstacle)
            {
                free_map(bsq, bsq->linhas);
                fputs(ERROR, stdout);
                exit(1);
            }
        }
    }
}

void close_error(t_bsq *bsq, char *av, FILE *file, int i)
{
    if(av)
        fclose(file);
    fputs(ERROR, stdout);
    if(i >= 0)
        free_map(bsq, i);
    exit(1);
}

void parse_bsq(t_bsq *bsq, char *av)
{
    FILE *file;
    if(av)
        file = fopen(av, "r");
    else
        file = stdin;
    if(!file)
    {
        fputs(ERROR, stdout);
        exit(1);
    }

    //scan the first line
    if(fscanf(file, "%d%c%c%c\n", &bsq->linhas, &bsq->empty, &bsq->obstacle, &bsq->fill) != 4)
        close_error(bsq, av, file, -1);
    if(bsq->linhas <= 0)
        close_error(bsq, av, file, -1);
    if(bsq->empty == bsq->fill || bsq->empty == bsq->obstacle || bsq->obstacle == bsq->fill)
        close_error(bsq,av,file,-1);
    
    bsq->map = malloc(sizeof(char *) * bsq->linhas);
    if(!bsq->map)
        close_error(bsq,av,file, -1);
    
    for(int y = 0; y < bsq->linhas; y++)
    {
        char *new = NULL;
        size_t len = 0;
        int new_len = 0;

        if(getline(&new,&len,file) == -1)
            close_error(bsq,av,file,y);
        
        new_len = my_len(new);
        //printf("new_len now :%d", %new_len);
        if(new_len > 0 && new[new_len - 1] == '\n')
            new[new_len - 1] = '\0';
        else if(y < bsq->linhas - 1 && new[new_len - 1] != '\n')
            close_error(bsq,av,file,y);
        
        new_len = my_len(new);
        //printf("new_len now :%d", %new_len);

        if(y == 0)
            bsq->largura = new_len;
        if(y != 0 && y < bsq->linhas -1 && bsq->largura != new_len)
            close_error(bsq,av,file,y);

        bsq->map[y] = new;
    }
    fclose(file);
    check_map(bsq);   //check if any line on map has incorrect char
}

void exec_bsq(t_bsq *bsq)
{
    int square_size[bsq->linhas][bsq->largura];     //store square size
    int max = 0;                                    //biggest possible square
    int best_linha = 0;
    int best_coluna = 0;

    for(int y = 0; y < bsq->linhas; y++)
    {
        for(int x = 0; x < bsq->largura; x++)
        {
            if(bsq->map[y][x] == bsq->obstacle)         //if we found obstacle put 0
                square_size[y][x] = 0;
            else if(y == 0 || x == 0)
                square_size[y][x] = 1;
            else
                square_size[y][x] = my_min(square_size[y - 1][x], square_size[y][x - 1], square_size[y-1][x-1]) + 1;
            if(square_size[y][x] > max)
            {
                max = square_size[y][x];
                best_linha = y;
                best_coluna = x;
            }
            
        }
    }
    int top_linha = best_linha - max + 1;
    int left_coluna = best_coluna - max + 1;
    int end_linha = top_linha + max;
    int end_coluna =left_coluna + max;
    for(int y = top_linha; y < end_linha; y++)
    {
        for(int x = left_coluna; x < end_coluna; x++)
            bsq->map[y][x] = bsq->fill;
    }

}


int main(int ac, char **av)
{
    t_bsq bsq;

    if(ac == 1)
        parse_bsq(&bsq, NULL);
    else if(ac == 2)
        parse_bsq(&bsq, av[1]);
    else
        return(printf("error"), 1);
    exec_bsq(&bsq);
    print_bsq(&bsq);
    free_map(&bsq, bsq.linhas);
}