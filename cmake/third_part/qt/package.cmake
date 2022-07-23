

if (NOT QT_DIR STREQUAL "")
    set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${QT_DIR}")
elseif (NOT $ENV{QT_DIR} STREQUAL "")
    set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};$ENV{QT_DIR}")
endif ()


if (REQUIRED_QT_6)
    find_package(Qt6 COMPONENTS Core Gui Widgets Network Svg REQUIRED)
else ()
    find_package(Qt5 COMPONENTS Core Gui Widgets Network Svg REQUIRED)
endif ()