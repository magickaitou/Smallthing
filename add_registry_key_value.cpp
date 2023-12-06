/*
	this code is used to add persistent key window so make Prokect2.exe start up with PC
	Persistent key: "HKCU:\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"

	Workflow:
		Open Registry Key 
		If Success => Set value => Close handle 
*/


#include <iostream>
#include <windows.h>
#include <string.h>

int main() {
	const char* path = "C:\\Users\\lynt1\\OneDrive\\Desktop\\Project2.exe";
	const char* subkey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";

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
	}
	return 0;
}
