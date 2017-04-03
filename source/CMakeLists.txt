#AUTHOR: NA
#FILE: CmakeLists.txt
#DATE: 04/03/17
#DESC: Parent CmakeLists.txt file to create out of source build of project

cmake_minimum_required (VERSION 3.2.0)

project(test_cmake)

###########################################
#Get Apple frameworks

if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -x objective-c++")
    set(CMAKE_OSX_ARCHITECTURES "x86_64")
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.10")
    set(CMAKE_OSX_SYSROOT "$ENV{MACSDK_10_10}")
    find_library(LIBIOKIT IOKit)
    find_library(COCOAFRAMEWORK Foundation)

    set(OpenCV_DIR /usr/local/opencv-3.0.0/cmake)
    find_library(OPENCV OpenCVLib)
    if(NOT OPENCV)
        message(FATAL_ERROR "OpenCV not found")
    endif()

    find_library(boost components system filesystem required)
    if(boost_found)
        message("Boost found")
        include_directories(${Boost_INCLUDE_DIR})
        add_definitions("-DHAS_BOOST")
    else(NOT Boost_FOUND)
        message(FATAL_ERROR "Boost not found")
    endif()
    endif()

###########################################
#Add source files

file(GLOB SOURCE
    "source/*.cpp"
)

file(GLOB HEADER
    "source/*.h"
)
file(GLOB RESOURCE
    "resource/*.mp4"
    "resource/*.mp3"
    "resource/*.avi"
)

set(ALL_FILES
    ${SOURCE}
    ${HEADER}
    ${RESOURCE}
    )

###########################################
#Add headers and lib search paths

target_include_directories(SOURCE ${CMAKE_CURRENT_SOURCE_DIR})

###########################################
#Add files to project folder directory

if(APPLE)
set(RESOURCE_SOURCES ${RESOURCE})
source_group("Resources" FILES ${RESOURCE})
elseif(WIN32)
source_group("Sources" FILES ${SOURCE})
source_group("Headers" FILES ${HEADER})
source_group("Resources" FILES ${RESOURCE})
endif()

###########################################
#Add libraries

include_directories(.
    #$ENV{BOOST_DIR}
    ${Boost_INCLUDE_DIRS}
)

if(WIN32)
    link_libraries(
        boost
    )
elseif(APPLE)
    link_libraries(
        /opt/local/lib/lib/libboost_filesystem.a
        $ENV{BOOST_LIB_DIR}/libboost_system.a
        $ENV{BOOST_LIB_DIR}/libboost_date_time.a
    )
    else(NOT APPLE AND NOT WIN32)
    message("Not windows or mac, no libs added")
endif()

###########################################
#Add executable

add_executable(${PROJECT_NAME} ${ALL_FILES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
#libboost_filesystem.dylib libboost_system.dylib)

###########################################
#Post build commands to copy resources to dir

#Create video resources folder
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    command ${CMAKE_COMMAND} -E make_directory
    $ENV{RESOURCE_DIR}
    comment "Creating Resources subfolder"
)

foreach(resource_file ${RESOURCE})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    command ${CMAKE_COMMAND} -E copy_if_different
    ${resource_file} $ENV{RESOURCE_DIR}
    )
endforeach()
