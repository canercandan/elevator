CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(elevator)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src)
SET(CXX_SOURCES)
ADD_SUBDIRECTORY(src)
ADD_EXECUTABLE(${PROJECT_NAME} ${CXX_SOURCES})

EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/samples ${CMAKE_CURRENT_BINARY_DIR}/samples)
