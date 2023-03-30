# Compiling and running

Go to the build directory (where this file is located), clear its contents (if there is any) and run

``cmake ../ && make && ./SDL2_App``

if this doesn't work, try

``cmake . && make && ./SDL2_App``

Either one should work


**Note:** Memory errors found in this are from the possible following:

- SDL in combination with Linux

- Nvidia drivers (SDL is using OpenGL by default)

In this current project there is no memory errors relating to my code, that I know of. All of the errors seem to relate to linux library calls or "unkown modules" which makes it all very ambigous.

This project has not been compiled on mac or windows and has no support directly for compiling using visual studio. You **NEED** to use cmake to compile this project