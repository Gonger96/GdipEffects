#include "stdafx.h"
#include "BrightnessContrast.h"
using namespace GdipEffects;

BrightnessContrast::BrightnessContrast()
{
	nativeMember = new gdip_effect_wrap<Gdiplus::BrightnessContrast>();	
}

BrightnessContrast::~BrightnessContrast()
{
	if(nativeMember)
		delete nativeMember;
}

Gdiplus::BrightnessContrastParams BrightnessContrast::GetParams()
{
	UINT cnt = sizeof(Gdiplus::BrightnessContrastParams);
	Gdiplus::BrightnessContrastParams params = {};
	Gdiplus::Status st = nativeMember->GetParameters(&cnt, &params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
	return params;
}

void BrightnessContrast::SetParams(int brightness, int contrast)
{
	Gdiplus::BrightnessContrastParams params = {};
	params.brightnessLevel = brightness;
	params.contrastLevel = contrast;
	Gdiplus::Status st = nativeMember->SetParameters(&params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
}