cmake_minimum_required(VERSION 2.8)
project(G52CPP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_definitions(-std=c++11)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${G52CPP_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})
# Need to check this works for me personally
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

add_compile_options(-fsanitize=undefined)
add_link_options(-fsanitize=undefined) 
# Nedd to check this works for me personally 


set(SOURCE_FILES 

# NEEDED TO MAKE ENGINE WORK
src/mainfunction.cpp 
src/BaseEngine.cpp
src/DisplayableObject.cpp
src/DrawingSurface.cpp
src/FontManager.cpp
src/SimpleImage.cpp
src/TileManager.cpp
# NEEDED TO MAKE ENGINE WORK

# My code
ProjectSrc/cw1_main.cpp
ProjectSrc/Bird.cpp
ProjectSrc/TileMap.cpp
ProjectSrc/Pipe.cpp
ProjectSrc/PipePair.cpp
# My code
)

add_executable(SDL2_App ${SOURCE_FILES})
target_link_libraries(SDL2_App ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY})

add_custom_command(TARGET SDL2_App PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${G52CPP_SOURCE_DIR}/src/resources ${CMAKE_CURRENT_BINARY_DIR})






