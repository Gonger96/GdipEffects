// GdipEffects.h
#pragma once
#include "Stdafx.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::CompilerServices;
using namespace System::Reflection;

namespace GdipEffects {
	class gdip_call_e
	{
	public:
		virtual ~gdip_call_e() {}
		virtual Gdiplus::Status call(Gdiplus::GpImage* img, RECT* ROI) = 0;
		virtual Gdiplus::Effect* get_source_effect() = 0;
	};

	template <typename base>
	class gdip_effect_wrap : 
		public base, public gdip_call_e
	{
	public:
		virtual ~gdip_effect_wrap() {}
		virtual Gdiplus::Effect* get_source_effect()
		{
			return dynamic_cast<Gdiplus::Effect*>(dynamic_cast<base*>(this));
		}
		virtual Gdiplus::Status call(Gdiplus::GpImage* img, RECT* ROI)
		{
			if(auxData)
			{
				Gdiplus::DllExports::GdipFree(auxData);
				auxData = NULL;
				auxDataSize = 0;
			}
    
			return Gdiplus::DllExports::GdipBitmapApplyEffect(
				static_cast<Gdiplus::GpBitmap*>(img),
				nativeEffect,
				ROI,
				useAuxData,
				&auxData,
				&auxDataSize
				);
		}
	};

	public ref class Effect abstract
	{
	public:
		virtual ~Effect() {}
		property int AuxDataSize
		{
			int get()
			{
				return GetNativeEffect()->GetAuxDataSize();
			}
		}
		property IntPtr AuxData
		{
			IntPtr get()
			{
				return IntPtr(GetNativeEffect()->GetAuxData());
			};
		}
		property bool UseAuxData
		{
			void set(bool flag)
			{
				GetNativeEffect()->UseAuxData(flag);
			}
		}
		property unsigned int ParameterSize
		{
			unsigned int get()
			{
				UINT i = 0;
				Gdiplus::Status st = GetNativeEffect()->GetParameterSize(&i);
				if(st != Gdiplus::Status::Ok)
					throw gcnew InvalidOperationException("Native Gdip Exception has been thrown. Status: " + static_cast<int>(st).ToString());
				return i;
			}
		}
		virtual IntPtr GetNativeWrapper() = 0;
	private:
		Gdiplus::Effect* GetNativeEffect()
		{
			return reinterpret_cast<gdip_call_e*>(GetNativeWrapper().ToPointer())->get_source_effect();
		}
	};

	[ExtensionAttribute]
	public ref class GdiPlusExtensions abstract sealed
	{
	public:
		[ExtensionAttribute]
		static void ApplyEffect(Bitmap^ bmp, Effect^ effect, System::Drawing::Rectangle bounds)
		{ 
			FieldInfo^ field = (Image::typeid)->GetField("nativeImage", BindingFlags::NonPublic | BindingFlags::Instance);
			Image^ img = bmp;
			IntPtr ptr = (IntPtr)field->GetValue(img);
			Gdiplus::GpImage* nativeImage = reinterpret_cast<Gdiplus::GpImage*>(ptr.ToPointer());
			if(!nativeImage)
				throw gcnew InvalidCastException("Invalid Image");
			gdip_call_e* wrp = reinterpret_cast<gdip_call_e*>(effect->GetNativeWrapper().ToPointer());
			if(!wrp)
				throw gcnew InvalidCastException("Invalid Wrapper");
			RECT rc = {bounds.Left, bounds.Top, bounds.Right, bounds.Bottom};
			Gdiplus::Status st = wrp->call(nativeImage, &rc);
			if(st != Gdiplus::Status::Ok)
				throw gcnew InvalidOperationException("Native Gdip Exception has been thrown. Status: " + static_cast<int>(st).ToString());
		}
	};
}
