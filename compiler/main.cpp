#include <stdio.h>

#include "scanner.hpp"

int main()
{
    Scanner scanner;
    scanner_init(scanner, "a { define put \"h\"");

    printf("%d\n", scan(scanner));
    printf("%d\n", scan(scanner));
    printf("%d\n", scan(scanner));
}