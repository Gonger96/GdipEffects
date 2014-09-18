#include "Stdafx.h"
#include "ColorLUT.h"
using namespace GdipEffects;

ColorLUT::ColorLUT()
{
	nativeMember = new gdip_effect_wrap<Gdiplus::ColorLUT>();
	red = gcnew ColorModifier();
	green = gcnew ColorModifier();
	blue = gcnew ColorModifier();
	alpha = gcnew ColorModifier();
}

ColorLUT::~ColorLUT()
{
	if(nativeMember)
		delete nativeMember;
}

void ColorLUT::SetParams()
{
	Gdiplus::ColorLUTParams params = {};
	for(int i = 0; i < 256; ++i)
	{
		params.lutR[i] = red[i];
		params.lutG[i] = green[i];
		params.lutB[i] = blue[i];
		params.lutA[i] = alpha[i];
	}
	Gdiplus::Status st = nativeMember->SetParameters(&params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
}