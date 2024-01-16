/* 
    16/1/2023: This is a small example of make a file start up with PC by copy the file in Startup folder
    shell:startup
*/


#include <iostream>
#include <fstream>
#include <windows.h>
#include <shlobj.h>
#include <cstdio>

int main() {
    // Your code to run on startup
    std::cout << "Your program is running on startup!" << std::endl;
    
    int a = getchar();


    // Get the path to the Startup folder
    TCHAR startupFolderPath[MAX_PATH];
    
    // SHGetFolderPath(...) retrieve the path to the Startup folder.
    // The CSIDL_STARTUP constant specifies the Startup folder.

    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_STARTUP, NULL, 0, startupFolderPath))) {
        // Construct the path to the executable in the Startup folder
        std::wstring startupPath = std::wstring(startupFolderPath) + L"\\YourStartupExecutable.exe";

        // Copy the executable to the Startup folder
        // Replace Project2.exe with the right name
        if (CopyFile(L"Project2.exe", startupPath.c_str(), FALSE)) {
            std::wcout << L"Executable copied to the Startup folder: " << startupPath << std::endl;
        }
        else {
            std::cerr << "Failed to copy executable to the Startup folder." << std::endl;
        }
    }
    else {
        std::cerr << "Failed to get the path to the Startup folder." << std::endl;
    }

    return 0;
}
