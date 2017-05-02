#include "GraphicsScene.h"

USING_NS_CC;

Scene* GraphicsScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GraphicsScene::create();
    scene->addChild(layer);
    return scene;
}

bool GraphicsScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    /*
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(0, 0);
   
    this->addChild(sprite, 0);
    */

    auto s = Director::getInstance()->getWinSize();
    auto draw = DrawNode::create();
    this->addChild(draw, 10); //what's the 10??

    //draw->drawTriangle(Vec2(10,10), Vec2(70,30), Vec2(100,140))
    Vec2 verts[] = {Vec2(10,10), Vec2(10,30), Vec2(100,140)};
    int count = 3;
    Color4F fillColor = Color4F(CCRANDOM_0_1(), CCRANDOM_0_1(), CCRANDOM_0_1(), 1);
    int borderWidth = 4;
    Color4F borderColor = Color4F(CCRANDOM_0_1(), CCRANDOM_0_1(), CCRANDOM_0_1(), 1);


    draw->drawPolygon(verts, count, fillColor, borderWidth, borderColor);

    return true;
}


Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if (!Layer::init())
    {
        return false;
    }

    sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
    this->addChild(sprite, 0);

    this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta) {
    auto position = sprite->getPosition();
    position.x -= 250 * delta;
    if (position.x < 0 - (sprite->getBoundingBox().size.width / 2))
        position.x = this->getBoundingBox().getMaxX() + sprite->getBoundingBox().size.width/2;
    sprite->setPosition(position);
}