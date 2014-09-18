#include "stdafx.h"
#include "HueSaturationLuminance.h"
using namespace GdipEffects;

HueSaturationLuminance::HueSaturationLuminance()
{
	nativeMember = new gdip_effect_wrap<Gdiplus::HueSaturationLightness>();	
}

HueSaturationLuminance::~HueSaturationLuminance()
{
	if(nativeMember)
		delete nativeMember;
}

Gdiplus::HueSaturationLightnessParams HueSaturationLuminance::GetParams()
{
	UINT cnt = sizeof(Gdiplus::HueSaturationLightnessParams);
	Gdiplus::HueSaturationLightnessParams params = {};
	Gdiplus::Status st = nativeMember->GetParameters(&cnt, &params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
	return params;
}

void HueSaturationLuminance::SetParams(int hue, int saturation, int luminance)
{
	Gdiplus::HueSaturationLightnessParams params = {};
	params.hueLevel = hue;
	params.lightnessLevel = luminance;
	params.saturationLevel = saturation;
	Gdiplus::Status st = nativeMember->SetParameters(&params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
}