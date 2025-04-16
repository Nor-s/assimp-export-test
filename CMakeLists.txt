cmake_minimum_required(VERSION 3.21)

project(
  fbx_export_test
  LANGUAGES CXX
  VERSION 0.1.0)


set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MDd")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")

set(BUILD_SHARED_LIBS OFF)
option(ASSIMP_BUILD_ZLIB ON)
option(ASSIMP_BUILD_TESTS OFF)
option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
if(WIN32)
  option(ASSIMP_RAPIDJSON_NO_MEMBER_ITERATOR OFF)
  set(ASSIMP_RAPIDJSON_NO_MEMBER_ITERATOR OFF)
endif()
set(ASSIMP_BUILD_ZLIB ON)
set(ASSIMP_BUILD_TESTS OFF)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/Debug)
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/Release)


add_subdirectory(assimp/)

# mixamo export
add_executable(mixamo_export  example/mixamo/main.cpp)
target_link_libraries(mixamo_export PUBLIC assimp::assimp)

# issue 5711: https://github.com/assimp/assimp/issues/5711
add_executable(issue5711  example/issue5711/main.cpp)
target_link_libraries(issue5711 PUBLIC assimp::assimp)
