cmake_minimum_required(VERSION 3.16)

project(TZE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(TZE
    Engine/Core/Main.cpp
    Engine/Core/Engine.cpp
    Engine/Core/Time.cpp
    Engine/Math/Vector2.cpp
    Engine/Math/Vector3.cpp
    Engine/Math/Matrix4.cpp
    Engine/Game/Player.cpp
)