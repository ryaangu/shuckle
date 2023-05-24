#ifndef COMPILER_SOURCE_FILE_HPP
#define COMPILER_SOURCE_FILE_HPP

#include <core/list.hpp>

#include <compiler/diagnostic.hpp>

struct SourceFile
{
    List<Diagnostic> diagnostics;

    // Initialize The Source File
    void init(const char *path);
};

#endif