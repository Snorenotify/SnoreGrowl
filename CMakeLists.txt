project( SnoreGrowl )
cmake_minimum_required( VERSION 2.6 )

include(GenerateExportHeader)

option(SNOREGROWL_STATIC "Build snoregrowl statically" OFF)

set(SNOREGROWL_VERSION_MAJOR 0)
set(SNOREGROWL_VERSION_MINOR 5)
set(SNOREGROWL_VERSION_PATCH 0)


if(SNOREGROWL_STATIC)
    set(SNOREGROWL_LINK_MODE STATIC)
    if(MSVC)
        set(SUFFIX "lib")
        foreach(_bt DEBUG RELEASE RELWITHDEBINFO)
            string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_${_bt} ${CMAKE_CXX_FLAGS_${_bt}})
        endforeach(_bt DEBUG RELEASE RELWITHDEBINFO)
    endif()
else()
    set(SNOREGROWL_LINK_MODE SHARED)
endif()

find_package(Threads REQUIRED)

add_subdirectory(src)
