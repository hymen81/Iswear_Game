#include "Stage1.h"


Stage1::Stage1()
{
	int a = 0;
	isTouchEnd = true;
}


Stage1::~Stage1()
{
}


std::vector<Input*> inputs;


//test
float oriX = 400;
float oriY = GROUND * 10;
LightEffect* _effect;


void Stage1::loadingsStep(float dt)
{
	static int progress = 0;

	//工廠模式
	FactoryInterface *factory;
	//FactoryInterface *enemyFactory = new EnemyFactory();

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
	case p10:
		map = MapLayer::create();
		bulletLayer = BulletLayer::create();
		main = (MainFly*)MainFly::myCreate("main.png");

		//利用工廠生產主角
		factory = new WarriorFactory();
		warrior = (Warrior*)factory->ctrateObject();

		warrior->setName("Warrior");
		weapon = (Weapon*)Weapon::create("weapon1.png");
		warrior->setWeapon(weapon);
		this->addChild(map, 2);
		this->addChild(bulletLayer, 1);
		map->addChild(weapon, 5);
		map->addChild(warrior, 5);
		this->addChild(main, 10);

		
		//map->setPosition(Vec2(map->getPositionX()-960/2, map->getPositionY()-540/2));

		break;
	case p20:
		for (int i = 0; i < 4; i++){
			
			auto arr = Input::create("arr.png", Rect(i * 96, 0, 96, 96));
			arr->setTag(i);
			arr->setPosition(arrPos[i]);
			arr->setControllee(warrior);
			inputs.push_back(arr);
			this->addChild(arr, 20);
		}
		warrior->setPosition(Vec2(oriX, oriY+200));
		//warrior->setWorldPosition(Vec2(oriX, oriY));
		//warrior->setEffect(_effect, "warrior_n.png");

		for (int i = 2; i < 10+21; i++)
		{
			factory = new EnemyFactory();
			auto skull = factory->ctrateObject();
			skull->setPosition(Vec2(oriX*(i), oriY+400));
			skull->setName("skull");
			//skull->setEffect(_effect, "warrior_n.png");
		
			map->addChild(skull, 5);

		}
		mainPos = Vec2(100, 100);
		main->setPosition(mainPos);
		break;

		// ...

	case p30:
		map1 = Sprite::create("stage1Back.png");
		map1Pos = Vec2(0 + map1->getContentSize().width / 2, 0 + map1->getContentSize().height / 10);
		map1->setPosition(map1Pos);
		this->addChild(map1, 0);

		trees = Sprite::create("trees.png");
		treesPos = Vec2(0 + trees->getContentSize().width / 2, 0 + trees->getContentSize().height - 200);
		trees->setPosition(treesPos);
		this->addChild(trees, 1);

		mSystem = ParticleSystemQuad::create("test.plist");
		mSystem->setTextureWithRect(TextureCache::sharedTextureCache()->addImage("8.png"), Rect(0, 0, 64, 64));
		mSystem->setBlendAdditive(true);
		mSystem->setPosition(ccp(0, 540));
		this->addChild(mSystem, 50);
		
		
		break;

	case p40:
		
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("bgm/01.mp3");
		CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.1f);
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm/01.mp3", true);
		//CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("SE/se_maoudamashii_battle17.mp3");
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("SE/se_maoudamashii_se_fall02.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("SE/se_maoudamashii_battle17.mp3");
		
		break;

	case p50:
		touchListener = EventListenerTouchOneByOne::create();
		touchListener->onTouchBegan = CC_CALLBACK_2(Stage1::onTouchBegan, this);
		touchListener->onTouchEnded = CC_CALLBACK_2(Stage1::onTouchEnded, this);
		touchListener->onTouchMoved = CC_CALLBACK_2(Stage1::onTouchMoved, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
		break;

	case p60:
		warrior->scheduleUpdate();
		map->scheduleUpdate();
		this->scheduleUpdate();

		this->unschedule(schedule_selector(Stage1::loadingsStep));
		this->removeChildByName("loadingAnimation");


		auto label = Label::createWithTTF("Loading OK!", "TTF/pixelart.ttf", 24);
		label->setPosition(warrior->getPosition());
		this->addChild(label);

		break;


	}

	progress++;

}


