cmake_minimum_required(VERSION 3.5)

project(CoinFlip VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    res.qrc

    chooselevelscene.cpp
    chooselevelscene.h
    gameconfig.cpp
    gameconfig.h
    
    mycoin.cpp
    mycoin.h
    
    mypushbutton.cpp
    mypushbutton.h
    
    playscene.cpp
    playscene.h
)

add_executable(CoinFlip
    ${PROJECT_SOURCES}
)

target_link_libraries(CoinFlip PRIVATE Qt5::Widgets)
