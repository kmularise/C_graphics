#ifndef MINIRT_LIBRARY_H
#define MINIRT_LIBRARY_H
#include <mlx.h>

typedef struct s_date {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

void hello(void);

#endif //MINIRT_LIBRARY_H
