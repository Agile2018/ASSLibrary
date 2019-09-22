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

		float* GetCoordinates();
		void InitLibrary();

		void LoadConfiguration(LPCWSTR nameFile);
		
		void SetIsRegister(bool option);
		
		void SetWorkMode(int mode);
		int GetWorkMode();
		void RecognitionFace(unsigned char* image, int rows, 
			int cols, int client);
		void RecognitionFastFace(unsigned char* image, int rows,
			int cols);
		void InitTracking(unsigned char* image, int rows,
			int cols);
		void Tracking(unsigned char* image, int rows,
			int cols);
		void Terminate(int option);
		void Reset();
		void SetSequenceFps(int value);
		void ResfreshBetweenFrame(int value);
		void TerminateTracking();
		bool GetStateProccessRecognition();
		void ResetIdUser();
		void SetConfigurationDatabase();
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
		
		property System::Boolean GetStateProccessRecognition {
			System::Boolean get() {
				return implementAipu->GetStateProccessRecognition();
			}
		}

		cli::array<float>^ GetCoordinates();

		void InitLibrary();
		
		void LoadConfiguration(System::String ^ fileString);
		void SetIsRegister(System::Boolean option);
		
		void SetWorkMode(System::Int32 mode);
		void SetFrame(cli::array<System::Byte>^ data, 
			System::Int32 rows, System::Int32 cols, System::Int32 client);
		void SetFastFrame(cli::array<System::Byte>^ data,
			System::Int32 rows, System::Int32 cols);
		void InitTracking(cli::array<System::Byte>^ data,
			System::Int32 rows, System::Int32 cols);
		void Tracking(cli::array<System::Byte>^ data,
			System::Int32 rows, System::Int32 cols);
		void Terminate(System::Int32 option);
		void Reset();
		void SetSequenceFps(System::Int32 value);
		void ResfreshBetweenFrame(System::Int32 value);
		void TerminateTracking();
		void ResetIdUser();
		void SetConfigurationDatabase();
	protected:

		!Aipu() {
			delete implementAipu;
		}

	private:
		UnmanagedAipu* implementAipu;
		
	};
}
