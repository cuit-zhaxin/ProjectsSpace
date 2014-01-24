#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Texture2D::setDefaultAlphaPixelFormat(Texture2D::PixelFormat::RGBA4444);
    Texture2D *texture2D = Director::getInstance()->getTextureCache()->addImage("sprites-hd.pvr.ccz");
    auto spBatchNode = SpriteBatchNode::createWithTexture(texture2D);
    addChild(spBatchNode);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites-hd.pvr.plist");
    
    std::vector<std::string> arrSpFrameName = {"bear_2x2.png","bird.png","cat.png","dog.png","ooze_2x2.png","turtle.png"};
    
    for(int i = 0;i< arrSpFrameName.size();i++){
    
        std::string spFrameName = arrSpFrameName.at(i);
        auto sp = Sprite::createWithSpriteFrameName(spFrameName);
        float offsetFaction = ((float)(i+1)/(arrSpFrameName.size()+1));
        Point spriteOffset = Point(visibleSize.width*offsetFaction,visibleSize.height/2);
        sp->setPosition(spriteOffset);
        addChild(sp);
    }
    
    Texture2D::setDefaultAlphaPixelFormat(Texture2D::PixelFormat::DEFAULT);
    return true;
}
