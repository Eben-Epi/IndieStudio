cmake_minimum_required(VERSION 3.13)
project(bomberman)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/packages)

add_executable(
	bomberman
	main.cpp
	src/ecs/EcsCore.cpp src/ecs/EcsCore.hpp src/ecs/System.cpp src/ecs/System.hpp src/ecs/Component.cpp src/ecs/Component.hpp src/ecs/Entity.cpp src/ecs/Entity.hpp src/ecs/Exceptions.hpp src/ecs/Components/ColisionComponent.cpp src/ecs/Components/ColisionComponent.hpp src/ecs/Components/DisplayableComponent.cpp src/ecs/Components/DisplayableComponent.hpp src/ecs/Systems/CollisionSystem.cpp src/ecs/Systems/CollisionSystem.hpp src/ecs/Systems/DisplayableSystem.cpp src/ecs/Systems/DisplayableSystem.hpp)

find_package(Irrlicht)

target_link_libraries(
	bomberman
	Irrlicht
)