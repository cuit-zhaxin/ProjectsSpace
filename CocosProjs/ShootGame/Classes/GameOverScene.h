//
//  GameOverScene.h
//  ShootGame
//
//  Created by zhaxin on 13-12-5.
//
//

#ifndef __ShootGame__GameOverScene__
#define __ShootGame__GameOverScene__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;
//using namespace std;

template<typename T>
std::string Convert2String(const T &value)
{
    std::stringstream ss;
	ss << value;
	return ss.str();
}


class GameOverScene:public CCLayerColor {
public:
    
    GameOverScene();
    ~GameOverScene();
    
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(GameOverScene);
    
    void setupViews();
    void restart_callback(CCObject* obj);
    
    CCSize win_size;
    CCSpriteFrameCache* cache;
    CCTexture2D* pTexture;
};

#endif /* defined(__ShootGame__GameOverScene__) */
