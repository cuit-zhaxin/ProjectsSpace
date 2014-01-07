//
//  GameSprite.cpp
//  ShootGame
//
//  Created by zhaxin on 13-12-4.
//
//

#include "GameSprite.h"

GameSprite::GameSprite(){

    pTexture2=CCTextureCache::sharedTextureCache()->addImage("shoot.png");
}

GameSprite::~GameSprite(){
}

