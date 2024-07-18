cmake_minimum_required(VERSION 3.18)
project(gTests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(APP_NAME unitTestApp)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

enable_testing()

find_package(Qt6 6.5 REQUIRED COMPONENTS
    Core
    Quick
)


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

set(QT_LIB
    Qt6::Core
    Qt6::Quick
    Qt6::Gui
    Qt6::Widgets
)

add_executable(gTests
    ${SOURCES}
    main.cpp
)

add_test(NAME gTests COMMAND gTests --gtest_output=xml:gtests_output.xml)

target_link_libraries(gTests PRIVATE
    TestAppLib
    #TestAppLibplugin
    Qt6::Quick
    GTest::gtest_main
    GTest::gtest
)

set(TARGET_TEST_DIR /data/local/tmp/gTests) # Directory on device to push tests.
set(TARGET_TEST_LIB_DIR ${TARGET_TEST_DIR}/${ANDROID_ABI})
    message("ANDROID_SDK_ROOT: ${ANDROID_SDK_ROOT}")

find_program(ADB NAMES adb PATHS ${ANDROID_SDK_ROOT}/platform-tools) # Verified to be working on Linux.

# add_custom_command(TARGET gTests POST_BUILD
#         COMMAND ${ADB} shell mkdir -p ${TARGET_TEST_LIB_DIR}

#         # Push libraries

#         COMMAND ${ADB} push $<TARGET_FILE:gTests> ${TARGET_TEST_LIB_DIR}
#         COMMAND ${ADB} push $<TARGET_FILE:TestAppLib> ${TARGET_TEST_LIB_DIR}
#         COMMAND ${ADB} push $<TARGET_FILE:Qt6::Quick> ${TARGET_TEST_LIB_DIR}
#         COMMAND ${ADB} push $<TARGET_FILE:Qt6::QmlModels> ${TARGET_TEST_LIB_DIR}
#         COMMAND ${ADB} push $<TARGET_FILE:Qt6::OpenGL> ${TARGET_TEST_LIB_DIR}
#         COMMAND ${ADB} push $<TARGET_FILE:Qt6::Network> ${TARGET_TEST_LIB_DIR}
#         COMMAND ${ADB} push $<TARGET_FILE:Qt6::Widgets> ${TARGET_TEST_LIB_DIR}
#         COMMAND ${ADB} push $<TARGET_FILE:Qt6::Gui> ${TARGET_TEST_LIB_DIR}
#         COMMAND ${ADB} push $<TARGET_FILE:Qt6::Core> ${TARGET_TEST_LIB_DIR}
#         COMMAND ${ADB} push $<TARGET_FILE:Qt6::OpenGL> ${TARGET_TEST_LIB_DIR}
#         COMMAND ${ADB} push ${CMAKE_CURRENT_BINARY_DIR}/android-build/build/intermediates/merged_native_libs/debug/out/lib/x86_64/libc++_shared.so ${TARGET_TEST_LIB_DIR}
#         COMMAND ${ADB} root
#         COMMAND ${ADB} shell \"chmod 777 ${TARGET_TEST_LIB_DIR}/gTests\"

#         # Execute tests

#         # FIXME What's correct: Build is stopped, if tests failed.
#         # What's to fix: Next build, if no files changed, will not execute and tests will not run, i.e. untested apk will be installed.
#         # Note: Sometimes desired logic is working. Sometimes not.
#         COMMAND ${ADB} shell \"export LD_LIBRARY_PATH=${TARGET_TEST_LIB_DIR}\; .${TARGET_TEST_LIB_DIR}/gTests\")

if(ANDROID)
    set(QT_ANDROID_APP_NAME ${APP_NAME})
    # define the application package name
    set(QT_ANDROID_APP_PACKAGE_NAME com.cartadis.${APP_NAME})

    # define the target SDK version
    set(QT_ANDROID_APP_VERSION_CODE 21)

    # define project version
     set(QT_ANDROID_APP_VERSION ${PROJECT_VERSION})

    # Set template
    set(QT_ANDROID_MANIFEST_TEMPLATE "${PARENT_DIR}/AndroidManifest.xml.in")

    configure_file(${QT_ANDROID_MANIFEST_TEMPLATE} ${CMAKE_CURRENT_SOURCE_DIR}/android/AndroidManifest.xml @ONLY)
    #Copy manifest file to apk @todo ignore for emulator
    set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY
        QT_ANDROID_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/android
    )
endif()

include(GoogleTest)
gtest_discover_tests(gTests
    DISCOVERY_MODE PRE_TEST
)
