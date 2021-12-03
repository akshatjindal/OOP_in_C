#ifndef SHAPE_H
#define SHAPE_H

#include <stdint.h>

/*
main ideas: 
the way that 'virtual' keyword works in cpp
..is via a Vtable that points to the virtual functions

in C, we can declare our own Vtable 
and have the attributes of said table class be the 
function ptrs that we want to pass to 

further, to allow for late binding (aka dynamic binding), 
what do we want and what do we know?

*/

typedef struct {
    struct Vtable const *vptr; 

    int16_t x;
    int16_t y;
} Shape; 

/*Vtable will have the ptrs 
to the cpp equal 'virtual' functions */
struct Vtable {
    void (*draw)(Shape const * const me);
    uint32_t (*area)(Shape const * const me);
};

//Shape's methods 
void Shape_ctor(
    Shape * const me,
    int16_t x0, 
    int16_t y0); 

void move_shape_by(
    Shape * const me,
    int16_t dx, 
    int16_t dy 
); 

uint16_t distance_from_shape(
    Shape const * const me,
    Shape const * other 
); 

//Virtual calls for dynamic binding 

void Shape_draw_vcall(Shape const * const me); 
uint32_t Shape_area_vcall(Shape const * const me);

static inline void Shape_draw_vcall(Shape const * const me)
{
    me->vptr->draw(me);

static inline uint32_t Shape_area_vcall(Shape const * const me)
{
    return me->vptr->area(me);
}

//draws shape -> calls the correct 'draw'
void draw_graph(Shape const *graph[]);

#endif 