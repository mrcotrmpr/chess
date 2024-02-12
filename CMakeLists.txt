cmake_minimum_required(VERSION 3.20)

project(chess)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ./src/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ./include/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

add_custom_target(copy_data COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources)
add_dependencies(${PROJECT_NAME} copy_data)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
