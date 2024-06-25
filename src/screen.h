#ifndef SCREEN_H
#define SCREEN_H

#pragma once
#include <stdint.h>
//#include <include/types.h>
//#include "screen.c"

//void set_pixel(int x, int y, uint32_t color);
uint32_t get_offset(int x, int y);
extern volatile uint32_t* fb_addr;

typedef struct {
    int x;
    int y;
} Vector2;
// Vector2 font_dimensions = {8, 8};

#endif