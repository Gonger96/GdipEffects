// RedEyeCorrection.h
#pragma once
#include "Stdafx.h"
#include "GdipEffects.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::CompilerServices;
using namespace System::Collections::Generic;

namespace GdipEffects {

	public ref class RedEyeCorrection sealed :
		public Effect
	{
	public:
		RedEyeCorrection();
		~RedEyeCorrection();
		virtual IntPtr GetNativeWrapper() override {return IntPtr(dynamic_cast<gdip_call_e*>(nativeMember));}
		void AddRectangle(System::Drawing::Rectangle rc)
		{
			rects->Add(rc);
			SetParams();
		}
		void AddRectangleRange(IEnumerable<System::Drawing::Rectangle>^ rectangles)
		{
			rects->AddRange(rectangles);
			SetParams();
		}
		void RemoveRectangle(System::Drawing::Rectangle rc)
		{
			rects->Remove(rc);
			SetParams();
		}
		void RemoveRange(int index, int count)
		{
			rects->RemoveRange(index, count);
		}
		System::Drawing::Rectangle^ GetRectangle(int index)
		{
			return rects[index];
		}
		property int RectangleCount
		{
			int get()
			{
				return rects->Count;
			}
		}
	private:
		gdip_effect_wrap<Gdiplus::RedEyeCorrection>* nativeMember;
		List<System::Drawing::Rectangle>^ rects;
		void SetParams();
	};

}
