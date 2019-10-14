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
	System::Int32 rows, System::Int32 cols, System::Int32 client) {
	pin_ptr<System::Byte> ptrByte = &data[0];
	unsigned char* bufferImage = ptrByte;
	implementAipu->RecognitionFace(bufferImage, rows, cols, client);
		
}

void Aipu::SetFastFrame(cli::array<System::Byte>^ data,
	System::Int32 rows, System::Int32 cols) {
	try
	{
		pin_ptr<System::Byte> ptrByte = &data[0];
		unsigned char* bufferImage = ptrByte;
		implementAipu->RecognitionFastFace(bufferImage, rows, cols);
	}
	catch ( const std::exception ex)
	{
		printf("ASSLIB: %s \n", ex.what());
	}
	
}

void Aipu::InitTracking(cli::array<System::Byte>^ data,
	System::Int32 rows, System::Int32 cols) {
	
	pin_ptr<System::Byte> ptrByte = &data[0];
	unsigned char* bufferImage = ptrByte;
	implementAipu->InitTracking(bufferImage, rows, cols);
	
}

void Aipu::Tracking(cli::array<System::Byte>^ data,
	System::Int32 rows, System::Int32 cols) {

	pin_ptr<System::Byte> ptrByte = &data[0];
	unsigned char* bufferImage = ptrByte;
	implementAipu->Tracking(bufferImage, rows, cols);

}

void Aipu::Terminate(System::Int32 option) {
	implementAipu->Terminate(option);
	if (option == 0)
	{
		delete implementAipu;
	}
		
}

void Aipu::Reset() {
	implementAipu->Reset();
}

cli::array<float>^ Aipu::GetCoordinates() {
	float* coordinates = implementAipu->GetCoordinates();
	cli::array<float>^ values = gcnew cli::array<float>(20);

	for (int i = 0; i != values->Length; ++i)
	{
		values[i] = *coordinates;
		coordinates++;
	}
	return values;
}

void Aipu::SetSequenceFps(System::Int32 value) {
	implementAipu->SetSequenceFps(value);
}

void Aipu::ResfreshBetweenFrame(System::Int32 value) {
	implementAipu->ResfreshBetweenFrame(value);
}

void Aipu::TerminateTracking() {
	implementAipu->TerminateTracking();
}

void Aipu::ResetIdUser() {
	implementAipu->ResetIdUser();
}

void Aipu::SetConfigurationDatabase() {
	implementAipu->SetConfigurationDatabase();
}

void Aipu::ResetLowScore() {
	implementAipu->ResetLowScore();
}

void Aipu::ResetCountRepeatUser() {
	implementAipu->ResetCountRepeatUser();
}

void Aipu::ResetCountNotDetect() {
	implementAipu->ResetCountNotDetect();
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
	int rows, int cols, int client) {
	aipuLib->RecognitionFace(image, rows, cols, client);
}

void UnmanagedAipu::RecognitionFastFace(unsigned char* image, int rows,
	int cols) {
	aipuLib->RecognitionFastFace(image, rows, cols);
}

void UnmanagedAipu::InitTracking(unsigned char* image, int rows,
	int cols) {
	aipuLib->InitTracking(image, rows, cols);
}

void UnmanagedAipu::Tracking(unsigned char* image, int rows,
	int cols) {
	aipuLib->Tracking(image, rows, cols);
}

void UnmanagedAipu::Terminate(int option) {
	aipuLib->Terminate(option);
	if (option == 0)
	{
		delete aipuLib;
	}
	
}

void UnmanagedAipu::Reset() {
	aipuLib->Reset();
}

float* UnmanagedAipu::GetCoordinates() {
	return aipuLib->GetCoordinates();
}

void UnmanagedAipu::SetSequenceFps(int value) {
	aipuLib->SetSequenceFps(value);
}

void UnmanagedAipu::ResfreshBetweenFrame(int value) {
	aipuLib->ResfreshBetweenFrame(value);
}

void UnmanagedAipu::TerminateTracking() {
	aipuLib->TerminateTracking();
}

bool UnmanagedAipu::GetStateProccessRecognition() {
	return aipuLib->GetStateProccessRecognition();
}

void UnmanagedAipu::ResetIdUser() {
	aipuLib->ResetIdUser();
}

void UnmanagedAipu::SetConfigurationDatabase() {
	aipuLib->SetConfigurationDatabase();
}

void UnmanagedAipu::ResetLowScore() {
	aipuLib->ResetLowScore();
}

void UnmanagedAipu::ResetCountRepeatUser() {
	aipuLib->ResetCountRepeatUser();
}

int UnmanagedAipu::GetCountLowScore() {
	return aipuLib->GetCountLowScore();
}

int UnmanagedAipu::GetCountRepeatUser() {
	return aipuLib->GetCountRepeatUser();
}

void UnmanagedAipu::ResetCountNotDetect() {
	aipuLib->ResetCountNotDetect();
}

int UnmanagedAipu::GetCountNotDetect() {
	return aipuLib->GetCountNotDetect();
}