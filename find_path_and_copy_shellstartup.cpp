/* 
    17/1/2024

    This code is used to find the exe path and copy file to the roaming 
    shell:startup
    window only :) 

*/


#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#endif

std::wstring getExecutablePath() {
#ifdef _WIN32
    wchar_t buffer[MAX_PATH];
    GetModuleFileNameW(NULL, buffer, MAX_PATH);
    return buffer;
#elif __linux__
    // Linux implementation (you may need to implement this)
    // This is just a placeholder
    return L"";
#endif
}

int main() {
    std::wstring executablePath = getExecutablePath();

    if (!executablePath.empty()) {
        std::wcout << L"Executable Path: " << executablePath << std::endl;

#ifdef _WIN32
        // Get the path to the Startup folder
        wchar_t startupFolderPath[MAX_PATH];

        if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_STARTUP, NULL, 0, startupFolderPath))) {
            // Construct the path to the executable in the Startup folder
            std::wstring startupPath = std::wstring(startupFolderPath) + L"\\YourStartupExecutable2.exe";

            // Copy the executable to the Startup folder
            if (CopyFile(executablePath.c_str(), startupPath.c_str(), FALSE)) {
                std::wcout << L"Executable copied to the Startup folder: " << startupPath << std::endl;
            }
            else {
                std::cerr << "Failed to copy executable to the Startup folder." << std::endl;
            }
        }
        else {
            std::cerr << "Failed to get the path to the Startup folder." << std::endl;
        }
#endif
    }
    else {
        std::cerr << "Failed to retrieve executable path." << std::endl;
    }


    std::cout << "Helloworld";
    getchar();

    return 0;
}
