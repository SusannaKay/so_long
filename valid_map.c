// OK mappa rettangolare
// OK tutte le righe della stessa lunghezza, lunghezza != da numero di righe
// OK mappa chiusa : tutti i bordi devono avere 1
// mappa con una soluzione: collectibles accessibili, uscita accessibile : almeno una posizione attorno al carattere, deve essere 0
// 1 exit (E), almeno 1 collectible (C), 1 starting position (P)
#include "so_long.h"

static int is_rectangular(t_map *map)
{
    int i;
    int len_row;

    i = 0;
    len_row = ft_strlen(map->map[i]);
    while(map->map[i] != NULL)
    {
        if (ft_strlen(map->map[i]) != len_row)
            return(ft_printf("Error\nMappa non valida"), -1);

        i++;    
    }
    if (i == len_row)
        return(ft_printf("Error\nMappa non rettangolare"), -1);
    return (0);
}


static int is_closed(char **map)
{
    int i;
    int len_row;
    int last_row;

    i = 0;
    last_row = 0;

    while(map[last_row] != NULL)
        last_row++;
    last_row--;
    while (map[i])
    {
        len_row = 0;
        while (map[i][len_row])
        {
            if ((i == 0 || i == last_row) && map[i][len_row] != '1')
                return (ft_printf("Error\nMappa aperta"), -1);
            len_row++;
        }
        if (map[i][0] != '1' && map[i][ft_strlen(map[i]) - 1] != '1')
            return (ft_printf("Error\nMappa aperta"), -1);
        i++;
    }
    return (0);
}

int verify_map(t_map *map)
{
    is_rectangular(map);
    ft_printf("%d",is_closed(map->map));

    return(ft_printf("mappa valida"), 0);
}