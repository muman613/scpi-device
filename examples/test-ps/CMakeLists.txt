project(test-ps VERSION 1.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ../../lib)
target_link_libraries(${PROJECT_NAME} scpi-lib)