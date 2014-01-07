//
//  GameOverScene.cpp
//  ShootGame
//
//  Created by zhaxin on 13-12-5.
//
//

#include "GameOverScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

GameOverScene::GameOverScene(){

    win_size=CCDirector::sharedDirector()->getVisibleSize();
    cache=CCSpriteFrameCache::sharedSpriteFrameCache();
    pTexture=CCTextureCache::sharedTextureCache()->addImage("bg.png");
    SimpleAudioEngine::sharedEngine()->preloadEffect("button.mp3");
}
GameOverScene::~GameOverScene(){}
bool GameOverScene::init(){
    
    bool sRet=false;
    
    do {
        
        CC_BREAK_IF(!CCLayerColor::init());
        
        sRet=true;
    } while (0);
    
    setupViews();
    
    return sRet;
}
CCScene* GameOverScene::scene(){

    CCScene* sc=NULL;
    do {
        sc=CCScene::create();
        CC_BREAK_IF(!sc);
        
        CCLayer* layer=GameOverScene::create();
        CC_BREAK_IF(!layer);
        
        sc->addChild(layer);
    } while (0);
    return sc;
}
void GameOverScene::setupViews(){

    CCSprite* menu_bg=CCSprite::createWithTexture(pTexture, CCRectMake(2, 2, 480, 852));
    menu_bg->setScaleX(0.7);
    menu_bg->setScaleY(0.5);
    menu_bg->setPosition(ccp(win_size.width/2,win_size.height/2));
    addChild(menu_bg,0);
    
    
    CCSprite* btn_restart_nor=CCSprite::createWithTexture(pTexture, CCRectMake(52, 856, 28, 112));
    CCSprite* btn_restart_sel=CCSprite::createWithTexture(pTexture, CCRectMake(52, 856, 28, 112));
    CCMenuItemSprite* btn_restart=CCMenuItemSprite::create(btn_restart_nor, btn_restart_sel, this, menu_selector(GameOverScene::restart_callback));
    
    
    btn_restart->setPosition(ccp(win_size.width/2,btn_restart->getContentSize().height/2+2));
    btn_restart->setRotation(-90);
    
    CCMenu* pMenu = CCMenu::create(btn_restart, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
    int last_score=(CCUserDefault::sharedUserDefault()->getIntegerForKey("LastGameScore"));
    std::string strScore=Convert2String(last_score);
    
    //CCLabelBMFont* score=CCLabelBMFont::create(strScore, "font.fnt");
    CCLabelTTF* finalScores = CCLabelTTF::create(strScore.c_str(), "Helvetica-Blod", 24);
    finalScores->setAnchorPoint(ccp(0.5,0.5));
    finalScores->setScale(2.f);
    finalScores->setPosition(ccp(win_size.width/2,win_size.height/2-100));
    this->addChild(finalScores,10);
    
}
void GameOverScene::restart_callback(CCObject* obj){

    SimpleAudioEngine::sharedEngine()->playEffect("button.mp3");
    CCUserDefault::sharedUserDefault()->setIntegerForKey("LastGameScore", 0);
    CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(1.f, GameScene::scene()));
}