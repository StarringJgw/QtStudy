cmake_minimum_required(VERSION 3.12)
project(QtClion)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

LINK_LIBRARIES(${QT_QTMAIN_LIBRARY})
add_executable(QtClion WIN32 main.cpp mainwindow.h mainwindow.cpp)

target_link_libraries(QtClion Qt5::Core)
target_link_libraries(QtClion Qt5::Widgets)