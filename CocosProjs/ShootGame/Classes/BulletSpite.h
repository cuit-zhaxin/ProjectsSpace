//
//  BulletSpite.h
//  ShootGame
//
//  Created by zhaxin on 13-12-4.
//
//

#ifndef __ShootGame__BulletSpite__
#define __ShootGame__BulletSpite__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class Bullet:/*public CCNode*/public CCSprite{
public:
    Bullet();
    ~Bullet();
    virtual void onEnter();
    virtual void onExit();
    
    Bullet* createWithFile(const char* fileName,int bulletType);
    void setIsNotVisiable();
    void setIsVisiable();
    bool getIsVisiable();
    
    Bullet* myBullet;
    bool isVisiable;
    CCSpriteFrameCache* cache;
};

#endif /* defined(__ShootGame__BulletSpite__) */
