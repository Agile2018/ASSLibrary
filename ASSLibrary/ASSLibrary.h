#pragma once

#include <windows.h>
#include <vcclr.h>
#using <System.dll>
#using <System.Drawing.dll>
#include <string>
#include <array>

using namespace System;
using namespace System::Drawing;
using namespace std;

namespace ASSLibrary {

	class UnmanagedAipu {
	public:
		UnmanagedAipu();
		~UnmanagedAipu();
		LPCWSTR GetError();

		LPCWSTR GetUser();

		void InitLibrary();

		void LoadConfiguration(LPCWSTR nameFile);
		
		void SetIsRegister(bool option);
		
		void SetWorkMode(int mode);
		int GetWorkMode();
		void RecognitionFace(unsigned char* image, int rows, 
			int cols, int client);
		void Terminate();
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

		property System::Int32 GetWorkMode {
			System::Int32 get() {
				return implementAipu->GetWorkMode();
			}
		}
			
		void InitLibrary();
		
		void LoadConfiguration(System::String ^ fileString);
		void SetIsRegister(System::Boolean option);
		
		void SetWorkMode(System::Int32 mode);
		void SetFrame(cli::array<System::Byte>^ data, 
			System::Int32 rows, System::Int32 cols, System::Int32 client);
		void Terminate();
	protected:

		!Aipu() {
			delete implementAipu;
		}

	private:
		UnmanagedAipu* implementAipu;
		
	};
}
