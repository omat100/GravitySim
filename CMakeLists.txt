cmake_minimum_required(VERSION 3.28)
project(GravitySim)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:/Users/user/dev/SFML-2.6.1/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(GravitySim src/main.cpp)

target_link_libraries(GravitySim sfml-graphics sfml-window sfml-system)