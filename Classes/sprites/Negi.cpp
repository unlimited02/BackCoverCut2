#include "Negi.h"
#include "Macros.h"

NegiSprite::NegiSprite()
{
}

NegiSprite::~NegiSprite()
{
    this->removeAllChildren();
    log("解放:NegiSprite");
}

bool NegiSprite::init()
{
    if (!Sprite::initWithFile("negi.png"))
    {
        return false;
    }
    
    setSprite();
    
    return true;
}

void NegiSprite::setSprite()
{
    this->setPosition(Vec2(WINSIZE.width/2, WINSIZE.height/2));
    
    float setLine = 3.0;
    
    UserDefault *userDef = UserDefault::getInstance();
    userDef->setFloatForKey("SetLine", setLine);
    userDef->flush();
}
