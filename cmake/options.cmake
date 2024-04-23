## Set C++ standard/compile-time options
add_library(CommonOptions INTERFACE)
target_include_directories(CommonOptions INTERFACE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(CommonOptions INTERFACE -static)


