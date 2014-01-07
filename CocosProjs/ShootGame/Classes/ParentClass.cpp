//
//  ParentClass.cpp
//  ShootGame
//
//  Created by zhaxin on 13-12-3.
//
//

#include "ParentClass.h"

ParentClass::ParentClass(){

    cache=CCSpriteFrameCache::sharedSpriteFrameCache();
    pTexture=CCTextureCache::sharedTextureCache()->addImage("bg.png");
    pTexture2=CCTextureCache::sharedTextureCache()->addImage("shoot.png");
    cache->addSpriteFramesWithFile("bg.plist", "bg.png");
    cache->addSpriteFramesWithFile("shoot.plist", "shoot.png");
    win_size=CCDirector::sharedDirector()->getWinSize();
}
ParentClass::~ParentClass(){

    delete cache;
}
bool ParentClass::init(){
    
    bool sRet=false;
    
    do {
        
        CC_BREAK_IF(!CCLayer::init());
        
        sRet=true;
    } while (0);
    
    return sRet;
}
CCScene* ParentClass::scene(){
    
    CCScene* sc=NULL;
    do {
        sc=CCScene::create();
        CC_BREAK_IF(!sc);
        
        CCLayer* layer=ParentClass::create();
        CC_BREAK_IF(!layer);
        
        sc->addChild(layer);
    } while (0);
    return sc;
}
void ParentClass::onEnter(){

    CCLayer::onEnter();
}
void ParentClass::onExit(){

    CCLayer::onExit();
}