#include <windows.h>
#include <ctime>
#include <wchar.h>

DWORD WINAPI ShowMonth(LPVOID lpParam)
{
    time_t now = time(0);
    struct tm ltm;

 
    localtime_s(&ltm, &now);

 
    const wchar_t* months[] = {
        L"Січень", L"Лютий", L"Березень", L"Квітень",
        L"Травень", L"Червень", L"Липень", L"Серпень",
        L"Вересень", L"Жовтень", L"Листопад", L"Грудень"
    };

    int month = ltm.tm_mon;

    MessageBox(NULL, months[month], L"Поточний місяць", MB_OK | MB_ICONINFORMATION);

    return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HANDLE hThread;
    DWORD dwThreadId;

    hThread = CreateThread(
        NULL,       
        0,          
        ShowMonth,  
        NULL,       
        0,          
        &dwThreadId 
    );

    if (hThread == NULL)
    {
        MessageBox(NULL, L"Не вдалося створити потік", L"Помилка", MB_OK | MB_ICONERROR);
        return 1;
    }

    WaitForSingleObject(hThread, INFINITE);

    CloseHandle(hThread);

    return 0;
}

