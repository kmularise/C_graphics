#ifndef SCENE_H
# define SCENE_H
# include "utils.h"

typedef struct s_ray{
    t_vector    origin;
    t_vector    dv;
}   t_ray;

t_ray   new_ray(t_vector origin, t_vector dv);
t_vector move_by_dv(t_ray *ray, double t);

#endif