#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
 
# define X_EVENT_KEY_PRESS        2
# define X_EVENT_KEY_release    3
# define X_EVENT_KEY_EXIT        17
 
# define KEY_ESC    53
# define KEY_W        13
# define KEY_A        0
# define KEY_S        1
# define KEY_D        2
 
typedef struct    s_data
{
    int            x;
    int            y;
}                t_data;
 
int        key_press(int keycode, t_data *data)
{
    if (keycode == KEY_A)
        data->x--;
    if (keycode == KEY_D)
        data->x++;
    if (keycode == KEY_W)
        data->y++;
    if (keycode == KEY_S)
        data->y--;
    printf("x:y = %d:%d\n", data->x, data->y);
    if (keycode == KEY_ESC)
        exit(0);
    return (0);
}
 
int        key_release(int keycode, t_data *data)
{
    printf("key release: %d\n %d:%d\n", keycode, data->x, data->y);
    return (0);
}
 
int        key_exit(int keycode, t_data *data)
{
    printf("key_exit : %d\n %d:%d\n", keycode, data->x, data->y);
    exit(0);
}
 
int        main(void)
{
    void    *mlx;
    void    *win;
    t_data    data;
    data.x = 0;
    data.y = 0;
 
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "title");
    mlx_hook(win, X_EVENT_KEY_PRESS, 0, key_press, &data);
    mlx_hook(win, X_EVENT_KEY_release, 0, key_release, &data);
    mlx_hook(win, X_EVENT_KEY_EXIT, 0, key_exit, &data);
    mlx_loop(mlx);
    return (0);
}