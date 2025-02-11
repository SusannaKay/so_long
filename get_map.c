#include "so_long.h"

int check_map_size(const char *filename, int *max_len)
{
    int fd;
    char *line;
    int row_count;
    int len;

    row_count = 0;
    fd = open("./map.ber", O_RDONLY);
    if (fd < 0)
        return (-1);
    line = get_next_line(fd);
    while (line)
    {
        len = 0;
        while (line[len] && line[len] != '\n')
            len++;
        if(*max_len == 0)
            *max_len = len;
        else if (len != *max_len)
        {
            free(line);
            close(fd);
            return(ft_printf("Error\nLa Mappa non e' rettangolare."), -1);
        }
        row_count++;
        free(line);
    }
    close(fd);
    return (row_count);
    }

char    **create_matrix(int row_count, t_data data)
{
    data.map = (char **)malloc((row_count + 1) * sizeof(char));
    if(!data.map)
        return (NULL);
    return(data.map);
}
char **fill_map(const char *filename, t_data data)
{
    int fd;
    char *line;
    int i;

    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        free (data.map);
        return (NULL);
    }
    line = get_next_line(fd);
    while(line)
    {
        data.map[i] = line;
        i++;
    }
    data.map[i] = NULL;
    close(fd);
    return (data.map);
}

char **read_map(const char *filename, t_data data)
{
    int max_len;
    int row_count;

    row_count = check_map_size(filename, &max_len);
    if(row_count < 0)
        return(NULL);
    create_matrix(row_count, data);
    if(!data.map)
        return (NULL);
    fill_map(filename, data);
    return (data.map);
}