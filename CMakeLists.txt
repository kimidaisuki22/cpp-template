cmake_minimum_required(VERSION 3.28.0)
set(CMAKE_C_COMPILER gcc-14)
set(CMAKE_CXX_COMPILER g++-14)
option(WITH_BENCHMARK "Build benchmarks" OFF)
if(WITH_BENCHMARK)
  list(APPEND VCPKG_MANIFEST_FEATURES "benchmark")
endif()

if(BUILD_TESTING)
  list(APPEND VCPKG_MANIFEST_FEATURES "test")
endif()

project(main VERSION 0.0.1)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

add_link_options(-fuse-ld=mold)

add_executable(main src/main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE fmt::fmt)
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(main PRIVATE spdlog::spdlog)

target_include_directories(main PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)
if(BUILD_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()
if(WITH_BENCHMARK)
  add_subdirectory(benchmark)
endif()

install(TARGETS main DESTINATION bin)
# install(TARGETS $<TARGET_RUNTIME_DLLS:main> DESTINATION bin)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_FILE_NAME update_server_package)
include(CPack)

include(GNUInstallDirs)
