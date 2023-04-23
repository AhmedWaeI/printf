#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
int _printf(const char *format, ...);
int printstring(char* s, int len);
int printchar(char c);
unsigned long int strlen(char* s);
#endif
