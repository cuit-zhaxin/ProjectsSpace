//
//  GameScene.cpp
//  ShootGame
//
//  Created by zhaxin on 13-12-3.
//
//

#include "GameScene.h"
#include "GamePauseLayer.h"
#include "SimpleAudioEngine.h"

void GameScene::onEnter(){

    ParentClass::onEnter();
    CCUserDefault::sharedUserDefault()->setBoolForKey("isGamePause", false);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("LastGameScore", 0);
}
void GameScene::onExit(){

    CCUserDefault::sharedUserDefault()->setIntegerForKey("LastGameScore", 0);
    ParentClass::onExit();
}
GameScene::GameScene(){

    score=0;
    SimpleAudioEngine::sharedEngine()->preloadEffect("button.mp3");
    pTexture=CCTextureCache::sharedTextureCache()->addImage("shoot.png");
}
GameScene::~GameScene(){}
bool GameScene::init(){
    
    bool sRet=false;
    
    do {
        
        CC_BREAK_IF(!ParentClass::init());
        
        setupViews();
        
        sRet=true;
    } while (0);
    
    return sRet;
}
CCScene* GameScene::scene(){
    
    CCScene* sc=NULL;
    do {
        sc=CCScene::create();
        CC_BREAK_IF(!sc);
        
        CCLayer* layer=GameScene::create();
        CC_BREAK_IF(!layer);
        
        sc->addChild(layer);
    } while (0);
    return sc;
}
void GameScene::setupViews(){
    
    CCSprite* bg1=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("background.png"));
    bg1->setAnchorPoint(ccp(0,0));
    bg1->setPosition(ccp(0,0));
    this->addChild(bg1,-1,1);
    
    CCSprite* bg2=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("background.png"));
    bg2->setAnchorPoint(ccp(0,0));
    bg2->setPosition(ccp(0,bg1->getContentSize().height-1));
    this->addChild(bg2,-1,2);
    
    schedule(schedule_selector(GameScene::bgRoll), 0.02f);
    
    addPlaneLayer();
    addPauseBtn();
}
void GameScene::addPauseBtn(){

    CCSprite* btn_pause_nor=CCSprite::createWithTexture(pTexture, CCRectMake(336, 2, 42, 45));
    CCSprite* btn_pause_sel=CCSprite::createWithTexture(pTexture, CCRectMake(289, 2, 42, 24));
    CCMenuItemSprite* btn_pause=CCMenuItemSprite::create(btn_pause_nor, btn_pause_sel, this, menu_selector(GameScene::gamePause));
    btn_pause->setRotation(-90);
    btn_pause->setScale(0.6f);
    
    CCMenu* pMenu = CCMenu::create(btn_pause, NULL);
    pMenu->setAnchorPoint(ccp(0,1));
    pMenu->setPosition(20,win_size.height-20);
    this->addChild(pMenu, 3);
}
void GameScene::addPlaneLayer(){

    plane_layer=PlanLayer::create();
    this->addChild(plane_layer);
}
void GameScene::bgRoll(float dt){
    
    if (!plane_layer->heroDie) {
        
        CCSprite* bg1=(CCSprite*)this->getChildByTag(1);
        CCSprite* bg2=(CCSprite*)this->getChildByTag(2);
        
        //if (bg1->getPosition().y >= win_size.height+bg1->getContentSize().height) {
        if (bg1->getPosition().y <= -(bg1->getContentSize().height)) {
            
            bg1->setPosition(ccp(0,bg2->getPosition().y+bg2->getContentSize().height-1));
        }
        
        if (bg2->getPosition().y <= -(bg2->getContentSize().height)) {
            bg2->setPosition(ccp(0,bg1->getPosition().y+bg1->getContentSize().height-1));
        }
        
        bg1->setPosition(ccpAdd(bg1->getPosition(), ccp(0, -5)));
        bg2->setPosition(ccpAdd(bg2->getPosition(), ccp(0, -5)));
        
    }else{
    
        stopAllActions();
    }
}
void GameScene::gamePause(CCObject* obj){

    SimpleAudioEngine::sharedEngine()->playEffect("button.mp3");
    CCDirector::sharedDirector()->pause();
    CCUserDefault::sharedUserDefault()->setBoolForKey("isGamePause",true);
    
    GamePauseLayer* gamepause_layer=GamePauseLayer::create();
    gamepause_layer->setColor(ccc3(85, 85, 85));
    gamepause_layer->setOpacity(100);
    gamepause_layer->ignoreAnchorPointForPosition(false);
    gamepause_layer->setAnchorPoint(ccp(0.5,0.5));
    gamepause_layer->setPosition(ccp(win_size.width/2,win_size.height/2));
    this->addChild(gamepause_layer,4);
}
