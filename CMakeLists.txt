cmake_minimum_required(VERSION 3.13)
project(LearnOpenGL)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
set(CMAKE_CXX_STANDARD 17)

# Including GLAD
include_directories(glad/include)
set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")

set(SOURCE_FILES main.cpp glad/src/glad.c Shapes/Shape.h Shapes/Triangle.cpp Shapes/Triangle.h Shapes/Shape.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

# Linking GLFW and OGL
target_link_libraries(${CMAKE_PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARY})