cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(mathlab)

find_package(glfw3 3.3 REQUIRED)
find_package(glew 2.2.0 REQUIRED)
find_package(OpenGL REQUIRED)

SET(LIBS glfw OpenGL::GL glew)


include_directories(${CMAKE_SOURCE_DIR}/src/data)

file(GLOB_RECURSE SOURCE_FILES
	${CMAKE_SOURCE_DIR}/src/*.c
	${CMAKE_SOURCE_DIR}/src/*.cpp)

## Add header files
file(GLOB_RECURSE HEADER_FILES
	${CMAKE_SOURCE_DIR}/src/*.h
	${CMAKE_SOURCE_DIR}/src/*.hpp)

add_executable(main ${HEADER_FILES} ${SOURCE_FILES})
#add_executable(main ./src/main.cpp ./src/scene/scene.cpp ./src/shader/shader.cpp)

target_link_libraries(main ${LIBS})
