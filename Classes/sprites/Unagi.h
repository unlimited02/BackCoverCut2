//
//  Unagi.h
//  BackCoverCut
//
//  Created by unlimited on 2014/10/26.
//
//

#ifndef __BackCoverCut__Unagi__
#define __BackCoverCut__Unagi__

#include "cocos2d.h"

USING_NS_CC;

class UnagiSprite : public cocos2d::Sprite
{
private:
public:
    UnagiSprite();
    ~UnagiSprite();
    
    virtual bool init();
    void setSprite();
    
    CREATE_FUNC(UnagiSprite);
};

#endif /* defined(__BackCoverCut__Unagi__) */
