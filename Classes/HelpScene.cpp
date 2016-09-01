#include "HelpScene.h"
#include "Definitions.h"
USING_NS_CC;

Scene* Tutorial::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Tutorial::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Tutorial::init()                          //initialize the game
{
    visibleSize = Director::getInstance()->getVisibleSize();          //Calculating standard values in this set
    origin = Director::getInstance()->getVisibleOrigin();
    screenCentreX = origin.x + visibleSize.width/2;
    screenCentreY = origin.y + visibleSize.height/2;
    screenEndX = origin.x + visibleSize.width;
    screenEndY = origin.y + visibleSize.height;

    
    if( !LayerColor::initWithColor(Color4B::BLACK))
    {
        return false;
    }
    
    showTutorial();
    return true;
 }

Label* Tutorial::makeLabel(const std::string text,const std::string font, int fontSize,bool isVisible)
{
    Label *label = Label::createWithTTF(text, font, fontSize);
    label->setAnchorPoint(Vec2(0.5f,0.5f));
    label->setColor(Color3B::WHITE);
    label->setPosition(Vec2(screenCentreX,screenCentreY));
    label->setAlignment(TextHAlignment::CENTER);
    label->setDimensions(visibleSize.width*0.75, 0);
    label->setOpacityModifyRGB(true);
    if(!isVisible)
        label->setOpacity(0.0f);
    return label;

}

Sprite* Tutorial::makeSprite(const std::string resourceLocation, bool isVisible)
{
    Sprite *sprite = Sprite::create(resourceLocation);
    sprite->setPosition(Vec2(screenCentreX,screenCentreY));
    sprite->setScale(visibleSize.width / sprite->getContentSize().width,visibleSize.width / sprite->getContentSize().width);
    if(!isVisible)
        sprite->setOpacity(0.0);
    return sprite;
}

void Tutorial::showTutorial()
{
    Label *introText = makeLabel("In the game a number of colored circles will be generated. The bounding box around the screen will also be changing color", "fonts/Zygoth.ttf", 4,false);
    
    this->addChild(introText);
    //introText->runAction(cocos2d::FadeTo::create(4.0f, 0.0));
    
    Sprite *gameArea = makeSprite("res/GameArea.png",false);
    this->addChild(gameArea);
   
    Label *basicScoringCriteria1 = makeLabel("Touching a circle of tha same color as the bounding box will fetch you points", "fonts/Zygoth.ttf", 4,false);
    this->addChild(basicScoringCriteria1);
    
    auto basicScoringCriteriaImage1 = makeSprite("res/ScoringCriteriaInstruction1.png", false);
    this->addChild(basicScoringCriteriaImage1);
    
    Label *basicScoringCriteria2 = makeLabel("Touch a different colored circle and you lose","fonts/Zygoth.ttf", 4,false);
    this->addChild(basicScoringCriteria2);
    
    auto basicScoringCriteriaImage2 = makeSprite("res/ScoringCriteriaInstruction2.png", false);
    this->addChild(basicScoringCriteriaImage2);
    
    Label *basicScoringCriteria3 = makeLabel("When a circle reflects from a boundary it becomes more translucent and finally disappears. Greater the translucensy, greater the score it will fetch if it is the correct color.","fonts/Zygoth.ttf", 4,false);
    this->addChild(basicScoringCriteria3);
    
    auto basicScoringCriteriaImage3 = makeSprite("res/ScoringCriteriaInstruction3.png", false);
    this->addChild(basicScoringCriteriaImage3);
    
    
   // gameArea->runAction(FadeIn::create(4.0f));
    auto introTextAction1 = TargetedAction::create(introText,FadeIn::create(TUTORIAL_TRANSITION_TIME));
    auto introTextAction2 = TargetedAction::create(introText,FadeOut::create(TUTORIAL_TRANSITION_TIME));
    auto gameAreaAction1 =TargetedAction::create(gameArea,FadeIn::create(TUTORIAL_TRANSITION_TIME));
    auto gameAreaAction2 =TargetedAction::create(gameArea,FadeOut::create(TUTORIAL_TRANSITION_TIME));
    auto basicScoringCriteria1Action1 = TargetedAction::create(basicScoringCriteria1, FadeIn::create(TUTORIAL_TRANSITION_TIME));
    auto basicScoringCriteria1Action2 = TargetedAction::create(basicScoringCriteria1, FadeOut::create(TUTORIAL_TRANSITION_TIME));
    auto basicScoringCriteriaImage1Action1 = TargetedAction::create(basicScoringCriteriaImage1, FadeIn::create(TUTORIAL_TRANSITION_TIME));
    auto basicScoringCriteriaImage1Action2 = TargetedAction::create(basicScoringCriteriaImage1, FadeOut::create(TUTORIAL_TRANSITION_TIME));
    auto basicScoringCriteria2Action1 = TargetedAction::create(basicScoringCriteria2, FadeIn::create(TUTORIAL_TRANSITION_TIME));
    auto basicScoringCriteria2Action2 = TargetedAction::create(basicScoringCriteria2, FadeOut::create(TUTORIAL_TRANSITION_TIME));
    auto basicScoringCriteriaImage2Action1 = TargetedAction::create(basicScoringCriteriaImage2, FadeIn::create(TUTORIAL_TRANSITION_TIME));
    auto basicScoringCriteriaImage2Action2 = TargetedAction::create(basicScoringCriteriaImage2, FadeOut::create(TUTORIAL_TRANSITION_TIME));
    auto basicScoringCriteria3Action1 = TargetedAction::create(basicScoringCriteria3, FadeIn::create(TUTORIAL_TRANSITION_TIME));
    auto basicScoringCriteria3Action2 = TargetedAction::create(basicScoringCriteria3, FadeOut::create(TUTORIAL_TRANSITION_TIME));
    auto basicScoringCriteriaImage3Action1 = TargetedAction::create(basicScoringCriteriaImage3, FadeIn::create(TUTORIAL_TRANSITION_TIME));
    auto basicScoringCriteriaImage3Action2 = TargetedAction::create(basicScoringCriteriaImage3, FadeOut::create(TUTORIAL_TRANSITION_TIME));

    auto endTutorial = CallFunc::create([](){
        Director::getInstance()->popScene();
    });
    this->runAction(Sequence::create(introTextAction1,introTextAction2
                                     ,gameAreaAction1,gameAreaAction2
                                     ,basicScoringCriteria1Action1,basicScoringCriteria1Action2
                                     ,basicScoringCriteriaImage1Action1,basicScoringCriteriaImage1Action2
                                     ,basicScoringCriteria2Action1,basicScoringCriteria2Action2
                                     ,basicScoringCriteriaImage2Action1,basicScoringCriteriaImage2Action2
                                     ,basicScoringCriteria3Action1,basicScoringCriteria3Action2
                                     ,basicScoringCriteriaImage3Action1,basicScoringCriteriaImage3Action2
                                     ,endTutorial
                                     ,nullptr));
   // this->setOpacity(0);
    

}



