cmake_minimum_required(VERSION 3.16)

project(TestApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    Quick
    Qml
)

set(SOURCES
    testclass1.cpp
    testclass2.cpp
)

set(HEADERS
    testclass1.h
    testclass2.h
)

set(QML_FILES
    qml/Main.qml
    qml/MyButton.qml
)

set(QT_LIB
    Qt6::Core
    Qt6::Quick
    Qt6::Gui
    Qt6::Widgets
    Qt6::Qml
)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(TestApp
    main.cpp
    #Main.qml
)

qt_add_library(TestAppLib STATIC)

qt_add_qml_module(TestApp
    URI TestApp
    VERSION 1.0
    QML_FILES ${QML_FILES}
    SOURCES ${SOURCES}
    SOURCES ${HEADERS}
)

qt_add_qml_module(TestAppLib
    URI "TestAppLib"
    VERSION 1.0
    QML_FILES ${QML_FILES}
    SOURCES ${SOURCES}
    SOURCES ${HEADERS}
)

target_include_directories(TestAppLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(TestAppLib
    PUBLIC
    ${QT_LIB}
)

target_link_libraries(TestApp
    PRIVATE
    ${QT_LIB}
)

include(GNUInstallDirs)

install(TARGETS TestApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
