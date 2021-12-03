#include "polymorphism/rectangle.h"

void Rectangle_ctor(
    Rectangle * const me, 
    int16_t x0, int16_t y0, 
    uint16_t w0, uint16_t h0)
{

    static const struct Vtable vtable = {
        &Rectangle_draw, 
        &Rectangle_area
    };

    Shape_ctor(&me->super, x0, y0);
    me->width = w0; 
    me->height = h0; 
}

void draw_rectangle(
    Rectangle const * const me)
{
    printf("drawing rectangle w/ height %d", me->height); 
    printf("and w/ width %d", me->width); 

}

uint32_t get_rectangle_area(
    Rectangle const * const me)
{
    return me->width * me->height; 
}
