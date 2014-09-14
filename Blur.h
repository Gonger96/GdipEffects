// Blur.h
#pragma once
#include "Stdafx.h"
#include "GdipEffects.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::CompilerServices;

namespace GdipEffects {

	public ref class Blur sealed :
		public Effect
	{
	public:
		Blur();
		~Blur();
		virtual IntPtr GetNativeWrapper() override {return IntPtr(dynamic_cast<gdip_call_e*>(nativeMember));}
		property float Radius
		{
			float get()
			{
				return GetParams().radius;
			}
			void set(float val)
			{
				SetParams(val, !!GetParams().expandEdge);
			} 
		}
		property bool ExpandEdge
		{
			bool get()
			{
				return !!GetParams().expandEdge;
			}
			void set(bool val)
			{
				SetParams(GetParams().radius, val);
			}
		}
	private:
		gdip_effect_wrap<Gdiplus::Blur>* nativeMember;
		Gdiplus::BlurParams GetParams();
		void SetParams(float radius, bool edge);
	};

}
