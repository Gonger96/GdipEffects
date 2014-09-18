#include "stdafx.h"
#include "ColorCurve.h"
using namespace GdipEffects;

ColorCurve::ColorCurve()
{
	nativeMember = new gdip_effect_wrap<Gdiplus::ColorCurve>();
}

ColorCurve::~ColorCurve()
{
	if(nativeMember)
		delete nativeMember;
}

Gdiplus::ColorCurveParams ColorCurve::GetParams()
{
	UINT cnt = sizeof(Gdiplus::ColorCurveParams);
	Gdiplus::ColorCurveParams params = {};
	Gdiplus::Status st = nativeMember->GetParameters(&cnt, &params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
	return params;
}

void ColorCurve::SetParams(Gdiplus::CurveAdjustments adjustment, Gdiplus::CurveChannel channel, int adjustValue)
{
	Gdiplus::ColorCurveParams params = {};
	params.adjustment = adjustment;
	params.adjustValue = adjustValue;
	params.channel = channel;
	Gdiplus::Status st = nativeMember->SetParameters(&params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
}