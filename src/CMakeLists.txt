#指定头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

#引入第三方库
#find_package(sqlite3 CONFIG REQUIRED)
#find_package(SDL2 CONFIG REQUIRED)
#将cpp加入可执行文件
#add_executable(test 
#)
#target_link_libraries(test PRIVATE SDL2::SDL2 SDL2::SDL2main)
#target_link_libraries(test PRIVATE sqlite3)
#add_subdirectory("first")