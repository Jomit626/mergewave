cmake_minimum_required(VERSION 3.1.0)

project(mergewave VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# verilog vcd lib
execute_process(
  COMMAND make parser-srcs
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/thirdparty/verilog-vcd-parser)

set(VCD_PARSER_SOURCES
    thirdparty/verilog-vcd-parser/src/VCDFile.cpp
    thirdparty/verilog-vcd-parser/src/VCDFileParser.cpp
    thirdparty/verilog-vcd-parser/src/VCDValue.cpp
    thirdparty/verilog-vcd-parser/build/VCDScanner.cpp
    thirdparty/verilog-vcd-parser/build/VCDParser.cpp)

include_directories(thirdparty/verilog-vcd-parser/src)
include_directories(thirdparty/verilog-vcd-parser/build)

add_library(verilog-vcd-parser ${VCD_PARSER_SOURCES})

# svlang
set(SLANG_INCLUDE_TESTS off)
set(SLANG_INCLUDE_INSTALL off)

add_subdirectory(thirdparty/slang)

set_target_properties(slangruntime PROPERTIES EXCLUDE_FROM_ALL True)
set_target_properties(slangcompiler PROPERTIES EXCLUDE_FROM_ALL True)

# Qt5
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTORCC on)
set(CMAKE_AUTOUIC on)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# mergewave
aux_source_directory(src SOURCES)
add_executable(mergewave ${SOURCES})

target_link_libraries(mergewave PUBLIC Qt5::Widgets)
target_link_libraries(mergewave PUBLIC verilog-vcd-parser)
target_link_libraries(mergewave PUBLIC slangparser)

