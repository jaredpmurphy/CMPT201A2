#include <stdlib.h>
#include <stdio.h>

#include "common.h"





vec2 new_vec2(unsigned int _y, unsigned int _x) {
    vec2 ret;
    ret.x = _x;
    ret.y = _y;
    return ret;
}

area new_area(unsigned int uply, unsigned int uplx, unsigned int lory, unsigned int lorx) {
    area ret;
    ret.uly = uply;
    ret.ulx = uplx;
    ret.lry = lory;
    ret.lrx = lorx;
}