#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Definitions.h"
#include "PluginAdColony/PluginAdColony.h"
#include "PluginFacebook/PluginFacebook.h"
#include "PluginReview/PluginReview.h"
#include "PluginShare/PluginShare.h"
#include "PluginAdMob/PluginAdMob.h"
#include "SimpleAudioEngine.h"

class GameWorld : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();
    float shapeDirections[DIRECTION_COUNT][2] = {SHAPE_DIRECTIONS};
    float obstacleTime;
    float generationTime;
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Node* currentShapePoint;
    cocos2d::Label* score = NULL;
    cocos2d::Menu* mainMenu = NULL;
    cocos2d::Label* titlePart = NULL;
    cocos2d::Label* bestScore = NULL;
    cocos2d::MenuItemToggle* soundButton = NULL;
    cocos2d::MenuItemToggle* musicButton = NULL;
    cocos2d::MenuItemToggle* ratingsButton = NULL;
    cocos2d::MenuItemToggle* facebookButton = NULL;
    cocos2d::MenuItemToggle* twitterButton = NULL;
    cocos2d::MenuItemToggle* helpButton = NULL;
   // cocos2d::MenuItemImage* soundOn;
   // cocos2d::MenuItemImage* soundOff;
    cocos2d::MenuItemImage* playButton = NULL;
    int scoreValue;
    int screenCentreX;
    int screenCentreY;
    int screenEndX;
    int screenEndY;
    bool isMainMenuScreen;
    struct WallInfo
    {
        int wallType;
        cocos2d::Vec2 positionOnWall;
    };
    
    struct Shape
    {
        Node* rotationPoint;
       // cocos2d::DrawNode* shape;
        cocos2d::Color4F color;
        std::string colorName;
        int shapeType;
        cocos2d::Vec2 initPosition;
        struct WallInfo wall;
        
    };
   // std::vector<Shape> shapeList;
    std::map<Node*,Shape> shapeList;
    virtual bool init();
    void loadGame();
    void onPlayButtonClick(cocos2d::Ref* ref);
    void onSoundButtonClick(cocos2d::Ref* ref);
    void onMusicButtonClick(cocos2d::Ref *ref);
    void onRatingsButtonClick(cocos2d::Ref *ref);
    void onFacebookButtonClick(cocos2d::Ref *ref);
    void onTwitterButtonClick(cocos2d::Ref *ref);
    void onHelpButtonClick(cocos2d::Ref *ref);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void genrateShapes();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameWorld);
    cocos2d::DrawNode* getShape();
    void shapeGenerator(float dt);
    void currentShapeChooser(float dt);
    void update(float dt);
    WallInfo getInitialEndLocation();
    void wallHit(cocos2d::Node *point,Shape &shape);
    cocos2d::Vec2 getTopWallCoords(float x1,float y1,float slope);
    cocos2d::Vec2 getBottomWallCoords(float x1,float y1,float slope);
    cocos2d::Vec2 getLeftWallCoords(float x1,float y1,float slope);
    cocos2d::Vec2 getRightWallCoords(float x1,float y1,float slope);
    bool isPointOnTopWall(cocos2d::Vec2 point);
    bool isPointOnBottomWall(cocos2d::Vec2 point);
    bool isPointOnLeftWall(cocos2d::Vec2 point);
    bool isPointOnRightWall(cocos2d::Vec2 point);
    float calculateDistance(cocos2d::Vec2 point1,cocos2d::Vec2 point2);
    float calculateUnitTimeFromDistance(float distance);
    bool onTouchBegan(cocos2d::Touch *touch,cocos2d::Event *event);
    cocos2d::Color3B getRandomColor();
    void releaseResources();
    void loadMainMenu();
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
    cocos2d::MenuItemToggle* addToggleButton(std::string buttonName,cocos2d::MenuItemToggle * toggleButton,bool status,cocos2d::Vec2 position,const cocos2d::ccMenuCallback &callback);
    
};

#endif // __HELLOWORLD_SCENE_H__
