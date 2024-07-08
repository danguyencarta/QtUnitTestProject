cmake_minimum_required(VERSION 3.16)
project(gTests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(Qt6 6.5 REQUIRED COMPONENTS
    Core
)

find_package(Python3)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SOURCES
    testclass1test.cpp
    testclass2test.cpp
)

# set(HEADERS
#     test.h
# )

set(QT_LIB
    Qt6::Core
    Qt6::Quick
    Qt6::Gui
    Qt6::Widgets
    Qt6::Qml
)

add_executable(gTests
    ${SOURCES}
    main.cpp
    # ${HEADERS}
)

add_test(NAME gTests COMMAND gTests --gtest_color=yes)

target_link_libraries(gTests PRIVATE
    TestAppLib
    TestAppLibplugin
    GTest::gtest_main
    Qt6::Core
)

include(GoogleTest)
gtest_discover_tests(gTests DISCOVERY_MODE PRE_TEST)
