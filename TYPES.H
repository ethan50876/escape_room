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
#define MAX_ROOMS 10
#define MAX_BOUNDARIES 9
#define MAX_DOORS 4

#define SYSTEM_CLOCK 0x462

typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;

typedef enum {
    left, right, up, down
} Direction;

typedef int bool;
#define true 1
#define false 0

#endif
