//
//  BulletSpite.cpp
//  ShootGame
//
//  Created by zhaxin on 13-12-4.
//
//

#include "BulletSpite.h"

Bullet::Bullet(){

    isVisiable=false;
}
Bullet::~Bullet(){
}

void Bullet::onEnter(){

    CCSprite::onEnter();
    cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile("shoot.plist");
}
void Bullet::onExit(){

    CCSprite::onExit();
}

Bullet* Bullet::createWithFile(const char *fileName,int bulletType){

    Bullet* bullet = new Bullet();
    if (bulletType==1) {
        bullet->initWithSpriteFrameName("bullet1.png");
    } else {
        bullet->initWithSpriteFrameName("bullet2.png");
    }
    return bullet;
}
void Bullet::setIsVisiable(){

    CCSize win_size=CCDirector::sharedDirector()->getWinSize();
    this->setVisible(true);
    isVisiable=true;
    this->runAction(CCSequence::create(CCMoveTo::create(0.3f, ccp(this->getPosition().x,win_size.height+100)),CCCallFunc::create(this, callfunc_selector(Bullet::setIsNotVisiable)),NULL));
}
bool Bullet::getIsVisiable(){

    return isVisiable;
}
void Bullet::setIsNotVisiable(){
    
    this->setVisible(false);
    isVisiable=false;
    this->stopAllActions();
}

