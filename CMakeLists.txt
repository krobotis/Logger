cmake_minimum_required (VERSION 3.8)

project(Logger)

add_library(Logger STATIC
    include/logger/Logger.h
	src/Logger.cpp
)

include (GenerateExportHeader)          

GENERATE_EXPORT_HEADER(Logger           # generates the export header Logger_EXPORTS.h automatically
    BASE_NAME Logger
    EXPORT_MACRO_NAME Logger_EXPORT
    EXPORT_FILE_NAME Logger_EXPORTS.h
    STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC
)

target_include_directories(Logger PUBLIC
    include
    ${CMAKE_CURRENT_BINARY_DIR}         # for Logger_EXPORTS.h
)

option(LOGGER_BUILD_EXAMPLE "Build the example of Logger." ON)
if (LOGGER_BUILD_EXAMPLE)
    add_executable(Logger_example examples/main.cpp)
    target_link_libraries (Logger_example PRIVATE Logger)
endif ()