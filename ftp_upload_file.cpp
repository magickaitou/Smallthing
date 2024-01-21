#include <windows.h>
#include <strsafe.h>
#include <wininet.h>
#include <iostream>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "user32.lib")

void FileSubmit()
{
    HINTERNET hInternet;
    HINTERNET hFtpSession;
    hInternet = InternetOpen(NULL, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (hInternet == NULL)
    {
        std::cout << "Error: " << GetLastError();
    }
    else
    {
        hFtpSession = InternetConnect(hInternet, (LPCWSTR)L"127.0.0.1", INTERNET_DEFAULT_FTP_PORT, (LPCWSTR)L"ftpuser", (LPCWSTR)L"1", INTERNET_SERVICE_FTP, 0, 0);
        if (hFtpSession == NULL)
        {
            std::cout << "Error at session: " << GetLastError();
        }
        else
        {
            if (!FtpPutFile(hFtpSession, (LPCWSTR)L"C:\\Users\\lynt1\\Downloads\\b.txt", (LPCWSTR)L"b.txt", FTP_TRANSFER_TYPE_BINARY, 0))
            {
                std::cout << "Error at put file: " << GetLastError();
            }
            else {
                std::cout << "Success!!! \n";
            }
        }
    }


}

int main() {
    FileSubmit();
    return 0;
}
