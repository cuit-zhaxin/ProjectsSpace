//
//  GamePauseLayer.h
//  ShootGame
//
//  Created by zhaxin on 13-12-5.
//
//

#ifndef __ShootGame__GamePauseLayer__
#define __ShootGame__GamePauseLayer__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class GamePauseLayer:public CCLayerColor {
public:
    
    GamePauseLayer();
    ~GamePauseLayer();
    
    virtual bool init();
    
    static CCScene* scene();
    
    CREATE_FUNC(GamePauseLayer);
    
    void setupViews();
    void resume_callback(CCObject* obj);
    void restart_callback(CCObject* obj);
    void quit_callback(CCObject* obj);
    
    CCSize win_size;
    CCSpriteFrameCache* cache;
    CCTexture2D* pTexture;
};


#endif /* defined(__ShootGame__GamePauseLayer__) */
