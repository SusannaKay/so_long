#include "so_long.h"

static void remove_nl(char *line)
{
    int len;

    len = ft_strlen(line);
    if (line[len - 1] == '\n')
        line[len - 1] = '\0';
}
static int get_map_size(t_map *map)
{
    int fd;
    char *line;
    int len;

    map->rows = 0;
    map->len_row = 0;
    fd = open(map->filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    line = get_next_line(fd);
    while (line)
    {
        len = 0;
        while (line[len] && line[len] != '\n')
            len++;
        if (map->len_row == 0)
            map->len_row = len;
        map->rows++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (map->rows);
}

static void create_matrix(t_map *map)
{
    map->map = (char **)malloc((map->rows + 1) * sizeof(char *));
    if (!map->map)
        map->map = NULL;
}
static char **fill_map(t_map *map)
{
    int fd;
    char *line;
    int i;

    i = 0;
    fd = open(map->filename, O_RDONLY);
    if (fd < 0)
    {
        free(map->map);
        return (NULL);
    }
    line = get_next_line(fd);
    while (line)
    {
        map->map[i] = line;
        remove_nl(map->map[i]);
        i++;
        line = get_next_line(fd);
    }
    map->map[i] = NULL;
    close(fd);
    return (map->map);
}

void read_map(t_map *map)
{
    if (get_map_size(map) < 0)
        return;
    create_matrix(map);
    if (!map->map)
        return;
    if (!fill_map(map))
        return;
}