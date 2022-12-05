cmake_minimum_required(VERSION 3.23)
project(TaDS_LAB3)

set(CMAKE_CXX_STANDARD 17)

add_executable(TaDS_LAB3 main.cpp Menu/MyMenu.cpp Menu/MyMenu.h Menu/MyMenuItem.cpp Menu/MyMenuItem.h Models/Errors.cpp Models/Errors.h Models/Graph.cpp Models/Graph.h)
