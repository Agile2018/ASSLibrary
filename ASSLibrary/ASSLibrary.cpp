#include "stdafx.h"

#include "ASSLibrary.h"

using namespace ASSLibrary;

Aipu::Aipu() {
	implementAipu = new UnmanagedAipu();
}

Aipu::~Aipu() {

}

void Aipu::LoadConfiguration(String ^ fileString) {
	pin_ptr<const WCHAR> fileConfig = PtrToStringChars(fileString);
	implementAipu->LoadConfiguration(fileConfig);	

}

void Aipu::InitLibrary() {
	implementAipu->InitLibrary();
}

void Aipu::RunVideo() {
	implementAipu->RunVideo();
}
