//
//  EnemySprite.cpp
//  ShootGame
//
//  Created by zhaxin on 13-12-4.
//
//

#include "EnemySprite.h"

Enemy::Enemy(){
    
    isVisiable=false;
}
Enemy::~Enemy(){
}
void Enemy::onEnter(){
    
    CCSprite::onEnter();
    cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile("shoot.plist");
}
void Enemy::onExit(){
    
    CCSprite::onExit();
}
Enemy* Enemy::createWithFile(const char *fileName,int type){
    
    Enemy* enemy = new Enemy();
    if (type==1) {
        enemy->initWithSpriteFrameName("enemy0.png");
    } else if(type==2){
        enemy->initWithSpriteFrameName("enemy1.png");
    }else{
        enemy->initWithSpriteFrameName("enemy2.png");
    }
    return enemy;
}
void Enemy::setIsVisiable(){
    
    this->setVisible(true);
    isVisiable=true;
    this->runAction(CCSequence::create(CCMoveTo::create(4, ccp(this->getPosition().x,-30)),CCCallFunc::create(this, callfunc_selector(Enemy::setIsNotVisiable)),NULL));
}
bool Enemy::getIsVisiable(){
    
    return isVisiable;
}
void Enemy::setIsNotVisiable(){
    
    this->setVisible(false);
    isVisiable=false;
    this->stopAllActions();
}

