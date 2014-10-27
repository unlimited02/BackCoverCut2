#include "GameScene.h"
#include "DescriptionScene.h"

#define WINSIZE Director::getInstance()->getWinSize()

Description::Description()
{
}

Description::~Description()
{
    log("解放:Description");
    this->removeAllChildren();
}

Scene *Description::createScene()
{
    Scene *scene = Scene::create();
    Layer *layer = Description::create();
    scene->addChild(layer);
    
    return scene;
}

bool Description::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    // 画像の配置
    setSprite();
    
    // タッチイベント
    EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(Description::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(Description::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

// 画像の配置
void Description::setSprite()
{
    log("画像配置");
    
    Sprite *sample1 = Sprite::create("sample.png");
    
    sample1->setPosition(Vec2(WINSIZE.width/2, WINSIZE.height/2));
    
    sample1->setScale(1.4);
    
    this->addChild(sample1, Z_Sprite, T_Sprite1);
}

// タッチアクション
bool Description::onTouchBegan(Touch *touch, Event *unused_event)
{
    log("タッチ開始");

    return true;
}

void Description::onTouchEnded(Touch *touch, Event *unused_event)
{
    gameStart();
    log("タッチ終了");
}

// 画面遷移
void Description::gameStart()
{
    log("遷移:SpriteSetSccene");
    Scene *scene = Game::createScene();
    TransitionScene *effect = TransitionPageTurn::create(0.5, scene, 0);
    Director::getInstance()->replaceScene(effect);
}
