cmake_minimum_required(VERSION 3.24)
project(cjvm)

set(CMAKE_CXX_STANDARD 17)

include_directories("include")
add_executable(cjvm src/main.cpp include/*/ include/classpath.h src/classpath/classpath.cpp src/classpath/composite_entry.cpp src/common/str.cpp include/file.h include/zip.h include/str.h src/common/file.cpp src/common/zip.cpp src/classpath/wildcard_entry.cpp src/classpath/jar_entry.cpp src/classpath/dir_entry.cpp src/common/system.cpp include/system.h)
