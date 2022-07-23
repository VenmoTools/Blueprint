cmake_minimum_required(VERSION 3.22)
project(BlueprintCore)

set(QT_DIR D:/LIBS/QT6/6.1.3/msvc2019_64)
set(REQUIRED_QT_6 ON)

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(cmake/init_target.cmake)
include(cmake/nice_target_sources.cmake)
include(cmake/third_part/qt/package.cmake)
include(cmake/CPM.cmake)


add_subdirectory(cmake/third_part)
add_subdirectory(libraries)
add_subdirectory(src)





add_executable(BlueprintCore main.cpp)
target_link_libraries(BlueprintCore
        PUBLIC
        Blueprint::UI
        Blueprint::UiComponents
        )

