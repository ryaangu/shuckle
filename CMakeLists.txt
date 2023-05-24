# Setup CMake
CMAKE_MINIMUM_REQUIRED (VERSION 3.5.2)

# Setup Project
PROJECT (Shuckle)

# Gather Sources
FILE (GLOB
    SOURCES

    "source/core/console/default/*.cpp"
    "source/core/memory/default/*.cpp"
    "source/compiler/*.cpp"
    "source/core/*.cpp"
    "source/*.cpp"
)

# Inlcude Directories
INCLUDE_DIRECTORIES ("source")

# Add Target
ADD_EXECUTABLE (shuckle ${SOURCES})