#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    const wchar_t* message = L"Черепанов Костянтин Михайлович";

    for (int i = 0; i < 5; ++i)
    {
        MessageBox(NULL, message, L"Повідомлення", MB_OK | MB_ICONINFORMATION);
    }

    return 0;
}
