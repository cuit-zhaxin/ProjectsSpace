//
//  LoadingScene.cpp
//  ShootGame
//
//  Created by zhaxin on 13-12-4.
//
//

#include "LoadingScene.h"
#include "GameScene.h"

LoadScene::LoadScene(){}
LoadScene::~LoadScene(){}
bool LoadScene::init(){

    bool sRet=false;
    
    do {
        
        CC_BREAK_IF(!ParentClass::init());
        
        sRet=true;
    } while (0);
    
    setupViews();
    
    return sRet;
}
CCScene* LoadScene::scene(){

    CCScene* sc=NULL;
    do {
        sc=CCScene::create();
        CC_BREAK_IF(!sc);
        
        CCLayer* layer=LoadScene::create();
        CC_BREAK_IF(!layer);
        
        sc->addChild(layer);
    } while (0);
    return sc;
}
void LoadScene::replaceScene(){
    
    CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.2F, GameScene::scene()));
}
void LoadScene::setupViews(){

    /*
     
     //    CCSprite* what=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("btn_finish.png"));      //回到游戏
     //    CCSprite* what=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("game_loading1.png"));   //飞机---朝向右
     //    CCSprite* what=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("game_loading2.png"));   //飞机---朝向右,尾部喷气1
     //    CCSprite* what=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("game_loading3.png"));   //飞机---朝向右,尾部喷气2
     //    CCSprite* what=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("game_loading4.png"));   //空
     //    CCSprite* what=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("gameover.png"));        //历史最高成绩 最终成绩
     //    CCSprite* what=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("name.png"));            //飞机大战
     //    CCSprite* what=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("quit_nor.png"));        //退出游戏未选中
     //    CCSprite* what=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("quit_sel.png"));        //退出按钮选中
     //    CCSprite* what=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("restart_nor.png"));     //重新开始
     //    CCSprite* what=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("restart_sel.png"));
     //    CCSprite* what=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("resume_nor.png"));      //继续游戏
     //    CCSprite* what=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("resume_sel.png"));
     //    what->setPosition(ccp(win_size.width/2,win_size.height/2));
     //    this->addChild(what,1);
     
     
     */
//    CCSprite* wel_bg=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("background.png"));
    CCSprite* wel_bg=CCSprite::create("Default.png");
    wel_bg->setPosition(ccp(win_size.width/2,win_size.height/2));
    this->addChild(wel_bg,0);
    
//    CCSprite* game_name=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("name.png"));
//    game_name->setPosition(ccp(win_size.width/2,win_size.height/3*2+50));
//    game_name->setScale(0.5f);
//    this->addChild(game_name,1);
    
    CCSpriteFrame* hero1=CCSpriteFrame::createWithTexture(pTexture, CCRectMake(114, 966, 186, 36));
    hero1->setRotated(-90);
    CCSpriteFrame* hero2=CCSpriteFrame::createWithTexture(pTexture, CCRectMake(82, 856, 108, 37));
    hero2->setRotated(-90);
    CCSpriteFrame* hero3=CCSpriteFrame::createWithTexture(pTexture, CCRectMake(966, 2, 176, 36));
    hero3->setRotated(-90);
    CCSpriteFrame* hero4=CCSpriteFrame::createWithTexture(pTexture, CCRectMake(82, 966, 2, 4));
    hero4->setRotated(-90);
    
    
    CCArray* pArray=CCArray::create();
    pArray->addObject(hero1);
    pArray->addObject(hero2);
    pArray->addObject(hero3);
    pArray->addObject(hero4);
    
    CCAnimation* pAnimation=CCAnimation::createWithSpriteFrames(pArray,0.5f);
    if (!pAnimation) {
        return ;
    }
    
    CCAnimate* pAnimate=CCAnimate::create(pAnimation);
    
    CCSprite *hero =CCSprite::createWithSpriteFrame(cache->spriteFrameByName("game_loading1.png"));
    
    hero->setPosition(ccp(win_size.width/2,win_size.height/2-40));
    this->addChild(hero,1);
    
    
    CCCallFunc* func=CCCallFunc::create(this, callfunc_selector(LoadScene::replaceScene));
    
    CCActionInterval* seq=CCSequence::create(pAnimate,func,NULL);
    
    hero->runAction(seq);

}
