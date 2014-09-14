#include "stdafx.h"
#include "Sharpen.h"
using namespace GdipEffects;

Sharpen::Sharpen()
{
	nativeMember = new gdip_effect_wrap<Gdiplus::Sharpen>();
}

Sharpen::~Sharpen()
{
	if(nativeMember)
		delete nativeMember;
}

Gdiplus::SharpenParams Sharpen::GetParams()
{
	UINT cnt = sizeof(Gdiplus::SharpenParams);
	Gdiplus::SharpenParams params = {};
	Gdiplus::Status st = nativeMember->GetParameters(&cnt, &params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
	return params;
}

void Sharpen::SetParams(float radius, float amount)
{
	Gdiplus::SharpenParams params = {};
	params.radius = radius;
	params.amount = amount;
	Gdiplus::Status st = nativeMember->SetParameters(&params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
}