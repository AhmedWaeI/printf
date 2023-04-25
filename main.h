#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int printstring(char* s, int len);
int printchar(char c);
unsigned long int strllen(const char* s);
void print_intt(int num);
unsigned int printbinary(unsigned int num);
#endif /* MAIN_H */
