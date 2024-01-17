/*
	 This code is used to combine add run key to this code, so code will start with the PC.
	 Date: 17/1/2024
*/

#include <iostream>
#include <windows.h>
#include <string.h>

int main() {
	// const char* path = "C:\\Users\\lynt1\\OneDrive\\Desktop\\Project2.exe";
	const char* subkey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";

	char path[MAX_PATH];
	GetModuleFileNameA(NULL, (LPSTR)path, MAX_PATH);

	HKEY hKey = NULL;
	/* A handle to a registry key.
	typedef HANDLE HKEY;*/

	LONG result = RegOpenKeyExA(
		HKEY_CURRENT_USER, // Can be one of 5 key roots
		(LPCSTR)subkey,	   // The name of registry subkey to be open
		0,                 // Specify the option to apply when open // set parameter to 0
		KEY_WRITE,         // Registry Key Security and Access Right
		&hKey
	);

	// If the function succeeds, the return value is ERROR_SUCCESS.

	if (result == ERROR_SUCCESS) {
		RegSetValueExA(
			hKey,			 //handle registry key
			(LPCSTR)"hello", //name
			0,				 // Reserved
			REG_SZ,			 // Type of data
			(unsigned char*)path,
			strlen(path)
		);
		RegCloseKey(hKey);
		std::cout << "Success!!!!\n";
	}
	else {
		std::cout << "Can not set the run key !!!!";
	}

	
	return 0;
}
