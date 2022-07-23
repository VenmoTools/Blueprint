

function(nice_target_source target_name src_loc)
    set(list ${ARGV})

    list(REMOVE_AT list 0 1)

    set(export_symbol "")
    set(private_sources "")
    set(public_sources "")
    set(interface_sources "")
    # 遍历源文件 按照PRIVATE  PUBLIC INTERFACE进行分组
    foreach (entry ${list})
        if (${entry} STREQUAL "PRIVATE" OR ${entry} STREQUAL "PUBLIC" OR ${entry} STREQUAL "INTERFACE")
            set(export_symbol ${entry})
        else ()
            set(full_name ${src_loc}/${entry})

            if ("${export_symbol}" STREQUAL "PRIVATE")
                list(APPEND private_sources ${full_name})
            elseif ("${export_symbol}" STREQUAL "PUBLIC")
                list(APPEND public_sources ${full_name})
            elseif ("${export_symbol}" STREQUAL "INTERFACE")
                list(APPEND interface_sources ${full_name})
            else()
                message(FATAL_ERROR "Unknown sources scope for target ${target_name}")
            endif()
        endif ()
    endforeach ()

    if (NOT "${public_sources}" STREQUAL "")
        target_sources(${target_name} PUBLIC ${public_sources})
    endif()

    if (NOT "${private_sources}" STREQUAL "")
        target_sources(${target_name} PRIVATE ${private_sources})
    endif()

    if (NOT "${interface_sources}" STREQUAL "")
        target_sources(${target_name} INTERFACE ${interface_sources})
    endif()

    if (WIN32)
        set_source_files_properties(${not_win_sources} PROPERTIES HEADER_FILE_ONLY TRUE)
        set_source_files_properties(${not_win_sources} PROPERTIES SKIP_AUTOGEN TRUE)
    elseif (APPLE)
        set_source_files_properties(${not_mac_sources} PROPERTIES HEADER_FILE_ONLY TRUE)
        set_source_files_properties(${not_mac_sources} PROPERTIES SKIP_AUTOGEN TRUE)
    elseif (LINUX)
        set_source_files_properties(${not_linux_sources} PROPERTIES HEADER_FILE_ONLY TRUE)
        set_source_files_properties(${not_linux_sources} PROPERTIES SKIP_AUTOGEN TRUE)
    endif()
endfunction()