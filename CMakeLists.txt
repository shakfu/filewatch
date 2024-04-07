cmake_minimum_required(VERSION 3.19)

project(filewatch_project
        VERSION 0.1.0
        DESCRIPTION "lightweight macOS filewatcher"
        HOMEPAGE_URL "https://github.com/shakfu/filewatch"
        LANGUAGES C CXX)

option(C74_BUILD_FAT "Build Universal Externals")

message(STATUS "CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")

if(C74_BUILD_FAT)
    set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE STRING "macOS architecture" FORCE)
else()
    set(CMAKE_OSX_ARCHITECTURES ${CMAKE_SYSTEM_PROCESSOR} CACHE STRING "macOS architecture" FORCE)
endif()
message("CMAKE_OSX_ARCHITECTURES set to ${CMAKE_OSX_ARCHITECTURES}")



add_executable(watcher
    fswait.c
    main.c
)

target_compile_options(watcher
    PUBLIC
    -g
)

target_link_libraries(watcher
    PUBLIC
    "-framework CoreServices"
)