bool Stage1::init()
{
	/*_effect = LightEffect::create();
	_effect->retain();
	Vec3 lightPos(200, 200, 100);
	_effect->setLightPos(lightPos);
	_effect->setLightCutoffRadius(5000);
	_effect->setBrightness(2.0);*/

	//map->setEffect(_effect, "title_n.png");
	//map->initTileMap();



	/*map = MapLayer::create();

	bulletLayer = BulletLayer::create();


	main = (MainFly*)MainFly::myCreate("main.png");
	warrior = (Warrior*)Warrior::create("sprite_1.png");
	warrior->setName("Warrior");
	auto weapon = (Weapon*)Weapon::create("weapon1.png");
	warrior->setWeapon(weapon);*/


	/*std::string arrFile[] =
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
	for (int i = 0; i < 4; i++){
	auto arr = Input::create("arr.png", Rect(i * 96, 0, 96, 96));
	arr->setTag(i);
	arr->setPosition(arrPos[i]);
	arr->setControllee(warrior);
	inputs.push_back(arr);
	this->addChild(arr, 20);
	}

	warrior->setPosition(Vec2(oriX, oriY));
	//warrior->setWorldPosition(Vec2(oriX, oriY));
	//warrior->setEffect(_effect, "warrior_n.png");

	for (int i = 0; i < 21; i++)
	{
	auto skull = Skull::myCreate("skull1.png");
	skull->setPosition(Vec2(oriX*(i), oriY));
	skull->setName("skull");
	//skull->setEffect(_effect, "warrior_n.png");
	auto skullWeapon = SkullWeapon::create("skullWeapon.png");
	map->addChild(skullWeapon, 10);
	skull->setWeapon(skullWeapon);
	map->addChild(skull, 10);

	}
	mainPos = Vec2(100, 100);
	main->setPosition(mainPos);*/

	//auto enemy = (Enemy*)Enemy::myCreate("main.png");
	//enemy->enemyWeakUp(this);





	/*warrior->scheduleUpdate();
	map->scheduleUpdate();
	this->scheduleUpdate();
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(Stage1::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Stage1::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(Stage1::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);*/


	/*CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("bgm/01.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm/01.mp3", true);


	map1 = Sprite::create("pixel_art_landscape_by_mockingjay1701-d8omc3c.png");
	Vec2 map1Pos = Vec2(0 + map1->getContentSize().width / 2, 0 + map1->getContentSize().height / 10);
	map1->setPosition(map1Pos);


	trees = Sprite::create("trees.png");
	Vec2 treesPos = Vec2(0 + trees->getContentSize().width / 2, 0 + trees->getContentSize().height - 200);
	trees->setPosition(treesPos);


	ParticleSystemQuad* mSystem = ParticleSystemQuad::create("test.plist");
	mSystem->setTextureWithRect(TextureCache::sharedTextureCache()->addImage("8.png"), Rect(0, 0, 64, 64));
	mSystem->setBlendAdditive(true);
	mSystem->setPosition(ccp(0, 540));*/

	/*this->addChild(map, 2);
	this->addChild(bulletLayer, 1);
	map->addChild(weapon, 5);
	map->addChild(warrior, 5);
	this->addChild(main, 10);
	this->addChild(map1, 0);
	this->addChild(trees, 1);
	this->addChild(mSystem, 50);*/





	this->schedule(schedule_selector(Stage1::loadingsStep), 0.1f);

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






	return true;
}

bool isCollison(Sprite* p1, Sprite* p2)
{
	if (p1 != NULL && p2 != NULL)
	{
		int minX = p1->boundingBox().getMinX();
		int minY = p1->boundingBox().getMinY();
		int maxX = p1->boundingBox().getMaxX();
		int maxY = p1->boundingBox().getMaxY();

		return (p2->boundingBox().getMidX() <= maxX && p2->boundingBox().getMidX() >= minX&&
			p2->boundingBox().getMidY() <= maxY && p2->boundingBox().getMidY() >= minY
			) ? true : false;
	}
	else
		return false;

}

