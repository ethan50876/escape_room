#ifndef TYPES_H
#define TYPES_H

#include <osbind.h>

#define ESC_KEY 0x01
#define LEFT_KEY 0x4b
#define RIGHT_KEY 0x4d
#define SPACE_KEY 0x39
#define UP_KEY 0x48
#define DOWN_KEY 0x50

#define GRID_VALUE 16

typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;

typedef enum {
    left, right, up, down
} Direction;

typedef unsigned char bool;

#endif
