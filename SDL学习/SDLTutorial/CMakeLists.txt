cmake_minimum_required(VERSION 3.17)
project(SDLTutorial)

set(CMAKE_CXX_STANDARD 14)
set(SDL2_INC_DIR /usr/include/SDL2)
set(SDL2_LINK_DIR /usr/local/lib)
set(SDL2_IMAGE_LINK_DIR /usr/lib/x86_64-linux-gnu)

include_directories(${SDL2_INC_DIR})
link_directories(${SDL2_LINK_DIR} ${SDL2_IMAGE_LINK_DIR})
link_libraries(SDL2)
link_libraries(SDL2_image)

add_executable(SDLTutorial main.cpp)