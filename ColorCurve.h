// ColorCurve.h
#pragma once
#include "Stdafx.h"
#include "GdipEffects.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::CompilerServices;

namespace GdipEffects {

	public enum class CurveAdjustments 
	{
		Exposure          = 0,
		Density           = 1,
		Contrast          = 2,
		Highlight         = 3,
		Shadow            = 4,
		Midtone           = 5,
		WhiteSaturation   = 6,
		BlackSaturation   = 7 
	};

	public enum class CurveChannel
	{
		All     = 0,
		Red     = 1,
		Green   = 2,
		Blue    = 3
	};

	public ref class ColorCurve sealed :
		public Effect
	{
	public:
		ColorCurve();
		~ColorCurve();
		virtual IntPtr GetNativeWrapper() override {return IntPtr(dynamic_cast<gdip_call_e*>(nativeMember));}
		property int AdjustValue
		{
			int get()
			{
				return GetParams().adjustValue;
			}
			void set(int val)
			{
				auto params = GetParams();
				SetParams(params.adjustment, params.channel, val);
			}
		}
		property CurveAdjustments Adjustment
		{
			CurveAdjustments get()
			{
				return static_cast<CurveAdjustments>(GetParams().adjustment);
			}
			void set(CurveAdjustments val)
			{
				auto params = GetParams();
				SetParams(static_cast<Gdiplus::CurveAdjustments>(val), params.channel, params.adjustValue);
			}
		}
		property CurveChannel Channel
		{
			CurveChannel get()
			{
				return static_cast<CurveChannel>(GetParams().adjustValue);
			}
			void set(CurveChannel val)
			{
				auto params = GetParams();
				SetParams(params.adjustment, static_cast<Gdiplus::CurveChannel>(val), params.adjustValue);
			}
		}
	private:
		gdip_effect_wrap<Gdiplus::ColorCurve>* nativeMember;
		Gdiplus::ColorCurveParams GetParams();
		void SetParams(Gdiplus::CurveAdjustments adjustment, Gdiplus::CurveChannel channel, int adjustValue);
	};

}
