cmake_minimum_required(VERSION 3.24)
project(cjvm)

set(CMAKE_CXX_STANDARD 17)

include_directories("include")
add_executable(cjvm src/main.cpp include/*/ include/classpath.h src/classpath/classpath.cpp src/classpath/composite_entry.cpp)
