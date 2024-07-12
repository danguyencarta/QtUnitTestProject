cmake_minimum_required(VERSION 3.10)
project(UnitTestProject)
 
# Trouver les modules Qt
find_package(Qt6 6.5 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    Quick
    Qml
    Test
)

qt_standard_project_setup(REQUIRES 6.5)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Ajouter les sous-répertoires
add_subdirectory(app)
add_subdirectory(gTests)
add_subdirectory(qtTests)

set(QML_IMPORT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/qml CACHE
    STRING
    "Path used to locate CMake modules by Qt Creator"
    FORCE)
#set(QML_IMPORT_PATH2 "${CMAKE_CURRENT_SOURCE_DIR}")
