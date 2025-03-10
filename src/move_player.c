#include "../so_long.h"

int move_player(int keycode, t_map *map)
{
    if (keycode == UP)
        // se non e un muro x-1, y
        // prendi vecchi x e y, trasforma valore in 0
        // nuovi valori, se e' C aumenta score +1 , se e' EXIT se score = collezionabili, end game, trasforma valore in P 
    if (keycode == DOWN)
        // se non e un muro x+1, y
    if (keycode == LEFT)
        // se non e un muro x, y - 1
    if (keycode == RIGHT)
        // se non e un muro x, y + 1
    
    // render map
}