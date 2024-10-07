project(scpi-lib VERSION 1.0 LANGUAGES CXX)

add_library(${PROJECT_NAME} scpi_device.cpp scpi_device.h)
target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::SerialPort)

