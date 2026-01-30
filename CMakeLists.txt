cmake_minimum_required(VERSION 3.20)
project(bininfer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES src/main.cpp)
set(CMAKE_BUILD_TYPE Debug)

add_executable(meow
	src/main.cpp
)

target_compile_options(meow PRIVATE
	-Wall 
	-Wextra 
	-Wpedantic
	-Wshadow 
	-Wconversion 
	-Wsign-conversion
	-Wnull-dereference 
	-Wdouble-promotion
	-Wformat=2
	-Walloca
	-g
	-fsanitize=address,undefined
	#-Werror (is good for pain ig..)
)

target_link_options(meow PRIVATE
	-fsanitize=address,undefined
)
