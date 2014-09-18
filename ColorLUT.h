// ColorLUT.h
#pragma once
#include "Stdafx.h"
#include "GdipEffects.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::CompilerServices;
using namespace System::Collections::Generic;

namespace GdipEffects {

	public ref class ColorModifier :
		public IEnumerable<unsigned char>
	{
	public:
		ColorModifier()
		{
			data = gcnew array<unsigned char>(256);
			for(int i = 0; i < 256; ++i)
				data[i] = i;
		}
		ColorModifier(array<unsigned char>^ rep)
		{
			data = gcnew array<unsigned char>(256);
			for(int i = 0; i < 256; ++i)
				data[i] = rep->Length > i ? rep[i] : i;
		}
		virtual IEnumerator<unsigned char>^ GetEnumerator()
		{
			return gcnew enumerator(this);
		}
		virtual Collections::IEnumerator^ GetEnumerator2() = Collections::IEnumerable::GetEnumerator
		{
			return gcnew enumerator(this);
		}
		property int Length {int get() {return 256;}}
		property unsigned char default[int]
		{
			unsigned char get(int idx)
			{
				return data[idx];
			}
			void set(int idx, unsigned char val)
			{
				data[idx] = val;
			}
		}
	private:
		ref struct enumerator : IEnumerator<unsigned char>
		{
		public:
			enumerator(ColorModifier^ m)
			{
				data = m;
				idx = -1;
			}
			~enumerator() {}
			virtual bool MoveNext() = IEnumerator<unsigned char>::MoveNext
			{
				if(idx < data->data->Length - 1)
				{
					idx++;
					return true;
				}
				return false;
			}
			property unsigned char Current
			{
				virtual unsigned char get() = IEnumerator<unsigned char>::Current::get
				{
					return data->data[idx];
				}
			}
			property Object^ Current2
			{
				virtual Object^ get() = System::Collections::IEnumerator::Current::get
				{
					return data->data[idx];
				}
			}
			virtual void Reset() = IEnumerator<unsigned char>::Reset {}
		private:
			ColorModifier^ data;
			int idx;
		};
		array<unsigned char>^ data;
	};

	public ref class ColorLUT sealed :
		public Effect
	{
	public:
		ColorLUT();
		~ColorLUT();
		virtual IntPtr GetNativeWrapper() override {return IntPtr(dynamic_cast<gdip_call_e*>(nativeMember));}
		property ColorModifier^ RedChannel
		{
			ColorModifier^ get() {return red;}
			void set(ColorModifier^ val) {red = val; SetParams();}
		}
		property ColorModifier^ GreenChannel
		{
			ColorModifier^ get() {return green;}
			void set(ColorModifier^ val) {green = val; SetParams();}
		}
		property ColorModifier^ BlueChannel
		{
			ColorModifier^ get() {return blue;}
			void set(ColorModifier^ val) {blue = val; SetParams();}
		}
		property ColorModifier^ AlphaChannel
		{
			ColorModifier^ get() {return alpha;}
			void set(ColorModifier^ val) {alpha = val; SetParams();}
		}
	private:
		gdip_effect_wrap<Gdiplus::ColorLUT>* nativeMember;
		ColorModifier^ red, ^green, ^blue, ^alpha;
		void SetParams();
	};

}
