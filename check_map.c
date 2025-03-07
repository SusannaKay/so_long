// mappa con una soluzione: collectibles accessibili, uscita accessibile : almeno una posizione attorno al carattere, deve essere 0
#include "so_long.h"

// verifica se il numero di righe è diverso dal numero di colonne, e che tutte le righe abbiano la stessa lunghezza
static int is_rectangular(t_map *map)
{
    int i;
    int len_row;
    int num_rows = 0;

    i = 0;
    len_row = ft_strlen(map->map[i]);
    while (map->map[i] != NULL)
    {
        if (ft_strlen(map->map[i]) != len_row)
            return (ft_printf("Error\nMappa non valida"), -1);
        i++;
    }
    num_rows++;
    if (num_rows == len_row)
        return (ft_printf("Error\nMappa non rettangolare"), -1);
    return (0);
}

// controlla se la matrice ha 1 lungo tutti i bordi
static int is_closed(char **map)
{
    int i;
    int len_row;
    int last_row;

    i = 0;
    last_row = 0;

    while (map[last_row] != NULL)
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
        if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
            return (ft_printf("Error\nMappa aperta"), -1);
        i++;
    }
    return (0);
}
// check numero di P, E, numero collezionabili e li salva nella struct
static int parsing_map(t_map *map)
{
    int i;
    int j;
    int p_counter;
    int e_counter;

    i = 0;
    p_counter = 0;
    e_counter = 0;
    while (map->map[i] != NULL)
    {
        j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == 'P')
            {
                if (!p_counter)
                    {
                        p_counter += 1;
                        map->p_x = j;
                        map->p_y = i;
                    }             
                else
                    return (ft_printf("Error\nToo many P"), -1);
            }
            if (map->map[i][j] == 'E')
            {
                if (!e_counter)
                    e_counter += 1;
                else
                    return (ft_printf("Error\nToo many E"), -1);
            }
            if (map->map[i][j] == 'C')
                map->collect++;
            j++;
        }
        i++;
    }
    return(0);
}

int verify_map(t_map *map)
{
    if(is_rectangular(map) < 0 || is_closed(map->map) < 0 || parsing_map(map) < 0)
        return (exit_game(map, NULL), -1);
    return (ft_printf("mappa valida\n"), 0);
}