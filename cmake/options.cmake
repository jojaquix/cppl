## Set C++ standard/compile-time options
add_library(CommonOptions INTERFACE)
target_include_directories(CommonOptions INTERFACE ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/deps)


if (MSVC)
    # why this not have effect? I need read more about this
    set_property(TARGET CommonOptions PROPERTY INTERFACE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")    
endif()
