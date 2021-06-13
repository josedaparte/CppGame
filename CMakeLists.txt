cmake_minimum_required(VERSION 3.0.0)

project(MyGame VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src/lib)

file(GLOB_RECURSE SOURCE_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} tinyPTC X11)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
