#define WINSIZE Director::getInstance()->getWinSize()

#include "Unagi.h"

UnagiSprite::UnagiSprite()
{
}

UnagiSprite::~UnagiSprite()
{
}

bool UnagiSprite::init()
{
    if (!Sprite::initWithFile("unagi.png"))
    {
        return false;
    }
    
    setSprite();
    
    return true;
}

void UnagiSprite::setSprite()
{
    Size visibleSize = WINSIZE;
    
    this->setPosition(Vec2(WINSIZE.width/2, WINSIZE.height/2));
    
    float setLine = 3.0;
    
    UserDefault *userDef = UserDefault::getInstance();
    userDef->setFloatForKey("SetLine", setLine);
    userDef->flush();
}