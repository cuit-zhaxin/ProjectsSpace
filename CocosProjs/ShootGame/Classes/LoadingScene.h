//
//  LoadingScene.h
//  ShootGame
//
//  Created by zhaxin on 13-12-4.
//
//

#ifndef __ShootGame__LoadingScene__
#define __ShootGame__LoadingScene__

#include <iostream>
#include "ParentClass.h"

class LoadScene:public ParentClass {
public:
    LoadScene();
    ~LoadScene();
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(LoadScene);
    
    void setupViews();
    void replaceScene();
};

#endif /* defined(__ShootGame__LoadingScene__) */
