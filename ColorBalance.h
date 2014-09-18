// ColorBalance.h
#pragma once
#include "Stdafx.h"
#include "GdipEffects.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::CompilerServices;

namespace GdipEffects {

	public ref class ColorBalance sealed :
		public Effect
	{
	public:
		ColorBalance();
		~ColorBalance();
		virtual IntPtr GetNativeWrapper() override {return IntPtr(dynamic_cast<gdip_call_e*>(nativeMember));}
		property int CyanRed
		{
			int get()
			{
				return GetParams().cyanRed;
			}
			void set(int val)
			{
				auto params = GetParams();
				SetParams(val, params.magentaGreen, params.yellowBlue);
			}
		}
		property int MagentaGreen
		{
			int get()
			{
				return GetParams().magentaGreen;
			}
			void set(int val)
			{
				auto params = GetParams();
				SetParams(params.cyanRed, val, params.yellowBlue);
			}
		}
		property int YellowBlue
		{
			int get()
			{
				return GetParams().yellowBlue;
			}
			void set(int val)
			{
				auto params = GetParams();
				SetParams(params.cyanRed, params.magentaGreen, val);
			}
		}
	private:
		gdip_effect_wrap<Gdiplus::ColorBalance>* nativeMember;
		Gdiplus::ColorBalanceParams GetParams();
		void SetParams(int cyanRed, int magentaGreen, int yellowBlue);
	};

}
