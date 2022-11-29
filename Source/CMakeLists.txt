PROJECT ( 2dproject )

set( common_out_path "../bin" )

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=gnu++11 )

add_subdirectory (executable)

add_subdirectory (library)

#add_subdirectory(unittests)
