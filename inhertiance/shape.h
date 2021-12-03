#ifndef SHAPE_H
#define SHAPE_H

#include <stdint.h>

typedef struct {
    int16_t x;
    int16_t y;
} Shape; 


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

#endif 