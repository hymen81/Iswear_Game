#include "LoadingScene.h"


LoadingScene::LoadingScene()
{
}


LoadingScene::~LoadingScene()
{
}
void LoadingScene::loadingsStep(float dt)
{
	static int progress = 0;
	std::string arrFile[] =
	{
		"up.png",
		"left.png",
		"right.png"
	};
	Vec2 arrPos[] =
	{
		Vec2(48 + 96, 48 + 96),
		Vec2(48, 48),
		Vec2(48 + 96 * 2, 48),
		Vec2(800, 48 + 96)
	};

	Weapon* weapon;
	Vec2 map1Pos;
	Vec2 treesPos;
	ParticleSystemQuad* mSystem;
	EventListenerTouchOneByOne *touchListener;

	switch (progress)
	{
	case 5:
		stage1 = Stage1::create();
		auto director = Director::getInstance();
		director->replaceScene(TransitionSlideInT::create(0.5f, stage1));
	
	}

	/*
	switch (progress)
	{
	case 0:
		stage1->map = MapLayer::create();
		stage1->bulletLayer = BulletLayer::create();
		stage1->main = (MainFly*)MainFly::myCreate("main.png");
		stage1->warrior = (Warrior*)Warrior::create("sprite_1.png");
		stage1->warrior->setName("Warrior");
		weapon = (Weapon*)Weapon::create("weapon1.png");
		stage1->warrior->setWeapon(weapon);
		stage1->addChild(stage1->map, 2);
		stage1->addChild(stage1->bulletLayer, 1);
		stage1->map->addChild(weapon, 5);
		stage1->map->addChild(stage1->warrior, 5);
		stage1->addChild(stage1->main, 10);

		break;
	case 1:
		for (int i = 0; i < 4; i++){
			auto arr = Input::create("arr.png", Rect(i * 96, 0, 96, 96));
			arr->setTag(i);
			arr->setPosition(arrPos[i]);
			arr->setControllee(stage1->warrior);
			//inputs.push_back(arr);
			stage1->addChild(arr, 20);
		}
		stage1->warrior->setPosition(Vec2(oriX, oriY));
		//warrior->setWorldPosition(Vec2(oriX, oriY));
		//warrior->setEffect(_effect, "warrior_n.png");

		for (int i = 2; i < 10 + 21; i++)
		{
			auto skull = Skull::myCreate("skull1.png");
			skull->setPosition(Vec2(oriX*(i), oriY));
			skull->setName("skull");
			//skull->setEffect(_effect, "warrior_n.png");

			stage1->map->addChild(skull, 5);

		}
		stage1->mainPos = Vec2(100, 100);
		stage1->main->setPosition(stage1->mainPos);
		break;

		// ...

	case 2:
		stage1->map1 = Sprite::create("pixel_art_landscape_by_mockingjay1701-d8omc3c.png");
		map1Pos = Vec2(0 + stage1->map1->getContentSize().width / 2, 0 + stage1->map1->getContentSize().height / 10);
		stage1->map1->setPosition(map1Pos);
		stage1->addChild(stage1->map1, 0);

		stage1->trees = Sprite::create("trees.png");
		treesPos = Vec2(0 + stage1->trees->getContentSize().width / 2, 0 + stage1->trees->getContentSize().height - 200);
		stage1->trees->setPosition(treesPos);
		stage1->addChild(stage1->trees, 1);

		mSystem = ParticleSystemQuad::create("test.plist");
		mSystem->setTextureWithRect(TextureCache::sharedTextureCache()->addImage("8.png"), Rect(0, 0, 64, 64));
		mSystem->setBlendAdditive(true);
		mSystem->setPosition(ccp(0, 540));
		stage1->addChild(mSystem, 50);


		break;

	case 3:

		CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("bgm/01.mp3");
		CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.1f);
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm/01.mp3", true);
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("SE/se_maoudamashii_battle17.mp3");
		break;

	case 4:
		touchListener = EventListenerTouchOneByOne::create();
		touchListener->onTouchBegan = CC_CALLBACK_2(Stage1::onTouchBegan, stage1);
		touchListener->onTouchEnded = CC_CALLBACK_2(Stage1::onTouchEnded, stage1);
		touchListener->onTouchMoved = CC_CALLBACK_2(Stage1::onTouchMoved, stage1);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
		break;

	case 5:
		stage1->warrior->scheduleUpdate();
		stage1->map->scheduleUpdate();
		stage1->scheduleUpdate();

		this->unschedule(schedule_selector(LoadingScene::loadingsStep));
		this->removeChildByName("loadingAnimation");


	}*/

	progress++;
}

bool LoadingScene::init()
{
	auto loadingAmimation = Sprite::create("loadingAnimation.png", Rect(0, 0, 256, 256));
	Vector<SpriteFrame*> animFrames(4);
	for (int i = 1; i < 4; i++)
	{
		auto frame = SpriteFrame::create("loadingAnimation.png", Rect(256 * i, 0, 256, 256));
		animFrames.pushBack(frame);
	}
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);

	//loadingAmimation->stopAllActions();
	loadingAmimation->runAction(animate);
	loadingAmimation->setPosition(Vec2(960 / 2, 540 / 2));
	loadingAmimation->setName("loadingAnimation");
	this->addChild(loadingAmimation, 60);

	auto loadingBack = Sprite::create();
	loadingBack->setColor(Color3B(255, 255, 255));
	this->addChild(loadingBack, 69);

	
	this->schedule(schedule_selector(LoadingScene::loadingsStep), 1.0f);


	return true;
}