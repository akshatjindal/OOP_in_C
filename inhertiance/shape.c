#include "shape.h"

void Shape_ctor(
    Shape * const me,
    int16_t x0, 
    int16_t y0)
{    
    me->x = x0; 
    me->y = y0;     
} 

void move_shape_by(
    Shape * const me,
    int16_t dx, 
    int16_t dy 
)
{
    me->x += dx; 
    me->y += dy; 
} 


uint16_t distance_from_shape(
    Shape const * const me,
    Shape const * other 
)
{
    //return arbitrary distance (unsigned)
    return 5; 
} 





