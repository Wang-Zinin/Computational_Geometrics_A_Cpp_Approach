cmake_minimum_required(VERSION 3.10)

project(geo)

set(CMAKE_CXX_STANDRD 11)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/geoMath.cpp
)
