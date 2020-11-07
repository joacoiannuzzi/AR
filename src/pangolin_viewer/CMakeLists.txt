# ----- Find dependencies -----

# Pangolin
find_package(Pangolin REQUIRED)

# ----- Configure PangolinViewer library -----

#add_library(pangolin_viewer
#        SHARED
#        viewer.h
#        color_scheme.h
#        viewer.cc
#        color_scheme.cc)
#
#set_target_properties(pangolin_viewer PROPERTIES
#        OUTPUT_NAME pangolin_viewer
#        LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
#
#target_include_directories(pangolin_viewer
#        PUBLIC
#        ${Pangolin_INCLUDE_DIR})
#
#target_link_libraries(pangolin_viewer
#        PUBLIC
#        openvslam
#        opencv_highgui
#        pangolin)

target_sources(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/viewer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/color_scheme.h
        ${CMAKE_CURRENT_SOURCE_DIR}/viewer.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/color_scheme.cc)

