//
//  GameScene.h
//  ShootGame
//
//  Created by zhaxin on 13-12-3.
//
//

#ifndef __ShootGame__GameScene__
#define __ShootGame__GameScene__

#include <iostream>
#include "ParentClass.h"
#include "PlanLayer.h"

class GameScene:public ParentClass {
public:    
    GameScene();
    ~GameScene();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    static CCScene* scene();
    CREATE_FUNC(GameScene);
    
    void setupViews();
    void bgRoll(float dt);
    void addPlaneLayer();
    void gamePause(CCObject* obj);
    void addPauseBtn();
    
    int score;
    PlanLayer* plane_layer;
    CCTexture2D* pTexture;
};

#endif /* defined(__ShootGame__GameScene__) */
