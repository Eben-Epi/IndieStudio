cmake_minimum_required(VERSION 3.13)
project(bomberman)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/packages)

add_executable(
	bomberman
	main.cpp
)

find_package(Irrlicht)

target_link_libraries(
	bomberman
	Irrlicht
)