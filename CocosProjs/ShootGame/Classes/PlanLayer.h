//
//  PlanLayer.h
//  ShootGame
//
//  Created by zhaxin on 13-12-3.
//
//

#ifndef __ShootGame__PlanLayer__
#define __ShootGame__PlanLayer__

#include <iostream>
#include "ParentClass.h"
#include "EnemySprite.h"
#include "BulletSpite.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

class PlanLayer:public ParentClass {
public:
    PlanLayer();
    ~PlanLayer();
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(PlanLayer);
    
    void setupViews();
    void addEnmy();
    void addBullets();
    void releaseBullets();
    void enemyMove();
    bool isCollision(CCPoint p1,int w1,int h1,CCPoint p2,int w2,int h2);
    void update(float dt);
    void heroBomb();
    void enemyBomb();
    void gameOver();
    void changeScore();
    
    CCArray* pEnemys;
    CCArray* pBullets;
    CCSprite* hero;
    Enemy* enemy_check;
    Bullet* bullet;
    Enemy* enemy;
    int randomCount;
    int bullerCount;
    bool heroDie;
    int score;
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
};

#endif /* defined(__ShootGame__PlanLayer__) */
