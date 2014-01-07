//
//  EnemySprite.h
//  ShootGame
//
//  Created by zhaxin on 13-12-4.
//
//g

#ifndef __ShootGame__EnemySprite__
#define __ShootGame__EnemySprite__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class Enemy:public CCSprite{
public:
    Enemy();
    ~Enemy();
    virtual void onEnter();
    virtual void onExit();
    
    Enemy* createWithFile(const char* fileName,int type);
    void setIsNotVisiable();
    void setIsVisiable();
    bool getIsVisiable();
    
    bool isVisiable;
    CCSpriteFrameCache* cache;
};

#endif /* defined(__ShootGame__EnemySprite__) */
