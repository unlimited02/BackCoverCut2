#include "Kabu.h"
#include "Macros.h"


KabuSprite::KabuSprite()
{
}

KabuSprite::~KabuSprite()
{
    this->removeAllChildren();
    log("解放:KabuSprite");
}

bool KabuSprite::init()
{
    if (!Sprite::initWithFile("kabu.png"))
    {
        return false;
    }
    
    setSprite();
    
    return true;
}

void KabuSprite::setSprite()
{
    this->setPosition(Vec2(WINSIZE.width/2, WINSIZE.height/2));
    
    float setLine = 2.2;
    
    UserDefault *userDef = UserDefault::getInstance();
    userDef->setFloatForKey("SetLine", setLine);
    userDef->flush();
}
