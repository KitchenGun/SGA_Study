#pragma once

class Scene
{//순수 가상함수가 들어간 인터페이스 제작
public:
	virtual ~Scene() {};
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void PreRender() = 0;
	virtual void Render() = 0;
};