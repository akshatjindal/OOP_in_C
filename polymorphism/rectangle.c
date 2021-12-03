#include "polymorphism/rectangle.h"

void Rectangle_ctor(
    Rectangle * const me, 
    int16_t x0, int16_t y0, 
    uint16_t w0, uint16_t h0)
{

    static const struct Vtable vtable = {
        (void (*) (Shape const * const me))&draw_rectangle, 
        (uint32_t (*)(Shape const * const me))&get_rectangle_area
    };

    Shape_ctor(&me->super, x0, y0); 
    
    //now shape's vptr will point to the vtable we defined 
    //..above instead of the one it currently points to (the shape's vtable)
    me->super.vptr = &vtable;
    
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
