#include "TitleScene.h"
#include "GameScene.h"
#include "SpriteSetScene.h"
#include "DescriptionScene.h"
#include "Macros.h"

Title::Title()
{
}

Title::~Title()
{
    this->removeAllChildren();
    log("解放:Title");
}

// タイトルシーンの作成
Scene *Title::createScene()
{
    Scene *scene = Scene::create();
    Layer *layer = Title::create();
    scene->addChild(layer);
    
    return scene;
}

bool Title::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    // 背景画像の配置
    setBackGround();
    
    // ボタンの配置
    setButton();
    
    return true;
}

void Title::setBackGround()
{
    // 背景画像の配置
    Sprite *bg = Sprite::create("titleBg.png");
    Size bgSize = bg->getContentSize();
    float sizeWidth = WINSIZE.width / bgSize.width;
    float sizeHeight = WINSIZE.height / bgSize.height;
    bg->setPosition(Vec2(WINSIZE.width/2, WINSIZE.height/2));
    bg->setScaleX(sizeWidth);
    bg->setScaleY(sizeHeight);
    this->addChild(bg, Z_Bg);

    log("背景配置");
}

// ボタン配置
void Title::setButton()
{
    // 開始ボタンの配置
    MenuItem *startItem = MenuItemImage::create("startbtn_result.png", "startbtn_push.png", CC_CALLBACK_0(Title::menuStart, this));
    startItem->setPosition(Vec2(WINSIZE.width/2, WINSIZE.height/3));
    
    Menu *menu1 = Menu::create(startItem, NULL);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1, Z_Button);
    
    Label *startLabel = Label::createWithSystemFont("スタート!", "ArialRoundedMTBold", 30);
    startLabel->setPosition(startItem->getPosition());
    startLabel->setScale(1.2);
    this->addChild(startLabel, Z_Label);
    
    // 終了ボタンの配置
    MenuItem *closeItem = MenuItemImage::create("endbtn_result.png", "endbtn_push.png", CC_CALLBACK_1(Title::menuEnd, this));
    closeItem->setPosition(Vec2(WINSIZE.width/2, WINSIZE.height/3 - WINSIZE.height/10 - WINSIZE.height/10));
    
    Menu *menu2 = Menu::create(closeItem, NULL);
    menu2->setPosition(Vec2::ZERO);
    this->addChild(menu2, Z_Button);
    
    Label *endLabel = Label::createWithSystemFont("ゲーム終了", "ArialRoundedMTBold", 30);
    endLabel->setPosition(closeItem->getPosition());
    endLabel->setScale(1.2);
    this->addChild(endLabel, Z_Label);
    
    // 画像変更ボタンの配置
    MenuItem *configItem = MenuItemImage::create("reStartbtn_result.png", "reStartbtn_push.png", CC_CALLBACK_0(Title::menuConfig, this));
    configItem->setPosition(Vec2(WINSIZE.width/2, WINSIZE.height/3 - WINSIZE.height/10));
    
    Menu *menu3 = Menu::create(configItem, NULL);
    menu3->setPosition(Vec2::ZERO);
    this->addChild(menu3, Z_Button);
    
    Label *configLabel = Label::createWithSystemFont("設定", "ArialRoundedMTBold", 30);
    configLabel->setPosition(configItem->getPosition());
    configLabel->setScale(1.2);
    this->addChild(configLabel, Z_Label);
    log("ボタン配置");
}

// ゲームへの画面遷移
void Title::menuStart()
{
    Scene *scene = Description::createScene();
    TransitionScene *effect = TransitionPageTurn::create(0.5, scene, 0);
    Director::getInstance()->replaceScene(effect);
    log("遷移:GameScene");
}

// アプリ終了
void Title::menuEnd(Ref *pSender)
{
    Director::getInstance()->end();
    exit(0);
    log("終了");
}

// 設定画面への画面遷移
void Title::menuConfig()
{
    Scene *scene = SetSprite::createScene();
    TransitionScene *effect = TransitionCrossFade::create(0.5, scene);
    Director::getInstance()->replaceScene(effect);
    log("遷移:SpriteSetSccene");
}
