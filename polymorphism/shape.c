#include "polymorphism/shape.h"

/*
- the main aim is for correct function (aka the func
of the correct child - given that u have multiple funcs
with the same name 
) to run on runtime

what do we know? 
- we know that c doesnt automatically upcast

--- Static
we let the Vtable be static (in ctor) so that it is not on 
the stack. 

*/

void Shape_ctor(
    Shape * const me,
    int16_t x0, 
    int16_t y0)
{   

    static const struct Vtable vtable = {
        &Shape_draw,
        &Shape_area
    };


    me->x = x0; 
    me->y = y0;     
} 

static void Shape_draw(
    Shape const * const me)
{
    (void)me; 
}

static uint32_t Shape_area(Shape const * const me){
    (void)me;
    //return arbitrary number as the shape may 
    //have an area - like a line  
    return 10;
}

void move_shape_by(
    Shape * const me,
    int16_t dx, 
    int16_t dy)
{
    me->x += dx; 
    me->y += dy; 
} 


uint16_t distance_from_shape(
    Shape const * const me,
    Shape const * other)
{
    //return arbitrary distance (unsigned)
    return 5; 
} 






