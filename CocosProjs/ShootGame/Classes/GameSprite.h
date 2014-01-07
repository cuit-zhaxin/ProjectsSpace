//
//  GameSprite.h
//  ShootGame
//
//  Created by zhaxin on 13-12-4.
//
//

#ifndef __ShootGame__GameSprite__
#define __ShootGame__GameSprite__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class GameSprite:public CCNode {
    
public:
    GameSprite();
    virtual ~GameSprite();
    
    void moveStart();
    void restart();
 
    CCTexture2D* pTexture2;
    CCSprite* mySprite;
    int state;
};

#endif /* defined(__ShootGame__GameSprite__) */
