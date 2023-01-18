cmake_minimum_required(VERSION 3.7)

project(project VERSION 0.0.1 LANGUAGES CXX)

add_executable(project
        main.cpp
        gl_interop.h
        geometry.h
        linear_algebra.h
        camera.cpp
        camera.h
        user_interaction.h
        Scene.cpp
        Scene.h
        )
target_link_libraries(project
    -lGLEW -lGL -lGLU -lglut -lpthread -lm -lOpenCL
        sfml-graphics sfml-window sfml-system
)

find_package(OpenCL REQUIRED)
target_link_libraries(project OpenCL::OpenCL)
find_package(GLEW REQUIRED)
target_link_libraries(project GLEW::GLEW)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/opencl_kernel.cl ${CMAKE_CURRENT_BINARY_DIR}/opencl_kernel.cl COPYONLY)
