#pragma once

#include "Geometry/Line.h"
#include "Geometry/Square.h"
#include "Geometry/Circle.h"
#include "Geometry/FilledCircle.h"
#include "Geometry/TextureRect.h"
#include "Geometry/AnimationRect.h"
#include "Characters/PlayerAfterBurner.h"
#include "Characters/Bullet.h"
#include "Geometry/BulletManager.h"
#include "Characters/Player.h"
#include "Characters/Mig25.h"
#include "Characters/Missile.h"
#include "Characters/SAM.h"

#include "Utilities/RenderTexture.h"
#include "Utilities/SoundSystem.h"

class Scene
{//순수 가상함수가 들어간 인터페이스 제작
public:
	virtual ~Scene() {};
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void PreRender() = 0;
	virtual void Render() = 0;
	virtual void PostRender() = 0;
};