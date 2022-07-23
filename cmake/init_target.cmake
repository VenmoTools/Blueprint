

function(init_target_folder target_name folder_name)
    if (NOT ${folder_name} STREQUAL "")
        set_target_properties(${target_name} PROPERTIES FOLDER ${folder_name})
    endif ()
endfunction()

function(init_target target_name)
    # 设置 CXX标准
    if (ARGC GREATER 1)
        if (${ARGV1} STREQUAL cxx_std_14 OR ${ARGV1} STREQUAL cxx_std_11 OR ${ARGV1} STREQUAL cxx_std_17)
            target_compile_features(${target_name} PRIVATE ${ARGV1})
        else ()
            target_compile_features(${target_name} PRIVATE cxx_std_17)
            init_target_folder(${target_name} ${ARGV1})
        endif ()
    endif ()

    if (CMAKE_CXX_COMPILE_ID STREQUAL "MSVC")
        set_target_properties(${target_name} PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif ()
endfunction()