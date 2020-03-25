cmake_minimum_required(VERSION 3.13)
set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_INSTALLATION_ROOT}/scripts/buildsystems/vcpkg.cmake)
project(demo VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(demo
        LinkQueue.h
        BrMatch.h
        SeqStack.h
        LinkList.h
        SqList.h
        List.h
        demo.cc)

add_executable(demo1 Btree.h demo1.cc)

target_link_libraries(demo PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
add_test(Sqlist-test demo)

target_link_libraries(demo1 PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
add_test(Sqlist-test1 demo1)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
