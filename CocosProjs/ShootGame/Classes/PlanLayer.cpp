//
//  PlanLayer.cpp
//  ShootGame
//
//  Created by zhaxin on 13-12-3.
//
//

#include "PlanLayer.h"
#include "GameOverScene.h"

PlanLayer::PlanLayer(){
    
    heroDie=false;
    bullerCount=5;
    randomCount=5;
    pEnemys=new CCArray();
    pEnemys->initWithCapacity(randomCount);
    pBullets=new CCArray();
    pBullets->initWithCapacity(bullerCount);
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    SimpleAudioEngine::sharedEngine()->preloadEffect("bullet.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect("game_over.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect("bomb.mp3");
}
PlanLayer::~PlanLayer(){
    hero=NULL;
}
bool PlanLayer::init(){

    bool sRet=false;
    
    do {
        
        CC_BREAK_IF(!ParentClass::init());
        
        setupViews();
        
        sRet=true;
    } while (0);
    
    return sRet;
}
CCScene* PlanLayer::scene(){

    CCScene* sc=NULL;
    do {
        sc=CCScene::create();
        CC_BREAK_IF(!sc);
        
        CCLayer* layer=PlanLayer::create();
        CC_BREAK_IF(!layer);
        
        sc->addChild(layer);
    } while (0);
    return sc;
}
void PlanLayer::setupViews(){

    hero=CCSprite::createWithSpriteFrame(cache->spriteFrameByName("hero1.png"));
    hero->setContentSize(CCSize(50,55));
    hero->setPosition(ccp(win_size.width/2,win_size.height/2-100));
    this->addChild(hero,1);
    CCSpriteFrame* hero1=CCSpriteFrame::createWithTexture(pTexture2, CCRectMake(872, 73, 122, 100));
    CCSpriteFrame* hero2=CCSpriteFrame::createWithTexture(pTexture2, CCRectMake(370, 55, 122, 100));
    CCAnimation* animation=CCAnimation::create();
    animation->setDelayPerUnit(0.05f);
    animation->addSpriteFrame(hero1);
    animation->addSpriteFrame(hero2);
    CCAnimate* animate=CCAnimate::create(animation);
    hero->setScale(0.5f);
    hero->setRotation(-90);
    hero->runAction(CCRepeatForever::create(animate));
    
    CCLabelBMFont* score=CCLabelBMFont::create("00000", "font.fnt");
    score->setAnchorPoint(ccp(0,1));
    score->setScale(0.7f);
    score->setPosition(40,win_size.height-8);
    this->addChild(score,3,30);
    
    addEnmy();
    addBullets();
    
    scheduleUpdate();
    schedule(schedule_selector(PlanLayer::releaseBullets), 0.2f);
    schedule(schedule_selector(PlanLayer::enemyMove), 0.02f);
}
void PlanLayer::addEnmy(){
    
    for (int i=0; i<pEnemys->capacity() ; i++) {
        
        Enemy* enemyNode=enemy->createWithFile("shoot.plist", 1);
        pEnemys->addObject(enemyNode);
        addChild(enemyNode,1);
    }
}
void PlanLayer::addBullets(){

    for (int i=0; i<pBullets->capacity() ; i++) {
    
        Bullet* bulletNode=bullet->createWithFile("shoot.plist", 1);
        pBullets->addObject(bulletNode);
        bulletNode->setScale(0.7f);
        addChild(bulletNode,1);
    }
}
void PlanLayer::enemyMove(){

    if (!heroDie) {
        
        for (int i=0; i<pEnemys->capacity(); i++) {
            
            Enemy* enemy_loop=(Enemy*)pEnemys->objectAtIndex(i);
            if(!enemy_loop->getIsVisiable()){
                int randomPosx=CCRANDOM_0_1()*(win_size.width-enemy_loop->getContentSize().width)+enemy_loop->getContentSize().width/2;
                enemy_loop->setPosition(ccp(randomPosx,win_size.height));
                enemy_loop->setIsVisiable();
                break;
            }
        }
    }else{
        pEnemys->removeAllObjects();
    }
}
void PlanLayer::releaseBullets(){
    
    if (!heroDie) {
        
        for (int i=0; i<bullerCount; i++) {
            
            if(!((Bullet*)pBullets->objectAtIndex(i))->getIsVisiable()){
                ((Bullet*)pBullets->objectAtIndex(i))->setPosition(ccp(hero->getPosition().x,hero->getPosition().y+hero->getContentSize().height/2-10));
                ((Bullet*)pBullets->objectAtIndex(i))->setIsVisiable();
                SimpleAudioEngine::sharedEngine()->playEffect("bullet.mp3");
            }
        }
    }
}
bool PlanLayer::isCollision(cocos2d::CCPoint p1, int w1, int h1, cocos2d::CCPoint p2, int w2, int h2){
    
    if (abs(p1.x-p2.x)<(w1+w2)/2 && abs(p1.y-p2.y)<(h1+h2)/2) {
        return true;
    }
    return false;
}
void PlanLayer::update(float dt){

    if (CCUserDefault::sharedUserDefault()->getBoolForKey("isGamePause")) {
        this->setTouchEnabled(false);
    }else{
        this->setTouchEnabled(true);
    }
    if (hero->getPosition().x-hero->getContentSize().width/4<0 ){
        hero->setPositionX(hero->getContentSize().width/4);
    }
    if (hero->getPosition().x+hero->getContentSize().width/4>win_size.width ){
        hero->setPositionX(win_size.width-hero->getContentSize().width/4);
    }
    if (hero->getPosition().y-hero->getContentSize().height/4<0 ){
        hero->setPositionY(hero->getContentSize().height/4);
    }
    if (hero->getPosition().y+hero->getContentSize().height/4>win_size.height ){
        hero->setPositionY(win_size.height-hero->getContentSize().height/4);
    }
    
    if (!heroDie) {
     
        for (int j=0; j<pBullets->capacity(); j++) {
            
            Bullet* bullet_check=(Bullet*)pBullets->objectAtIndex(j);
            CCSize bullet_check_size = bullet_check->getContentSize();
            CCPoint bullet_pos=bullet_check->getPosition();
            
            for (int i=0; i<pEnemys->capacity(); i++) {
                enemy_check=(Enemy*)pEnemys->objectAtIndex(i);
                CCSize enemy_check_size = enemy_check->getContentSize();
                CCPoint enemy_pos=enemy_check->getPosition();
                
                CCSize hero_check_size = hero->getContentSize();
                CCPoint hero_pos=hero->getPosition();
                
                if (heroDie) {
                    enemy_check->setIsNotVisiable();
                }
                if(enemy_check->boundingBox().intersectsRect(hero->boundingBox())){
                    
                    CCLOG("hero and enemy");
                    heroDie=true;
                    bullet_check->setIsNotVisiable();
                    heroDie=true;
                    this->heroBomb();
                }
                if(bullet_check->boundingBox().intersectsRect(enemy_check->boundingBox())){

                    CCLOG("bullet and enemy");
                    SimpleAudioEngine::sharedEngine()->playEffect("bomb.mp3");
                    enemy_check->setIsNotVisiable();
                    changeScore();
                    bullet_check->setIsNotVisiable();
                }
            }
        }
    }
}
bool PlanLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){

    return true;
}
void PlanLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
    
    CCPoint touchPoint=pTouch->getLocation();
    hero->setPosition(ccp(touchPoint.x,touchPoint.y+20));
}
void PlanLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){
    
    CCPoint touchPoint=pTouch->getLocation();
    hero->setPosition(ccp(touchPoint.x,touchPoint.y+20));
}
void PlanLayer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent){

    CCPoint touchPoint=pTouch->getLocation();
    hero->setPosition(ccp(touchPoint.x,touchPoint.y+20));
}
void PlanLayer::changeScore(){

    score+=2;
    char string[5] = {0};
    
    if (score<99999) {
     
        sprintf(string, "%d", score);
        CCLabelBMFont *pScore = (CCLabelBMFont*) getChildByTag(30);
        pScore->setString(string);
    }
}
void PlanLayer::heroBomb(){

    CCSpriteFrame* hero1=CCSpriteFrame::createWithTexture(pTexture2, CCRectMake(746, 73, 98, 124));
    hero1->setRotated(-90);
    CCSpriteFrame* hero2=CCSpriteFrame::createWithTexture(pTexture2, CCRectMake(620, 64, 98, 124));
    hero2->setRotated(-90);
    CCSpriteFrame* hero3=CCSpriteFrame::createWithTexture(pTexture2, CCRectMake(494, 62, 98, 124));
    hero3->setRotated(-90);
    CCSpriteFrame* hero4=CCSpriteFrame::createWithTexture(pTexture2, CCRectMake(755, 2, 66, 78));
    hero4->setRotated(-90);
    
    
    CCArray* pArray=CCArray::create();
    pArray->addObject(hero1);
    pArray->addObject(hero2);
    pArray->addObject(hero3);
    pArray->addObject(hero4);
    CCAnimation* pAnimation=CCAnimation::createWithSpriteFrames(pArray,2.f);
    if (!pAnimation) {
        return ;
    }
    pAnimation->setDelayPerUnit(0.03f);
    pAnimation->setRestoreOriginalFrame(true);
    pAnimation->setLoops(1);
    CCFiniteTimeAction * pAnimate = CCAnimate::create(pAnimation);
    CCCallFunc* func=CCCallFunc::create(this, callfunc_selector(PlanLayer::gameOver));
    CCActionInterval* seq=CCSequence::create(pAnimate,func,NULL);
    hero->runAction(seq);

}
void PlanLayer::enemyBomb(){
    
    
    CCSpriteFrame* enemy1=CCSpriteFrame::createWithTexture(pTexture2, CCRectMake(2, 42, 69, 31));
    enemy1->setRotated(-90);
    CCSpriteFrame* enemy2=CCSpriteFrame::createWithTexture(pTexture2, CCRectMake(926, 2, 69, 93));
    enemy2->setRotated(-90);
    CCSpriteFrame* enemy3=CCSpriteFrame::createWithTexture(pTexture2, CCRectMake(273, 46, 69, 95));
    enemy3->setRotated(-90);
    CCSpriteFrame* enemy4=CCSpriteFrame::createWithTexture(pTexture2, CCRectMake(194, 43, 69, 77));
    enemy4->setRotated(-90);
    
    CCArray* pArray=CCArray::create();
    pArray->addObject(enemy1);
    pArray->addObject(enemy2);
    pArray->addObject(enemy3);
    pArray->addObject(enemy4);
    
    CCAnimation* pAnimation=CCAnimation::createWithSpriteFrames(pArray,0.5f);
    if (!pAnimation) {
        return ;
    }
    
    pAnimation->setDelayPerUnit(0.03f);
    pAnimation->setRestoreOriginalFrame(true);
    pAnimation->setLoops(1);
    CCFiniteTimeAction * pAnimate = CCAnimate::create(pAnimation);
    CCCallFunc* func=CCCallFunc::create(this, callfunc_selector(Enemy::setIsNotVisiable));
    CCActionInterval* seq=CCSequence::create(pAnimate,func,NULL);
    enemy_check->runAction(seq);
}
void PlanLayer::gameOver(){
    
    SimpleAudioEngine::sharedEngine()->playEffect("game_over.mp3");
    CCUserDefault::sharedUserDefault()->setIntegerForKey("LastGameScore", score);
    hero->setVisible(false);
    GameOverScene* gameover_layer=GameOverScene::create();
    gameover_layer->setColor(ccc3(255, 255, 255));
    gameover_layer->setOpacity(100);
    gameover_layer->ignoreAnchorPointForPosition(false);
    gameover_layer->setAnchorPoint(ccp(0.5,0.5));
    gameover_layer->setPosition(ccp(win_size.width/2,win_size.height/2));
    this->addChild(gameover_layer,5);
}