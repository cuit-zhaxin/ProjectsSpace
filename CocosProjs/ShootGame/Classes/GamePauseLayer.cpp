//
//  GamePauseLayer.cpp
//  ShootGame
//
//  Created by zhaxin on 13-12-5.
//
//

#include "GamePauseLayer.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
using namespace CocosDenshion;

GamePauseLayer::GamePauseLayer(){
    
    win_size=CCDirector::sharedDirector()->getVisibleSize();
    cache=CCSpriteFrameCache::sharedSpriteFrameCache();
    pTexture=CCTextureCache::sharedTextureCache()->addImage("bg.png");
    SimpleAudioEngine::sharedEngine()->preloadEffect("button.mp3");
}
GamePauseLayer::~GamePauseLayer(){}
bool GamePauseLayer::init(){
    
    bool sRet=false;
    
    do {
        
        CC_BREAK_IF(!CCLayerColor::init());
        
        sRet=true;
    } while (0);
    
    setupViews();
    
    return sRet;
}
CCScene* GamePauseLayer::scene(){
    
    CCScene* sc=NULL;
    do {
        sc=CCScene::create();
        CC_BREAK_IF(!sc);
        
        CCLayer* layer=GamePauseLayer::create();
        CC_BREAK_IF(!layer);
        
        sc->addChild(layer);
    } while (0);
    return sc;
}
void GamePauseLayer::setupViews(){
    
    CCSprite* menu_bg=CCSprite::createWithTexture(pTexture, CCRectMake(484, 2, 480, 852));
    menu_bg->setScaleX(0.7);
    menu_bg->setScaleY(0.5);
    menu_bg->setPosition(ccp(win_size.width/2,win_size.height/2));
    //menu_bg->setVisible(false);
    addChild(menu_bg,0);
    
    
    CCSprite* btn_resume_nor=CCSprite::createWithTexture(pTexture, CCRectMake(52, 970, 54, 26));
    CCSprite* btn_resume_sel=CCSprite::createWithTexture(pTexture, CCRectMake(52, 970, 54, 26));
    CCMenuItemSprite* btn_resume=CCMenuItemSprite::create(btn_resume_nor, btn_resume_sel, this, menu_selector(GamePauseLayer::resume_callback));
    btn_resume->setPosition(ccp(win_size.width/2,win_size.height/2+30));
    //btn_resume->setRotation(-90);
    
    CCSprite* btn_restart_nor=CCSprite::createWithTexture(pTexture, CCRectMake(52, 856, 28, 112));
    CCSprite* btn_restart_sel=CCSprite::createWithTexture(pTexture, CCRectMake(52, 856, 28, 112));
    CCMenuItemSprite* btn_restart=CCMenuItemSprite::create(btn_restart_nor, btn_restart_sel, this, menu_selector(GamePauseLayer::restart_callback));
    btn_restart->setPosition(ccp(win_size.width/2,btn_resume->getPosition().y-40));
    btn_restart->setRotation(-90);
    
    CCSprite* btn_quit_nor=CCSprite::createWithTexture(pTexture, CCRectMake(2, 998, 110, 24));
    CCSprite* btn_quit_sel=CCSprite::createWithTexture(pTexture, CCRectMake(2, 998, 110, 24));
    CCMenuItemSprite* btn_quit=CCMenuItemSprite::create(btn_quit_nor, btn_quit_sel, this, menu_selector(GamePauseLayer::quit_callback));
    btn_quit->setPosition(ccp(win_size.width/2,btn_restart->getPosition().y-40));
    //btn_quit->setRotation(-90);
    
    CCMenu* pMenu = CCMenu::create(btn_resume,btn_restart,btn_quit, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 4);
    //setTouchPriority(-300);
}
void GamePauseLayer::restart_callback(CCObject* obj){
    
    CCUserDefault::sharedUserDefault()->setBoolForKey("isGamePause", false);
    SimpleAudioEngine::sharedEngine()->playEffect("button.mp3");
    CCDirector::sharedDirector()->resume();
    CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(1.f, GameScene::scene()));
}
void GamePauseLayer::resume_callback(CCObject* obj){
    
    CCUserDefault::sharedUserDefault()->setBoolForKey("isGamePause", false);
    SimpleAudioEngine::sharedEngine()->playEffect("button.mp3");
    this->setVisible(false);
    CCDirector::sharedDirector()->resume();
}
void GamePauseLayer::quit_callback(CCObject* obj){
    
    CCUserDefault::sharedUserDefault()->setBoolForKey("isGamePause", false);
    SimpleAudioEngine::sharedEngine()->playEffect("button.mp3");
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
