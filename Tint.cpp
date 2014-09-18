#include "stdafx.h"
#include "Tint.h"
using namespace GdipEffects;

Tint::Tint()
{
	nativeMember = new gdip_effect_wrap<Gdiplus::Tint>();
}

Tint::~Tint()
{
	if(nativeMember)
		delete nativeMember;
}

Gdiplus::TintParams Tint::GetParams()
{
	UINT cnt = sizeof(Gdiplus::TintParams);
	Gdiplus::TintParams params = {};
	Gdiplus::Status st = nativeMember->GetParameters(&cnt, &params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
	return params;
}

void Tint::SetParams(int hue, int amount)
{
	Gdiplus::TintParams params = {};
	params.hue = hue;
	params.amount = amount;
	Gdiplus::Status st = nativeMember->SetParameters(&params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
}