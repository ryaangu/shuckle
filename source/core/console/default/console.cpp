#include <core/console.hpp>

#include <stdio.h>

void console_write(const char *content)
{
    printf("%s", content);
}

void console_writeln(const char *content)
{
    puts(content);
}