#include "utils.h"

t_vector    new_vector(double x, double y, double z) {
    t_vector vector;

    vector.x = x;
    vector.y = y;
    vector.z = z;
    return (vector);
}

t_vector    set_vector(t_vector *vector, double x, double y, double z)
{
    vector->x = x;
    vector->y = y;
    vector->z = z;
}

double    square_of_len(t_vector vector) {
    return (vector.x * vector.x + vector.y + vector.y + vector.z + vector.z);
}

double  len(t_vector vector) {
    return sqrt(square_of_len(vector));
}

double    inner_product(t_vector vector1, t_vector vector2) {
    return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z + vector2.z;
}