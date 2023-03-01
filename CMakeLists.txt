cmake_minimum_required(VERSION 3.22)
project(GameEngine)

set(CMAKE_CXX_STANDARD 14)

file(GLOB APP_SOURCES */*.cpp)
foreach (testsourcefile ${APP_SOURCES})
    get_filename_component(testname ${testsourcefile} NAME_WLE)
    get_filename_component(dirname ${testsourcefile} DIRECTORY)
    file(GLOB dir_src CONFIGURE_DEPENDS
            "${dirname}/*.h"
            "${dirname}/*.cpp"
            )
    message("${testname}.cpp | ${dir_src}")
    add_executable("${testname}.cpp" ${dir_src})
endforeach (testsourcefile ${APP_SOURCES})

#add_executable(GameEngine ${helloworld_SRC})
add_executable(GameEngine ${APP_SOURCES})
#include_directories(Game)


# --- SDL2 SETUP ---
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
set(SDL2_IMAGE_PATH "SDL2/x86_64-w64-mingw32")
find_package(SDL2_image REQUIRED)
target_link_libraries(GameEngine ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
