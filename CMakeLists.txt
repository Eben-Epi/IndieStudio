cmake_minimum_required(VERSION
	3.13)
project(bomberman)

set(CMAKE_CXX_STANDARD
	11)
set(CMAKE_MODULE_PATH
	${PROJECT_SOURCE_DIR}/packages)

add_executable(
	bomberman
	main.cpp
	src/ecs/ECSCore.cpp
	src/ecs/ECSCore.hpp
	src/ecs/System.cpp
	src/ecs/System.hpp
	src/ecs/Component.cpp
	src/ecs/Component.hpp
	src/ecs/Entity.cpp
	src/ecs/Entity.hpp
	src/ecs/Exceptions.hpp
	src/ecs/Components/BombDropperComponent.cpp
	src/ecs/Components/BombDropperComponent.hpp
	src/ecs/Components/BreakableComponent.cpp
	src/ecs/Components/BreakableComponent.hpp
	src/ecs/Components/DirectionComponent.cpp
	src/ecs/Components/DirectionComponent.hpp
	src/ecs/Components/DisplayableComponent.cpp
	src/ecs/Components/DisplayableComponent.hpp
	src/ecs/Components/HealthComponent.cpp
	src/ecs/Components/HealthComponent.hpp
	src/ecs/Components/ItemContainerComponent.cpp
	src/ecs/Components/ItemContainerComponent.hpp
	src/ecs/Components/KickableComponent.cpp
	src/ecs/Components/KickableComponent.hpp
	src/ecs/Components/KickerComponent.cpp
	src/ecs/Components/KickerComponent.hpp
	src/ecs/Components/MovableComponent.cpp
	src/ecs/Components/MovableComponent.hpp
	src/ecs/Components/PositionComponent.cpp
	src/ecs/Components/PositionComponent.hpp
	src/ecs/Components/PowerUpComponent.cpp
	src/ecs/Components/PowerUpComponent.hpp
	src/ecs/Components/CollisionComponent.cpp
	src/ecs/Components/CollisionComponent.hpp
	src/ecs/Systems/CollisionSystem.cpp
	src/ecs/Systems/CollisionSystem.hpp
	src/ecs/Systems/DisplayableSystem.cpp
	src/ecs/Systems/DisplayableSystem.hpp
	src/ecs/data/Directions.hpp
	src/ecs/data/Vector2.hpp
	src/ecs/Factories/EntityFactory.cpp
	src/ecs/Factories/EntityFactory.hpp
	src/ecs/Factories/SystemFactory.cpp
	src/ecs/Factories/SystemFactory.hpp
	src/ecs/Ressources.hpp
	src/map/Map.hpp
	src/map/Map.cpp)

find_package(Irrlicht REQUIRED)

target_link_libraries(
	bomberman
	Irrlicht
)

