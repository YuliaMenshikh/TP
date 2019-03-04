cmake_minimum_required(VERSION 2.8)
project(TestCMake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURSES_LIST C/main.cpp C/main.h)

execute_process(COMMAND python A/preparing.py)

add_subdirectory(B)

add_executable(${PROJECT_NAME} ${SOURSES_LIST})

target_link_libraries(${PROJECT_NAME} Lib)