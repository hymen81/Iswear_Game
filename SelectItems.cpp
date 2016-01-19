#include "SelectItems.h"

typedef struct itemRes
{
	std::string nor;
	std::string sel;
	std::string text;
}res;

res r[5] = { { "start1.png", "start2.png", "Start" },
{ "CloseNormal.png", "CloseSelected.png", "Start2" },
{ "CloseNormal.png", "CloseSelected.png", "Start3" },
{ "CloseNormal.png", "CloseSelected.png", "Start4" },
{ "CloseNormal.png", "CloseSelected.png", "Start4" }
};

Sprite * sky;

SelectItems::SelectItems()
{
	
}

SelectItems::~SelectItems()
{
}



MenuItemImage* SelectItems::createItem(std::string nor, std::string sel, std::string text)
{
	auto Item = MenuItemImage::create(
		nor,
		sel,
		CC_CALLBACK_1(SelectItems::menuCloseCallback, this));
	auto label = Label::createWithTTF(text, "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2::ZERO);
	//Item->addChild(label);
	return Item;
}



bool SelectItems::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->setTouchEnabled(true);

	Vector<MenuItem*> menuItems;
	
	for (int i = 0; i < 5; i++)
	{
		auto menuItem = createItem(r[i].nor, r[i].sel, r[i].text);
		menuItem->setPosition(Vec2(400,-i*50 + 500));
		menuItem->setTag(i);
		menuItems.pushBack(menuItem);
	}


	sky = Sprite::create("sky_night.png");
	Size spriteSize = sky->getContentSize();
	float scaleX = visibleSize.width / spriteSize.width;
	float scaleY = visibleSize.height / spriteSize.height;
	sky->setScale(scaleX, scaleY);
	sky->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(sky, 0);

	/*auto Item = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(SelectItems::menuCloseCallback, this));
	auto label = Label::createWithTTF("dasdasd", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2::ZERO);
	Item->addChild(label);


	Item->setPosition(Vec2(200,
		500));
	menuItems.pushBack(Item);*/
	

	Menu* pMenu = Menu::createWithArray(menuItems);

	pMenu->setPosition(Vec2(0,-100));

	this->addChild(pMenu, 1);
	
	/*auto items = Menu::createWithArray(menuItems);
	items->setPosition();
	

	this->addChild(items, 1);*/

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	

	// position the label on the center of the screen
	//label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		//origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	//this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	

	bird = Sprite::create("bird0_0.png");
	auto array = PointArray::create(20);

	array->addControlPoint(Vec2(0, 0));
	array->addControlPoint(Vec2(80, 80));
	array->addControlPoint(Vec2(visibleSize.width - 80, 80));
	array->addControlPoint(Vec2(visibleSize.width - 80, visibleSize.height - 80));
	array->addControlPoint(Vec2(80, visibleSize.height - 80));
	array->addControlPoint(Vec2(80, 80));
	array->addControlPoint(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	auto action = CatmullRomBy::create(3, array);
	auto reverse = action->reverse();

	auto seq = Sequence::create(action, reverse, nullptr);

	//bird->runAction(seq);
	auto drawNode1 = DrawNode::create();
	drawNode1->setPosition(Vec2(50, 50));
	drawNode1->drawCatmullRom(array, 50, Color4F(1.0, 0.0, 1.0, 1.0));
	//this->addChild(drawNode1);
	

	/*auto animation = Animation::create();
	for (int i = 1; i<=4; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "em%d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}
	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(0.3f/ 3.0f);
	//animation->setRestoreOriginalFrame(true);
	
	 action2 = Animate::create(animation);
	

	bird->setPosition(Vec2(200,400));
	bird->runAction(Sequence::create(action2, action2->reverse(), NULL));

	this->addChild(bird, 1);*/

	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(SelectItems::onTouchBegan, this);
	
	

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	this->scheduleUpdate();
	
	return true;
}

void SelectItems::update(float deta)
{
	//sky->setPositionX(sky->getPositionX() - 0.01f);
}

bool SelectItems::onTouchBegan(Touch* touch, Event* event)
{
	/*auto animation = Animation::create();
	for (int i = 1; i<=4; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "em%d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}
	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(0.3f / 3.0f);
	//animation->setRestoreOriginalFrame(true);

	action2 = Animate::create(animation);
	bird->runAction(Sequence::create(action2, action2->reverse(), NULL));*/
	log("onTouchBegan");
	return true;
}



void SelectItems::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	MenuItem* pMenuItem = (MenuItem *)(pSender);
	int tag = (int)pMenuItem->getTag();
	log("%d", tag);
	auto director = Director::getInstance();
	auto scene = Stage1::create();


	auto animation = Animation::create();

	switch (tag)
	{
	case 0:
		director->replaceScene(TransitionCrossFade::create(0.1f, scene));
		//
		break;
		// replace scene with GameScene
	case 1:
		
		break;
	case 2:
		// replace scene with OptionsScene
		break;
	case 3:
		// replace scene with OptionsScene
		break;
	case 4:
		// replace scene with OptionsScene
		Director::getInstance()->end(); 
		break;

	default:
		break;
		// log error w/tag
	}


	

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}