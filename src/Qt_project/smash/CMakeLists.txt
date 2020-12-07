cmake_minimum_required(VERSION 3.1.0)

project(Smash VERSION 1.0 LANGUAGES CXX)
file(GLOB source_files *.c *.cpp *.qrc)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.1/mingw81_64/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS widgets REQUIRED)
find_package(Qt5 COMPONENTS gui REQUIRED)
find_package(Qt5 COMPONENTS core REQUIRED)
find_package(Qt5 COMPONENTS multimedia REQUIRED)
find_package(Qt5 COMPONENTS multimediawidgets REQUIRED)

set(QT_USE_QTMULTIMEDIA TRUE)
set(QT_USE_QTMULTIMEDIAWIDGETS TRUE)


add_executable(Smash 
	characterselect.h
	game.h
	gingerbread.h
	lakki.h
	levelselect.h
	mainmenu.h
	platform.h
	player.h
	totoro.h
	characterselect.cpp
	game.cpp
	gingerbread.cpp
	levelselect.cpp
	main.cpp
	mainmenu.cpp
	platform.cpp
	player.cpp
	Resourses.qrc
)

target_link_libraries(Smash Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Multimedia Qt5::MultimediaWidgets PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "Release")


