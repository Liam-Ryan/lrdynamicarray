set(SOURCE_FILES lrdynamicarray.c lrdynamicarray.h)
add_library(lrdynamicarray ${SOURCE_FILES})
target_include_directories(lrdynamicarray PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})