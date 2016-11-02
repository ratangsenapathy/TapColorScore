#ifndef __HELP_SCENE_H__
#define __HELP_SCENE_H__

#include "cocos2d.h"
#include "Definitions.h"


class Tutorial : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Label* introText;
    cocos2d::Sprite* gameArea;
    int screenCentreX;
    int screenCentreY;
    int screenEndX;
    int screenEndY;
    int increaseVisiblityCallNo;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(Tutorial);
    virtual bool init();
    void showTutorial();
    void decreaseVisibility(float dt);
    void displayGameArea(float dt);
    void increaseVisibility(float dt);
    cocos2d::Label* makeLabel(const std::string text,const std::string font,int fontSize, bool isVisible);
    cocos2d::Sprite* makeSprite(const std::string resourceLocation,bool isVisible);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
    
};

#endif // __HELLOWORLD_SCENE_H__
