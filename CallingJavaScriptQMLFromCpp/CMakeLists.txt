cmake_minimum_required(VERSION 3.16)

project(JavaScriptQML VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appJavaScriptQML
    ./src/main.cpp
)

qt_add_qml_module(appJavaScriptQML
    URI JavaScriptQML
    VERSION 1.0
    QML_FILES
        ./qml/Main.qml
    SOURCES
        ./include/qmljscaller.hpp
        ./src/qmljscaller.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appJavaScriptQML PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appJavaScriptQML
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(appJavaScriptQML PUBLIC ${CMAKE_SOURCE_DIR}/include/)

target_link_libraries(appJavaScriptQML
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appJavaScriptQML
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
