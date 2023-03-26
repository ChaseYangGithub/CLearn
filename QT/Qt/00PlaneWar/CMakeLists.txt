cmake_minimum_required(VERSION 3.5)

project(00PlaneWar VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
#添加引用Qt5::Multimedia
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets  Multimedia)
set(PROJECT_SOURCES
    main.cpp

    mainscene.cpp   #主场景
    mainscene.h #主场景

    config.h    #游戏标题等主体配置数据

    res_img.qrc #图片素材文件
    res_sounds.qrc  #声音素材文件

    map.h   #地图类
    map.cpp #地图类

    heroplane.cpp #英雄飞机类
    heroplane.h #英雄飞机类

    bullet.h    #子弹类
    bullet.cpp    #子弹类

    enermyplane.cpp #敌机类
    enermyplane.h #敌机类

    bomb.cpp    #爆炸类
    bomb.h    #爆炸类
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(00PlaneWar
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET 00PlaneWar APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(00PlaneWar SHARED
            ${PROJECT_SOURCES}
        )
    # Define properties for Android with Qt 5 after find_package() calls as:
    #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
else()
    add_executable(00PlaneWar
        ${PROJECT_SOURCES}
    )
endif()
endif()
#添加引用Qt5::Multimedia
target_link_libraries(00PlaneWar PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt5::Multimedia)

set_target_properties(00PlaneWar PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS 00PlaneWar
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(00PlaneWar)
endif()
