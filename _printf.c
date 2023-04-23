#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int printstring(char* s, int len) {
    if (write(1, s, len) == -1) {
        return -1;
    }
    return 0;
}

int printchar(char c) {
    if (write(1, &c, 1) == -1) {
        return -1;
    }
    return 0;
}

unsigned long int strlen(char* s) {
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }

    return (i);
}

int _printf(const char* const format, ...) {
    int i;
    int count = 0;
    char c;
    char* s;
    int len;
    va_list args;

    va_start(args, format);

    if (format == NULL) {
        return -1;
    }

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            if (format[i + 1] == '\0') {
                return -1; // error: incomplete format specifier
            }

            switch (format[i + 1]) {
                case 'c':
                    c = va_arg(args, int);
                    if (printchar(c) == -1) {
                        return -1; // error: failed to print char
                    }
                    count++;
                    break;
                case 's':
                    s = va_arg(args, char*);
                    len = strlen(s);
                    if (printstring(s, len) == -1) {
                        return -1; // error: failed to print string
                    }
                    count = count + len;
                    break;
                case '%':
                    if (printchar('%') == -1) {
                        return -1; // error: failed to print '%'
                    }
                    count++;
                    break;
                default:
                    return -1; // error: invalid conversion specifier
            }
            i++; // skip over conversion specifier character
        } else {
            if (printchar(format[i]) == -1) {
                return -1; // error: failed to print character
            }
            count++;
        }
    }

    va_end(args);

    return count;
}

