#pragma once

#define DLL_EXPORT __declspec(dllexport)

#include <string>

using namespace std;

extern "C" {
	int DLL_EXPORT SimpleReturnFunc();
}