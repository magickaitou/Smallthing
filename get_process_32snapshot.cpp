#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <iostream>

DWORD EnumProcess() {
    HANDLE snap;
    PROCESSENTRY32 pe;
    DWORD pid = 0;

    snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) {
        return GetLastError();
    }

    pe.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(snap, &pe)) {
        CloseHandle(snap);
        return GetLastError();
    }

    do {
        std::wcout << L"Process Name: " << pe.th32ProcessID << L"      Name: " << pe.szExeFile << std::endl;
    } while (Process32Next(snap, &pe));

    CloseHandle(snap);

    return NO_ERROR;
}

int main() {
    EnumProcess();
    return NO_ERROR;
}
