#ifndef COMMON_GAME_H
#define COMMON_GAME_H

/** Contains useful utility functions / structs */

#define GHOST 'X'
#define PLAYER '*'
#define VWALL '|'
#define HWALLD '-'
#define HWALLU '_'
#define DOOR ']'
#define COIN 'o'

#define UP new_vec2(-1,0)
#define DOWN new_vec2(1,0)
#define LEFT new_vec2(0,-1)
#define RIGHT new_vec2(0,1)

/** Represents a coordinate for some game object
    with y=vertical(row) and x=horizontal(column) */

typedef struct {
    int y;
    int x;
} vec2;

vec2 new_vec2(int y, int x);

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

area new_area(unsigned int uply, unsigned int uplx, unsigned int lory, unsigned int lorx);

#endif