void Stage1::update(float delta)
{
	Vec2 mapPos = map->getPosition();
	Vec2 landScapePos = map1->getPosition();
	Vec2 treesPos = trees->getPosition();
	if ((oriX - warrior->getPosition().x) <= -200)
	{
		mapPos.x += ((oriX + 200) - warrior->getPosition().x);
		landScapePos.x += ((oriX + 200) - warrior->getPosition().x) / 100;
		treesPos.x += ((oriX + 200) - warrior->getPosition().x) / 10;
		oriX = warrior->getPosition().x - 200;
	}
	else if ((oriX - warrior->getPosition().x) >= 200)
	{
		mapPos.x += ((oriX -200 ) - warrior->getPosition().x);
		landScapePos.x += ((oriX - 200) - warrior->getPosition().x) / 100;
		treesPos.x += ((oriX - 200) - warrior->getPosition().x) / 10;
		oriX = warrior->getPosition().x + 200;
	}
	if ((oriY - warrior->getPosition().y) <= -100)
	{
		mapPos.y += ((oriY + 100) - warrior->getPosition().y);
		landScapePos.y += ((oriY + 100) - warrior->getPosition().y) / 100;
		treesPos.y += ((oriY + 100) - warrior->getPosition().y) / 10;
		oriY = warrior->getPosition().y - 100;
	}
	else if ((oriY - warrior->getPosition().y) >= 100)
	{
		mapPos.y += ((oriY - 100) - warrior->getPosition().y);
		landScapePos.y += ((oriY - 100) - warrior->getPosition().y) / 100;
		treesPos.y += ((oriY - 100) - warrior->getPosition().y) / 10;
		oriY = warrior->getPosition().y + 100;
	}
	map->setPosition(mapPos);
	map1->setPosition(landScapePos);
	trees->setPosition(treesPos);

	


	//static float y = 0;
	//y -= 0.1f;
	//map->setPositionY(y);
	return;
	static int time = 0;
	if (time++ % main->getshootSpeed() == 0)
	{
		main->onFire(bulletLayer);
	}

	Vector<Sprite*> removeBullet;
	Vector<Sprite*> removeEm;

	for (int i = 0; i < bulletLayer->getChildren().size(); i++)
	{
		//break;
		Sprite* bullet = (Sprite*)bulletLayer->getChildren().at(i);

		for (int j = 0; j < map->getChildren().size(); j++){
			Sprite* sp = (Sprite*)map->getChildren().at(j);
			if (sp->getName() == "map")
				continue;
			else
			{
				if (isCollison(sp, bullet))
				{
					removeBullet.pushBack(bullet);
					removeEm.pushBack(sp);
				}
				else if ((sp->getPosition().y > 1000 || sp->getPosition().x > 1000
					|| sp->getPosition().y < -10 || sp->getPosition().x < -10)
					)
				{
					removeEm.pushBack(sp);
				}
				else if ((bullet->getPosition().y > 1000 || bullet->getPosition().x > 1000
					|| bullet->getPosition().y < -10 || bullet->getPosition().x < -10)
					)
				{
					removeBullet.pushBack(bullet);
				}
			}
		}
	}
	REMOVE_DELETE_SPRITE(bulletLayer, removeBullet);
	REMOVE_DELETE_SPRITE(map, removeEm);
}

bool Stage1::onTouchBegan(Touch* touch, Event* event)
{
	//main->setPosition(touch->getLocation());
	//main->setString("You Touched Here");
	//isTouchEnd = false;
	for (int i = 0; i < 4; i++)
		inputs[i]->onTouchBegan(touch, event);

	return true;
}

void Stage1::onTouchEnded(Touch* touch, Event* event)
{
	isTouchEnd = true;
	cocos2d::log("touch ended");
	for (int i = 0; i < 4; i++)
		inputs[i]->onTouchEnded(touch, event);
}

void Stage1::onTouchMoved(Touch* touch, Event* event)
{
	for (int i = 0; i < 4; i++)
		inputs[i]->onTouchMoved(touch, event);

	static Vec2 prePos(-1, -1);
	if (isTouchEnd)
	{
		isTouchEnd = false;
		prePos = Vec2(-1, -1);
	}
	if (prePos.x != -1){
		Vec2 diff = touch->getLocation() - prePos;
		if (main->getBoundingBox().containsPoint(touch->getLocation()))
		mainPos += diff;
	}
	prePos = touch->getLocation();
	main->setPosition(mainPos);

	cocos2d::log("touch moved");


	//_effect->setLightPos(Vec3(mainPos.x,mainPos.y,100));
	//map->setLightPos(Vec3(mainPos.x, mainPos.y, 100));
}