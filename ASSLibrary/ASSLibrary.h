#pragma once

#include <windows.h>
#include <vcclr.h>
#using <System.dll>
#include <AipuLib.h>
#include <string>

using namespace System;
using namespace std;

namespace ASSLibrary {

	class UnmanagedAipu {
	public:

		LPCWSTR GetError() {
			string messageReceived = aipuLib->GetMessageError();
			wstring wideMessage(messageReceived.begin(), messageReceived.end());
			const wchar_t* resultMessage = wideMessage.c_str();
			return resultMessage;
		}

		LPCWSTR GetUser() {
			string user = aipuLib->GetUserJSON();
			wstring wideUser(user.begin(), user.end());
			const wchar_t* resultUser = wideUser.c_str();
			return resultUser;

		}

		const unsigned char GetFrame() {
			unsigned char* frame = aipuLib->GetFrame();
			const unsigned char* imgData = reinterpret_cast<const unsigned char*>(frame);
			
			return *imgData;
		}

		void InitLibrary() {
			aipuLib->InitLibrary();
		}

		void LoadConfiguration(LPCWSTR nameFile) {
			wstring lpcwstrToWstring(nameFile);			
			string wStringToString(lpcwstrToWstring.begin(), lpcwstrToWstring.end());
			aipuLib->LoadConfiguration(wStringToString);
		}
		
		void RunVideo() {
			aipuLib->RunVideo();
		}

	private:
		AipuLib* aipuLib = new AipuLib();
	};


	public ref class Aipu
	{
	public:
		Aipu();
		~Aipu();

		property String ^  GetError{
			String ^ get() {
				return gcnew String(implementAipu->GetError());
			}
		}

		property String ^  GetUser {
			String ^ get() {
				return gcnew String(implementAipu->GetUser());
			}
		}
		
		property Byte^  GetFrame {
			Byte^ get() {
				return gcnew Byte(implementAipu->GetFrame());
			}
		}

		void InitLibrary();
		void RunVideo();
		void LoadConfiguration(String ^ fileString);

	protected:

		!Aipu() {
			delete implementAipu;
		}

	private:
		UnmanagedAipu* implementAipu;
	};
}
