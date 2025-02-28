# 设置最小 CMake 版本
cmake_minimum_required(VERSION 3.10)

# 设置项目名称和支持的语言
project(UDP C CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加库文件
add_library(mylib STATIC src/libCodeTest.cpp)

# 添加可执行文件
add_executable(main src/main.cpp)
                    # src/libCodeTest.cpp)

# 链接库文件到可执行文件
target_link_libraries(main mylib)

# 包含头文件目录
target_include_directories(main PRIVATE include)

# 指定共享库的位置
set(MYLIB_PATH "${CMAKE_SOURCE_DIR}/lib/libVDMocapSDK_dataRead.so")

# 链接共享库到可执行文件
target_link_libraries(main ${MYLIB_PATH})