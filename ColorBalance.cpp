#include "stdafx.h"
#include "ColorBalance.h"
using namespace GdipEffects;

ColorBalance::ColorBalance()
{
	nativeMember = new gdip_effect_wrap<Gdiplus::ColorBalance>();	
}

ColorBalance::~ColorBalance()
{
	if(nativeMember)
		delete nativeMember;
}

Gdiplus::ColorBalanceParams ColorBalance::GetParams()
{
	UINT cnt = sizeof(Gdiplus::ColorBalanceParams);
	Gdiplus::ColorBalanceParams params = {};
	Gdiplus::Status st = nativeMember->GetParameters(&cnt, &params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
	return params;
}

void ColorBalance::SetParams(int cyanRed, int magentaGreen, int yellowBlue)
{
	Gdiplus::ColorBalanceParams params = {};
	params.cyanRed = cyanRed;
	params.magentaGreen = magentaGreen;
	params.yellowBlue = yellowBlue;
	Gdiplus::Status st = nativeMember->SetParameters(&params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
}