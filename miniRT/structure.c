#include "scene.h"

typedef struct  s_camera{
    t_vector    origin;
    t_vector    dx;
    t_vector    dy;
    double      viewport_height;
    double      viewport_width;
    double      focal_len;


}   t_camera;

typedef struct  s_canvas{
    int width;
    int height;
    double ratio;
}   t_canvas;