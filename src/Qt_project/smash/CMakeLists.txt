cmake_minimum_required(VERSION 3.1.0)

project(Smash VERSION 1.0 LANGUAGES CXX)
file(GLOB source_files *.h *.c *.cpp *.qrc)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_PREFIX_PATH "C:/Qt/5.15.1/mingw81_64/lib/cmake")
find_package(Qt5 COMPONENTS widgets REQUIRED)
find_package(Qt5 COMPONENTS gui REQUIRED)
find_package(Qt5 COMPONENTS core REQUIRED)
find_package(Qt5 COMPONENTS multimedia REQUIRED)
find_package(Qt5 COMPONENTS multimediawidgets REQUIRED)

set(QT_USE_QTMULTIMEDIA TRUE)
set(QT_USE_QTMULTIMEDIAWIDGETS TRUE)
set(QT_USE_QTWIDGETS TRUE)
set(QT_USE_QTGUI TRUE)
set(QT_USE_QTCORE TRUE)


add_executable(Smash)
target_sources(Smash PRIVATE main.cpp)
target_link_libraries(Smash Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Multimedia Qt5::MultimediaWidgets)


