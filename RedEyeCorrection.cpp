#include "Stdafx.h"
#include "RedEyeCorrection.h"
using namespace GdipEffects;

RedEyeCorrection::RedEyeCorrection()
{
	nativeMember = new gdip_effect_wrap<Gdiplus::RedEyeCorrection>();
	rects = gcnew List<System::Drawing::Rectangle>();
}

RedEyeCorrection::~RedEyeCorrection()
{
	if(nativeMember)
		delete nativeMember;
}

void RedEyeCorrection::SetParams()
{
	RECT* rcs = new RECT[rects->Count];
	for(int i = 0; i < rects->Count; ++i)
	{
		rcs[i].bottom = rects[i].Bottom;
		rcs[i].top = rects[i].Top;
		rcs[i].right = rects[i].Right;
		rcs[i].left = rects[i].Left;
	}
	Gdiplus::RedEyeCorrectionParams params;
	params.areas = rcs;
	params.numberOfAreas = rects->Count;
	Gdiplus::Status st = nativeMember->SetParameters(&params);
	delete[] rcs;
	if(st != Gdiplus::Status::Ok)
		throw gcnew InvalidOperationException("Gdip native Exception has been thrown: " + static_cast<int>(st).ToString());
}