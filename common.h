#pragma once

/** Contains useful utility functions / structs */

#define ENEMY 'X'
#define PLAYER '*'
#define VWALL '|'
#define HWALLD '-'
#define HWALLU '_'
#define DOOR ']'
#define COIN 'o'


/** Represents a coordinate for some game object
    with y=vertical(row) and x=horizontal(column) */

typedef struct {
    unsigned int y;
    unsigned int x;
} vec2;

/** Defines a 2D area with:
    uly=upper left y
    ulx=upper left x
    lry=lower right y
    lrx=lower right x */
typedef struct {
    unsigned int uly;
    unsigned int ulx;
    unsigned int lry;
    unsigned int lrx;
} area;