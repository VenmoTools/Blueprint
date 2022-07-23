if (REQUIRED_QT_6)
    add_subdirectory(qt6)
    return()
endif ()


add_library(third_part_qt INTERFACE IMPORTED GLOBAL)
add_library(Blueprint::Qt ALIAS third_part_qt)


target_link_libraries(third_part_qt
        INTERFACE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        Qt::Svg
        )

target_include_directories(third_part_qt SYSTEM
        INTERFACE
        ${Qt5Core_PRIVATE_INCLUDE_DIRS}
        ${Qt5Gui_PRIVATE_INCLUDE_DIRS}
        )

