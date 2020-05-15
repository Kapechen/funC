# CMakeList.txt: learnC++ 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
# specify the C++ standard
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED True)
project ("${PROJECT_NAME}")
SET(CMAKE_TOOLCHAIN_FILE "${VCPKG_PATH}")
#指定编译目录
#set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)
include_directories(${PROJECT_SOURCE_DIR}/include)

#find_package(SDL2 CONFIG REQUIRED)
# 将源代码添加到此项目的可执行文件。
add_executable(${PROJECT_NAME} "main.cpp" "src/coordin.cpp" "src/stock2.cpp" "src/stack.cpp" "src/mytime1.cpp" "src/vect.cpp" "src/stringbad.cpp" "src/string1.cpp" "src/queue.cpp" "src/student.cpp"   "src/tv.cpp")

# TODO: 如有需要，请添加测试并安装目标。
#target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)