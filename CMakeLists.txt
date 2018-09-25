cmake_minimum_required(VERSION 3.12)
project(ProgressBarLab)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(wxWidgets REQUIRED net gl core base xrc adv)
include(${wxWidgets_USE_FILE})

add_subdirectory(test)

set(SOURCE_FILES Observer.h Subject.h Model.cpp Model.h View.cpp View.h ScrolledPanel.h)
add_executable(ProgressBarLab main.cpp )
add_library(core ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_link_libraries(${PROJECT_NAME} core)