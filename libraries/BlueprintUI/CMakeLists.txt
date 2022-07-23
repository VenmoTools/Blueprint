
add_library(BlueprintUI STATIC)
add_library(Blueprint::UI ALIAS BlueprintUI )

init_target(BlueprintUI)

get_filename_component(src_loc . REALPATH)

# 设置target 源码
nice_target_source(BlueprintUI ${src_loc}
        PUBLIC
        Canvas/BlueprintCanvas.cc
        Canvas/BlueprintCanvas.hpp

        BlueprintStyle/CanvasStyle.cc
        BlueprintStyle/CanvasStyle.hpp

        Utils/Algorithm.hpp
        )

target_include_directories(BlueprintUI PUBLIC ${src_loc})

target_link_libraries(BlueprintUI
        PUBLIC
        Blueprint::Qt
        )
