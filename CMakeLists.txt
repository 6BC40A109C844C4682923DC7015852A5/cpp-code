cmake_minimum_required(VERSION 3.13)
set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_INSTALLATION_ROOT}/scripts/buildsystems/vcpkg.cmake)
project(demo VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(Sqlist sq_main.cc)

target_link_libraries(demo1 PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
add_test(Sqlist-test Sqlist)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
