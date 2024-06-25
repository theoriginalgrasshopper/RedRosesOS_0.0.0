#include <stdint.h>
#include "screen.h"
//#include <include/font.h>
#include "font.h"
#include <stddef.h>
//#include "main.c"

// FRABEBUFFER ADDRESS
volatile uint32_t* fb_addr;
void set_pixel(int x, int y, uint32_t color) {
    if ((x >= 0 && (uint64_t) x < 1280) && (y >= 0 && (uint64_t) y < 800))
        fb_addr[get_offset(x, y)] = color;
    }

uint32_t get_offset(int x, int y) {
    return y * 1280 + x;
    }

void print_char_at(char c, int x, int y, uint32_t color) {
    if (c != '\n') {
        for (size_t yy = 0; yy < 8; yy++) {
            for (size_t xx = 0; xx < 8; xx++) {

                if ((font[(size_t) c][yy]) & (1 << xx))
                    // Set the character's pixels
                    set_pixel(x * 8 + xx, y * 8 + yy, color);
                else 
                    // erase anything that's under the char (haha bye unwanted cursor)
                    set_pixel(x * 8 + xx, y * 8 + yy, 0xffffff);
            }
        }

    }
}
    