

add_library(Blueprint_UiComponents STATIC)
add_library(Blueprint::UiComponents ALIAS Blueprint_UiComponents)

init_target(Blueprint_UiComponents)

get_filename_component(src_loc . REALPATH)


nice_target_source(Blueprint_UiComponents ${src_loc}
        PUBLIC
        DockWindow/DockTitleBar.cc
        DockWindow/DockTitleBar.hpp
        Input/QGraphicsInputField.cc
        Input/QGraphicsInputField.hpp
        )

target_include_directories(Blueprint_UiComponents PUBLIC ${src_loc})

target_link_libraries(Blueprint_UiComponents
        PUBLIC
        Blueprint::Qt
        )

