// Levels.h
#pragma once
#include "Stdafx.h"
#include "GdipEffects.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::CompilerServices;

namespace GdipEffects {

	public ref class Levels sealed :
		public Effect
	{
	public:
		Levels();
		~Levels();
		virtual IntPtr GetNativeWrapper() override {return IntPtr(dynamic_cast<gdip_call_e*>(nativeMember));}
		property int Highlight
		{
			int get()
			{
				return GetParams().highlight;
			}
			void set(int val)
			{
				auto params = GetParams();
				SetParams(val, params.midtone, params.shadow);
			}
		}
		property int Midtone
		{
			int get()
			{
				return GetParams().midtone;
			}
			void set(int val)
			{
				auto params = GetParams();
				SetParams(params.highlight, val, params.shadow);
			}
		}
		property int Shadow
		{
			int get()
			{
				return GetParams().shadow;
			}
			void set(int val)
			{
				auto params = GetParams();
				SetParams(params.highlight, params.midtone, val);
			}
		}
	private:
		gdip_effect_wrap<Gdiplus::Levels>* nativeMember;
		Gdiplus::LevelsParams GetParams();
		void SetParams(int highlight, int midtone, int shadow);
	};

}
