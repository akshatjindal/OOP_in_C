#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

/*  key takeaway:
    the ordering matters. 
    If you put Shape x below the width for ex. 
        the rect class wont derive from the Shape class
    
    reason: this is defined in the C standard

    pretty much equiv to class Rect: public Shape
*/
typedef struct {
    Shape super; 

    uint16_t width; 
    uint16_t height; 
} Rectangle; 

void Rectangle_ctor(
    Rectangle * const me, 
    int16_t x0, int16_t y0, 
    uint16_t w0, uint16_t h0
); 

void draw_rectangle(
    Rectangle const * const me
); 

uint32_t get_rectangle_area(
    Rectangle const * const me
);

#endif 