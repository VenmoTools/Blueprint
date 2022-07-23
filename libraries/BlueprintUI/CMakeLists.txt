
add_library(BlueprintUI STATIC )
add_library(Blueprint::UI ALIAS BlueprintUI )

init_target(BlueprintUI)

get_filename_component(src_loc . REALPATH)

# 设置target 源码
nice_target_source(BlueprintUI ${src_loc}
        PUBLIC
        Canvas/BlueprintCanvas.cc
        Canvas/BlueprintCanvas.hpp
        Canvas/BlueprintNode.cc
        Canvas/BlueprintNode.hpp
        Canvas/BlueprintPin.cc
        Canvas/BlueprintPin.hpp

        BlueprintStyle/NodeStyle.cc
        BlueprintStyle/NodeStyle.hpp
        BlueprintStyle/CanvasStyle.cc
        BlueprintStyle/CanvasStyle.hpp

        BlueprintPainter/PinPainter.cc
        BlueprintPainter/PinPainter.hpp
        BlueprintPainter/NodePainter.cc
        BlueprintPainter/NodePainter.hpp

        Utils/Algorithm.hpp
        )

target_include_directories(BlueprintUI PUBLIC ${src_loc})

target_link_libraries(BlueprintUI
        PUBLIC
        Blueprint::Qt
        )
