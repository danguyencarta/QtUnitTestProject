pipeline {
    agent {
        label 'cartawash-test-win'
    }
    environment {
        JENKINS_PATH = "\"C:\\jenkins\\workspace\\QtUnitTestProject\\GoogleTest\""
        QT_PATH = "\"C:\\Qt\""
		CMAKE_PATH = "\"C:\\Qt\\Tools\\CMake_64\\bin\\cmake.exe\""
        NINJA_PATH = "\"C:\\Qt\\Tools\\Ninja\\ninja.exe\""
        DEPLOY_WIN_PATH = "\"C:\\Qt\\6.5.3\\mingw_64\\bin\\windeployqt.exe\""
    }
    stages {
        stage("Checkout") {
            steps {
                bat 'if not exist QtUnitTestProject mkdir QtUnitTestProject'
                bat 'echo %Path%'
                
                dir("QtUnitTestProject") {
                    script {
                        def scmVars = checkout([
                            $class: 'GitSCM', 
                            branches: [[name: "main"]], 
                            userRemoteConfigs: [[url: 'https://github.com/danguyencarta/QtUnitTestProject.git']]
                        ])
                    }
                }
            }
                  
            post {
                success {echo 'checkout agent was done successfully'}
                failure {echo 'There is a problem in QtUnitTestProject checkout'}
            }
        }
        stage("Prepare build directory") {
            steps {
                bat 'if not exist build-unitTestProject mkdir build-unitTestProject'
                bat 'if not exist build-unitTestProject\\.qtc mkdir build-unitTestProject\\.qtc'
                bat 'if not exist build-unitTestProject\\.qtc\\package-manager xcopy QtUnitTestProject\\.qtc build-unitTestProject\\.qtc /e'
            }
            post {
                success {echo 'Prepare build directory was done successfully'}
                failure {echo 'There is a problem in prepare build directory'}
            }
        }
        stage("Run cmake") {
            steps {
                withEnv(["PATH+MINGW=C:\\Qt\\Tools\\mingw1310_64\\bin"]) {
                    bat '%CMAKE_PATH% -S %JENKINS_PATH%/QtUnitTestProject -B %JENKINS_PATH%/build-unitTestProject "-DCMAKE_GENERATOR:STRING=Ninja" "-DCMAKE_MAKE_PROGRAM:FILEPATH=%NINJA_PATH%" "-DCMAKE_BUILD_TYPE:STRING=Debug" "-DCMAKE_PROJECT_INCLUDE_BEFORE:FILEPATH=%JENKINS_PATH%/build-unitTestProject/.qtc/package-manager/auto-setup.cmake" "-DQT_QMAKE_EXECUTABLE:FILEPATH=%QT_PATH%/6.5.3/mingw_64/bin/qmake.exe" "-DCMAKE_PREFIX_PATH:PATH=%QT_PATH%/6.5.3/mingw_64" "-DCMAKE_C_COMPILER:FILEPATH=%QT_PATH%/Tools/mingw1310_64/bin/gcc.exe" "-DCMAKE_CXX_COMPILER:FILEPATH=%QT_PATH%/Tools/mingw1310_64/bin/g++.exe" "-DCMAKE_CXX_FLAGS_INIT:STRING="'
                }
            }
            post {
                success {echo 'Run cmake was done successfully'}
                failure {echo 'There is a problem in run cmake'}
            }
        }
        stage("Build") {
            steps {
                withEnv(["PATH+MINGW=C:\\Qt\\Tools\\mingw1310_64\\bin"]) {
                    bat '%CMAKE_PATH% --build build-unitTestProject'
                }
            }
            post {
                success {echo 'Build successfully'}
                failure {echo 'There is a problem in build'}
            }
        }
        stage("Deploy") {
            steps {
                bat '%DEPLOY_WIN_PATH% build-unitTestProject --test --quicktest --widgets'
            }
            post {
                success {echo 'Deploy successfully'}
                failure {echo 'There is a problem in deploy'}
            }
        }
        stage("Run gTest") {
            steps {
                catchError(buildResult: 'SUCCESS', stageResult: 'UNSTABLE') {
                    dir("build-unitTestProject") {
                        bat 'gTests --gtest_output=xml:gtests_results.xml'
                        // bat 'unittest -o qttest_results.xml -junitxml'
                    }
                }
            }
            post {
                always {
                    step([
                            $class              : 'JUnitResultArchiver',
                            testResults         : 'build-unitTestProject/gtests_results.xml',
                    ])
                }
                success {echo 'Run gTests successfully'}
                failure {echo 'There is a problem in running gTests'}
            }
        }
        stage("Run qtTest") {
            steps {
                catchError(buildResult: 'SUCCESS', stageResult: 'UNSTABLE') {
                    dir("build-unitTestProject") {
                        bat 'unittest -o qttest_results.xml -junitxml'
                    }
                }
            }

            post {
                always {
                    step([
                            $class              : 'JUnitResultArchiver',
                            testResults         : 'build-unitTestProject/qttest_results.xml',
                    ])
                }
                success {echo 'Run tests successfully'}
                failure {echo 'There is a problem in running tests'}
            }
        }
    }
}