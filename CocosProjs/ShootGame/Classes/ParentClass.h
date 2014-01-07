//
//  ParentClass.h
//  ShootGame
//
//  Created by zhaxin on 13-12-3.
//
//

#ifndef __ShootGame__ParentClass__
#define __ShootGame__ParentClass__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class ParentClass:public CCLayer {
public:
    ParentClass();
    ~ParentClass();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    static CCScene* scene();
    CREATE_FUNC(ParentClass);
    
    CCSize win_size;
    CCSpriteFrameCache* cache;
    CCTexture2D* pTexture;
    CCTexture2D* pTexture2;
};


#endif /* defined(__ShootGame__ParentClass__) */
