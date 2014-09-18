// HueSaturationLuminance.h
#pragma once
#include "Stdafx.h"
#include "GdipEffects.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::CompilerServices;

namespace GdipEffects {

	public ref class HueSaturationLuminance sealed :
		public Effect
	{
	public:
		HueSaturationLuminance();
		~HueSaturationLuminance();
		virtual IntPtr GetNativeWrapper() override {return IntPtr(dynamic_cast<gdip_call_e*>(nativeMember));}
		property int HueLevel
		{
			int get()
			{
				return GetParams().hueLevel;
			}
			void set(int val)
			{
				auto params = GetParams();
				SetParams(val, params.saturationLevel, params.lightnessLevel);
			}
		}
		property int SaturationLevel
		{
			int get()
			{
				return GetParams().saturationLevel;
			}
			void set(int val)
			{
				auto params = GetParams();
				SetParams(params.hueLevel, val, params.lightnessLevel);
			}
		}
		property int LuminanceLevel
		{
			int get()
			{
				return GetParams().lightnessLevel;
			}
			void set(int val)
			{
				auto params = GetParams();
				SetParams(params.hueLevel, params.saturationLevel, val);
			}
		}
	private:
		gdip_effect_wrap<Gdiplus::HueSaturationLightness>* nativeMember;
		Gdiplus::HueSaturationLightnessParams GetParams();
		void SetParams(int hue, int saturation, int luminance);
	};

}
