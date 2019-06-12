#
# A CMake module to find pthread for the project B-YEP-400 IndieStudio
#
# This CMake module is designed to work on Fedora28 and Windows10. We will not
# provide support for other distributions. We will use this module to compile
# your project during our tests.
#
# You must provide the path to this module to CMake by setting
# CMAKE_MODULE_PATH variable to its location.
#
# Once done this module will define:
#  pthread_FOUND - system has pthread
#  pthread_INCLUDE_DIRS - the pthread include directory
#  pthread_LIBRARIES - Link these to use pthread
#
# Author: Guillaume DEVOILLE <guillaume1.devoille@epitech.eu> (17/05/2019)
#

IF (NOT Pthread_LIBRARIES)

    IF (MSVC)     # Windows
        SET(CMAKE_FIND_LIBRARY_PREFIXES "")
        SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
    ELSE (MSVC)   # Linux
        SET(CMAKE_FIND_LIBRARY_PREFIXES "lib")
        SET(CMAKE_FIND_LIBRARY_SUFFIXES ".so")
    ENDIF(MSVC)

    FIND_LIBRARY(Pthread_LIBRARIES
        NAMES
            pthread
        PATHS
            /usr/lib64/                   # Default Fedora28 library path
            /usr/lib/                     # Some more Linux library path
            /usr/lib/x86_64-linux-gnu/    # Some more Linux library path
            /usr/local/lib/               # Some more Linux library path
            /usr/local/lib64/             # Some more Linux library path
            ${CMAKE_MODULE_PATH}/         # Expected to contain the path to this file for Windows10
            ${Pthread_DIR}/               # pthread root directory (if provided)
    )
ENDIF (NOT Pthread_LIBRARIES)

IF (Pthread_LIBRARIES)
    SET(Pthread_FOUND TRUE)
ELSE (Pthread_LIBRARIES)
    SET(Pthread_FOUND FALSE)
ENDIF (Pthread_LIBRARIES)

IF (Pthread_FIND_REQUIRED AND NOT Pthread_FOUND)
    MESSAGE(FATAL_ERROR
            "  pthread not found.\n"
            "      Windows: Fill CMake variable Pthread_DIR to the provided directory.\n"
            "      Linux: Install pthread using your package manager ($> sudo dnf install pthread).\n"
            )
ENDIF (Pthread_FIND_REQUIRED AND NOT Pthread_FOUND)
