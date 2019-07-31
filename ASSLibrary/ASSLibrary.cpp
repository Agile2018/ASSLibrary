#include "stdafx.h"

#include "ASSLibrary.h"
#include <AipuLib.h>


using namespace ASSLibrary;


AipuLib* aipuLib;


Aipu::Aipu() {
	implementAipu = new UnmanagedAipu();
}

Aipu::~Aipu() {
	delete implementAipu;
}

void Aipu::LoadConfiguration(System::String ^ fileString) {
	pin_ptr<const WCHAR> fileConfig = PtrToStringChars(fileString);
	implementAipu->LoadConfiguration(fileConfig);	

}

void Aipu::InitLibrary() {
	implementAipu->InitLibrary();
}

void Aipu::SetIsRegister(System::Boolean option) {
	if (option.Equals(true))
	{
		implementAipu->SetIsRegister(true);
	}
	else {
		implementAipu->SetIsRegister(false);
	}
	
}

void Aipu::SetWorkMode(System::Int32 mode) {

	implementAipu->SetWorkMode(mode);
}

void Aipu::SetFrame(cli::array<System::Byte>^ data, 
	System::Int32 rows, System::Int32 cols) {
	pin_ptr<System::Byte> ptrByte = &data[0];
	unsigned char* bufferImage = ptrByte;
	implementAipu->RecognitionFace(bufferImage, rows, cols);
		
}

void Aipu::Terminate() {
	implementAipu->Terminate();
	delete implementAipu;
	
}
UnmanagedAipu::UnmanagedAipu() {
	aipuLib = new AipuLib();
}
UnmanagedAipu::~UnmanagedAipu() {
	
}

LPCWSTR UnmanagedAipu::GetError() {
	string messageReceived = aipuLib->GetMessageError();
	wstring wideMessage(messageReceived.begin(), messageReceived.end());
	const wchar_t* resultMessage = wideMessage.c_str();
	return resultMessage;
}

LPCWSTR UnmanagedAipu::GetUser() {
	string user = aipuLib->GetUserJSON();
	wstring wideUser(user.begin(), user.end());
	const wchar_t* resultUser = wideUser.c_str();
	//printf("ASSLIB: %ws \n", resultUser);
	return resultUser;

}

void UnmanagedAipu::InitLibrary() {
	aipuLib->InitLibrary();
}

void UnmanagedAipu::LoadConfiguration(LPCWSTR nameFile) {
	wstring lpcwstrToWstring(nameFile);
	string wStringToString(lpcwstrToWstring.begin(), lpcwstrToWstring.end());	
	aipuLib->LoadConfiguration(wStringToString);

}

void UnmanagedAipu::SetIsRegister(bool option) {
	aipuLib->SetIsRegister(option);
}

void UnmanagedAipu::SetWorkMode(int mode) {
	aipuLib->SetWorkMode(mode);
}

int UnmanagedAipu::GetWorkMode() {
	return aipuLib->GetWorkMode();
}

void UnmanagedAipu::RecognitionFace(unsigned char* image,
	int rows, int cols) {
	aipuLib->RecognitionFace(image, rows, cols);
}

void UnmanagedAipu::Terminate() {
	aipuLib->Terminate();
	delete aipuLib;
}