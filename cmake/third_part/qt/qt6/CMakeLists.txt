

add_library(third_part_qt INTERFACE IMPORTED GLOBAL)
add_library(Blueprint::Qt ALIAS third_part_qt)


target_link_libraries(third_part_qt
        INTERFACE
        Qt6::Core
        Qt6::CorePrivate
        Qt6::Gui
        Qt6::GuiPrivate
        Qt6::Widgets
        Qt6::Network
        Qt6::Svg
        )