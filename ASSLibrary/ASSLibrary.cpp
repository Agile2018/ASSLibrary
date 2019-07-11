#include "stdafx.h"

#include "ASSLibrary.h"
#include <AipuLib.h>


using namespace ASSLibrary;


AipuLib* aipuLib = new AipuLib();


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

void Aipu::RunVideo() {
	implementAipu->RunVideo();
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

void Aipu::StopVideo() {
	implementAipu->StopVideo();
}

void Aipu::SetLapseReadFrame(System::Int32 lapse) {
	
	implementAipu->SetLapseReadImage(lapse);
}

void Aipu::SetIndexImage(System::Int32 index) {

	implementAipu->SetIndexImage(index);
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

void  UnmanagedAipu::LoadConfiguration(LPCWSTR nameFile) {
	wstring lpcwstrToWstring(nameFile);
	string wStringToString(lpcwstrToWstring.begin(), lpcwstrToWstring.end());
	aipuLib->LoadConfiguration(wStringToString);
}

void UnmanagedAipu::RunVideo() {
	aipuLib->RunVideo();
}

void UnmanagedAipu::SetIsRegister(bool option) {
	aipuLib->SetIsRegister(option);
}

void UnmanagedAipu::StopVideo() {
	aipuLib->StopVideo();
}

void UnmanagedAipu::SetLapseReadImage(int lapse) {
	aipuLib->SetLapseFrameToFrame(lapse);
}

void UnmanagedAipu::SetIndexImage(int index) {
	aipuLib->SetIndexImage(index);
}

//unsigned char UnmanagedAipu::GetFrame() {
//	unsigned char* frame = aipuLib->GetFrame();
//	//const unsigned char* imgData = reinterpret_cast<const unsigned char*>(frame);
//	//pin_ptr<byte> fileConfig = frame;
//	return *frame;
//}

