#include "stdafx.h"
#include "Levels.h"
using namespace GdipEffects;

Levels::Levels()
{
	nativeMember = new gdip_effect_wrap<Gdiplus::Levels>();	
}

Levels::~Levels()
{
	if(nativeMember)
		delete nativeMember;
}

Gdiplus::LevelsParams Levels::GetParams()
{
	UINT cnt = sizeof(Gdiplus::LevelsParams);
	Gdiplus::LevelsParams params = {};
	Gdiplus::Status st = nativeMember->GetParameters(&cnt, &params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
	return params;
}

void Levels::SetParams(int highlight, int midtone, int shadow)
{
	Gdiplus::LevelsParams params = {};
	params.highlight = highlight;
	params.midtone = midtone;
	params.shadow = shadow;
	Gdiplus::Status st = nativeMember->SetParameters(&params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
}