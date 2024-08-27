#pragma once
#ifndef _ROBOT_DEF_H
#define _ROBOT_DEF_H

#include <iostream>

// DEFINES
#define _ORIGN_X 0
#define _ORIGN_Y 0

#define _PLACE "PLACE"
#define _MOVE "MOVE"
#define _LEFT "LEFT"
#define _RIGHT "RIGHT"
#define _REPORT "REPORT"

#define _TBL_MX_X 5
#define _TBL_MX_Y 5

// ENUMS
enum CMD_ENUM
{
    CMD_EMPTY = -1,
    CMD_PLACE = 0,
    CMD_MOVE = 1,
    CMD_LEFT = 2,
    CMD_RIGHT = 3,
    CMD_REPORT = 4
};

enum ROBOT_FACE_ENUM
{
    NORTH = 0,
    EAST = 1,
    WEST = 2,
    SOUTH = 3,
    INVALID_FACE = 4
};

// Structs
typedef struct _ttable
{
    CMD_ENUM _cmd;
    long int *_pos;
} TablePosition;

#endif