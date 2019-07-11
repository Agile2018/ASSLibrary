#pragma once

#include <windows.h>
#include <vcclr.h>
#using <System.dll>
#using <System.Drawing.dll>
#include <string>

using namespace System;
using namespace System::Drawing;
using namespace std;

namespace ASSLibrary {

	class UnmanagedAipu {
	public:

		LPCWSTR GetError();

		LPCWSTR GetUser();

		void InitLibrary();

		void LoadConfiguration(LPCWSTR nameFile);
		
		void RunVideo();
		void SetIsRegister(bool option);
		void StopVideo();
		void SetLapseReadImage(int lapse);
		void SetIndexImage(int index);
		
	private:
		
	};


	public ref class Aipu
	{
	public:
		Aipu();
		~Aipu();

		property System::String ^  GetError{
			System::String ^ get() {
				return gcnew System::String(implementAipu->GetError());
			}
		}

		property System::String ^  GetUser {
			System::String ^ get() {
				return gcnew System::String(implementAipu->GetUser());
			}
		}
			
		void InitLibrary();
		void RunVideo();
		void LoadConfiguration(System::String ^ fileString);
		void SetIsRegister(System::Boolean option);
		void StopVideo();
		void SetLapseReadFrame(System::Int32 lapse);
		void SetIndexImage(System::Int32 index);
	protected:

		!Aipu() {
			delete implementAipu;
		}

	private:
		UnmanagedAipu* implementAipu;
		
	};
}
