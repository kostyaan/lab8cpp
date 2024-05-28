#include <windows.h>
#include <string>

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    const wchar_t* message = static_cast<const wchar_t*>(lpParameter);
    MessageBox(NULL, message, L"Повідомлення", MB_OK | MB_ICONERROR);
    return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    const wchar_t* messages[5] = {
        L"Черепанов Костянтин Михайлович - Повідомлення 1",
        L"Черепанов Костянтин Михайлович - Повідомлення 2",
        L"Черепанов Костянтин Михайлович - Повідомлення 3",
        L"Черепанов Костянтин Михайлович - Повідомлення 4",
        L"Черепанов Костянтин Михайлович - Повідомлення 5",
    };

    HANDLE threads[5];
    for (int i = 0; i < 5; ++i)
    {
        threads[i] = CreateThread(
            NULL,                 
            0,                    
            ThreadProc,           
            (LPVOID)messages[i],  
            0,                    
            NULL                          );

        if (threads[i] == NULL)
        {
            MessageBox(NULL, L"Не вдалося створити потік", L"Помилка", MB_OK | MB_ICONERROR);
            return 1;
        }
    }

     WaitForMultipleObjects(5, threads, TRUE, INFINITE);

    for (int i = 0; i < 5; ++i)
    {
        CloseHandle(threads[i]);
    }

    return 0;
}
