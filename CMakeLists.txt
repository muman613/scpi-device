cmake_minimum_required(VERSION 3.16.3)

project(ARGUS-DEV)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_OSX_ARCHITECTURES "x86_64")

# Disable rpath modification on installation (https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_RPATH_USE_LINK_PATH.html)
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core DBus Sql Quick Charts Svg SerialPort Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core DBus Sql Quick Charts Svg SerialPort Test REQUIRED)

find_package(Threads)
find_package(PkgConfig REQUIRED)

add_subdirectory(lib)

