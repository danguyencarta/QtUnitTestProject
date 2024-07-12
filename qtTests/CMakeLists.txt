cmake_minimum_required(VERSION 3.5)

project(unitTest LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
enable_testing()

add_definitions(-DQUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

find_package(Qt6 6.5 REQUIRED COMPONENTS
    Core
    Quick
    Qml
    Test
    QuickTest
)

qt_standard_project_setup(REQUIRES 6.5)

set(SOURCES
    tst_main.cpp
    tst_testclass1.cpp
    tst_testclass2.cpp

)

set(HEADERS
    tst_testclass1.h
    tst_testclass2.h

)

set(QML_FILES
    tst_testCase1.qml
    tst_testCase2.qml
)



qt_add_executable(unitTest
    tst_main.cpp
)

qt_add_qml_module(unitTest
    URI untitled
    VERSION 1.0
    QML_FILES ${QML_FILES}
    SOURCES
    ${SOURCES}
    ${HEADERS}
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_test(NAME unitTest COMMAND unitTest)

target_link_libraries(unitTest PRIVATE
    TestAppLib
    TestAppLibplugin
    Qt6::QuickTest
    Qt6::Test
    Qt6::Core
    Qt6::Qml
)

include(GNUInstallDirs)
