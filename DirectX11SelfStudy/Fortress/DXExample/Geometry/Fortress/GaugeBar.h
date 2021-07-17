#pragma once
class GaugeBar : public TextureRect
{
public:
	GaugeBar(Vector3 position, Vector3 size, float rotation);
	~GaugeBar();

	void SetBarSize(float val) { GB->SetBarSize(val); }
	void Update() override;
private:

};