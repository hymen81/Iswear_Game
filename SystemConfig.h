#ifndef __SYSTEM_CONFIG__
#define __SYSTEM_CONFIG__


#define GROUND 32
#define MAX_JUMP_COUNT 3
#define BLOCK_SIZE 32

#define MINVIEW_X 200
#define MAXVIEW_X MINVIEW_X +500

#define MAX_Y (100-1)

#define CAN_MOVE_BLOCK_SIZE 2
#define SKULL_HEATH         2
#define WARRIOR_MOVE_SPEED  5
#define WARRIOR_JUMP_POWER  40

#define HURTING_SPEED 8

#define WARRIOR_SPEED 0.05f

#define SKULL_ATTACK_SPEED(sec) ((sec)*60)

static int canMoveBlock[CAN_MOVE_BLOCK_SIZE] =
{
	1, 2
};

#define OBJECT_DEBUG 1

extern int titleMap[][1000];

#endif