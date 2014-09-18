// Tint.h
#pragma once
#include "Stdafx.h"
#include "GdipEffects.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::CompilerServices;

namespace GdipEffects {

	public ref class Tint sealed :
		public Effect
	{
	public:
		Tint();
		~Tint();
		virtual IntPtr GetNativeWrapper() override {return IntPtr(dynamic_cast<gdip_call_e*>(nativeMember));}
		property int Hue
		{
			int get() {return GetParams().hue;}
			void set(int val) {SetParams(val, GetParams().amount);}
		}
		property int Amount
		{
			int get() {return GetParams().amount;}
			void set(int val) {SetParams(GetParams().hue, val);}
		}
	private:
		gdip_effect_wrap<Gdiplus::Tint>* nativeMember;
		Gdiplus::TintParams GetParams();
		void SetParams(int hue, int amount);
	};

};