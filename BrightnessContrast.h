// BrightnessContrast.h
#pragma once
#include "Stdafx.h"
#include "GdipEffects.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::CompilerServices;

namespace GdipEffects {

	public ref class BrightnessContrast sealed :
		public Effect
	{
	public:
		BrightnessContrast();
		~BrightnessContrast();
		virtual IntPtr GetNativeWrapper() override {return IntPtr(dynamic_cast<gdip_call_e*>(nativeMember));}
		property int BrightnessLevel
		{
			int get() {return GetParams().brightnessLevel;}
			void set(int val)
			{
				SetParams(val, GetParams().contrastLevel);
			}
		}
		property int ContrastLevel
		{
			int get() {return GetParams().contrastLevel;}
			void set(int val)
			{
				SetParams(GetParams().brightnessLevel, val);
			}
		}
	private:
		gdip_effect_wrap<Gdiplus::BrightnessContrast>* nativeMember;
		Gdiplus::BrightnessContrastParams GetParams();
		void SetParams(int brightness, int contrast);
	};

}
