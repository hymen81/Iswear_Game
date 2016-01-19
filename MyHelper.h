#ifndef _HELPER_
#define _HELPER_

#include "MyShake.h"
#include "SimpleAudioEngine.h"

typedef enum
{
	upArrow,
	leftArrow,
	rightArrow,
	attackButton
}INPUT_ARROW_BL;

typedef enum
{
	goBack,
	goForward
}DIRECTION;

typedef enum
{
	p10,
	p20,
	p30,
	p40,
	p50,
	p60,
	p70,
	p80,
	p90,
	p100,
}LOADING_PERCENT;


#define FOR(x) for(int index =0; index< (x).size();index++)
#define REMOVE_DELETE_SPRITE(l,x) FOR((x)){(l)->removeChild((x).at(index)); (x).clear();}

#define FOR_LAYER_CHILD(x) (int i = 0; i < (x)->getChildren().size(); i++)

#define CREATE_FUNC_FILE(__TYPE__) \
static __TYPE__* create(std::string __FILENAME__) \
		{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->initWithFile(__FILENAME__)) \
			    { \
        pRet->autorelease(); \
        return pRet; \
			    } \
							    else \
			    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
			    } \
		}

#define EACH_BLOCK2(_x_) (\
	for(int i = 0; i< CAN_MOVE_BLOCK_SIZE;i++)\
	    if(titleMap[titleY][titleX] != canMoveBlock[i])\
			_x_ = true;\
								else\
				_x_ = false;\
)

//#define COULD_NOT_BLOCK(y,x) titleMap[y][x] != 1  && titleMap[y][x] != 2 && titleMap[y][x] != 0
#define COULD_NOT_BLOCK(y,x) titleMap[y][x] != 129  && titleMap[y][x] != 143 && titleMap[y][x] != 0 && titleMap[y][x] != 13 && titleMap[y][x] != 30

#define COULD_NOT_BLOCK2 

#define SPEED_ZERO 0

#define PLAY_SE(s) CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(s,false,1.0f,0.0f,1.0f)



#endif