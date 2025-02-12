// OK mappa rettangolare
// OK tutte le righe della stessa lunghezza, lunghezza != da numero di righe
// OK mappa chiusa : tutti i bordi devono avere 1
// mappa con una soluzione: collectibles accessibili, uscita accessibile : almeno una posizione attorno al carattere, deve essere 0
// 1 exit (E), almeno 1 collectible (C), 1 starting position (P)
#include "so_long.h"

int is_rectangular(char **map)
{
    int row_count;
    int len_row;

    row_count = 0;
    len_row = 0;
    while(map[row_count] != NULL)
    {
        if (len_row == 0)
            len_row = ft_strlen(map[row_count]);
        else
            {
                if (ft_strlen(map[row_count]) != len_row)
                    return(ft_printf("Error\nMappa non valida"), -1);
            }
        row_count++;    
    }
    if (row_count == len_row)
        return(ft_printf("Error\nMappa non rettangolare"), -1);
    return (0);
}

int is_closed(char **map)
{
    int row_count;
    int len_row;
    int last_row;

    row_count = 0;
    last_row = 0;

    while(map[last_row] != NULL)
        last_row++;
    last_row--;
    while (map[row_count])
    {
        len_row = 0;
        while (map[row_count][len_row])
        {
            if ((row_count == 0 || row_count == last_row) && map[row_count][len_row] != '1')
                return (ft_printf("Error\nMappa aperta"), -1);
            len_row++;
        }
        if (map[row_count][0] != '1' && map[row_count][ft_strlen(map[row_count]) - 1] != '1')
            return (ft_printf("Error\nMappa aperta"), -1);
        row_count++;
    }
    return (0);
}
