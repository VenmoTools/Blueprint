
add_library(BlueprintUI STATIC )
add_library(Blueprint::UI ALIAS BlueprintUI)

init_target(BlueprintUI)

get_filename_component(src_loc . REALPATH)

# 设置target 源码
nice_target_source(BlueprintUI ${src_loc}
        PUBLIC

        BlueprintNode/NodeUI.cc
        BlueprintNode/NodeUI.hpp
        BlueprintNode/NodeHeader.cc
        BlueprintNode/NodeHeader.hpp
        BlueprintNode/NodeLayout.cc
        BlueprintNode/NodeLayout.hpp

        Canvas/BlueprintCanvas.cc
        Canvas/BlueprintCanvas.hpp
        BlueprintPin/BlueprintPin.cc
        BlueprintPin/BlueprintPin.hpp

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
        Blueprint::UiComponents
        )
