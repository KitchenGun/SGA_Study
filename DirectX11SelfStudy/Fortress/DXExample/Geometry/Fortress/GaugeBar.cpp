#include "stdafx.h"
#include "GaugeBar.h"

GaugeBar::GaugeBar(Vector3 position, Vector3 size, float rotation)
	:TextureRect(position,size,rotation)
{
	SetSRV(L"./_Textures/Gauge.png");
	GB->SetTarget(true);
	GB->SetBarSize(0);
}

GaugeBar::~GaugeBar()
{
}

void GaugeBar::Update()
{

}
