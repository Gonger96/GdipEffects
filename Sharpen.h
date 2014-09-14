// Blur.h
#pragma once
#include "Stdafx.h"
#include "GdipEffects.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::CompilerServices;

namespace GdipEffects {

	public ref class Sharpen sealed :
		public Effect
	{
	public:
		Sharpen();
		~Sharpen();
		virtual IntPtr GetNativeWrapper() override {return IntPtr(dynamic_cast<gdip_call_e*>(nativeMember));}
		property float Radius
		{
			float get()
			{
				return GetParams().radius;
			}
			void set(float val)
			{
				SetParams(val, GetParams().amount);
			} 
		}
		property float Amount
		{
			float get()
			{
				return GetParams().amount;
			}
			void set(float val)
			{
				SetParams(GetParams().radius, val);
			}
		}
	private:
		gdip_effect_wrap<Gdiplus::Sharpen>* nativeMember;
		Gdiplus::SharpenParams GetParams();
		void SetParams(float radius, float amount);
	};

};

