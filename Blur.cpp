#include "Stdafx.h"
#include "Blur.h"
using namespace GdipEffects;

Blur::Blur()
{
	nativeMember = new gdip_effect_wrap<Gdiplus::Blur>();	
}

Blur::~Blur()
{
	if(nativeMember)
		delete nativeMember;
}

Gdiplus::BlurParams Blur::GetParams()
{
	UINT cnt = sizeof(Gdiplus::BlurParams);
	Gdiplus::BlurParams params = {};
	Gdiplus::Status st = nativeMember->GetParameters(&cnt, &params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
	return params;
}

void Blur::SetParams(float radius, bool edge)
{
	Gdiplus::BlurParams params = {};
	params.radius = radius;
	params.expandEdge = edge;
	Gdiplus::Status st = nativeMember->SetParameters(&params);
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
}