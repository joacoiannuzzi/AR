# Project definition
cmake_minimum_required(VERSION 3.1)
project(AR)

# Source files
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(SOURCES "${SRC_DIR}/main.cpp" src/drawer.h src/shader.h)
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libraries")

# Executable definition and properties
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

# glad
set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
#target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")

# GLFW
#set(GLFW_DIR "${LIB_DIR}/glfw")
#set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
#set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
#set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
#set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
#add_subdirectory("${GLFW_DIR}")
#target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
#target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
#target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIR})
link_libraries(${OpenCV_LIBS})
#target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})


add_subdirectory(${SRC_DIR}/pangolin_viewer)

find_package(DBoW2 REQUIRED)
set(BoW_INCLUDE_DIR ${DBoW2_INCLUDE_DIRS})
set(BoW_LIBRARY ${DBoW2_LIBS})
target_compile_definitions(${PROJECT_NAME} PUBLIC USE_DBOW2)

# Set macro flag
target_compile_definitions(${PROJECT_NAME} PRIVATE USE_PANGOLIN_VIEWER)
# Link viewer
#link_libraries(pangolin_viewer)

include_directories(/usr/local/include/openvslam/3rd/json/include)
include_directories(/usr/include/eigen3)
#find_package(Eigen3 REQUIRED)
#include_directories(${Eigen3_INCLUDE_DIRS})

# openvslam
find_package(openvslam REQUIRED)
include_directories(${openvslam_INCLUDE_DIR})
link_libraries(${openvslam_LIBS})


# Pangolin
find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
link_libraries(${Pangolin_LIBS})

find_package(glfw3 REQUIRED)
include_directories(${glfw3_INCLUDE_DIR})
#link_libraries(${glfw_LIBRARIES})

configure_file(configuration/root_directory.h.in configuration/root_directory.h)
include_directories(${CMAKE_BINARY_DIR}/configuration)

add_library(STB_IMAGE "src/stb_image.cpp")
#set(LIBS ${LIBS} STB_IMAGE)

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        STB_IMAGE
        Threads::Threads
        Eigen3::Eigen
        yaml-cpp
        opencv_core
        opencv_features2d
        opencv_calib3d
        ${OpenCV_LIBS}
        ${openvslam_LIBS}
        ${Pangolin_LIBRARIES}
        ${GLEW_LIBRARIES}
        glfw
        openvslam
        g2o::core
        g2o::stuff
        g2o::types_sba
        g2o::types_sim3
        g2o::solver_dense
        g2o::solver_eigen
        g2o::solver_csparse
        g2o::csparse_extension
        ${CXSPARSE_LIBRARIES}
        ${SUITESPARSE_LIBRARIES}
        ${BoW_LIBRARY}
        PRIVATE
        ${LAPACK_LIBRARIES})








