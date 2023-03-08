#ifndef TYPES_H
#define TYPES_H

#define ESC_KEY 0x0001001b
#define LEFT_KEY 0x004b0000
#define RIGHT_KEY 0x004d0000
#define SPACE_KEY 0x00390020
#define UP_KEY 0x00480000
#define DOWN_KEY 0x00500000

#define GRID_VALUE 16

typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;

typedef enum {
    left, right, up, down
} Direction;

#endif
