PROJECT ( unittest)

include_directories(
../library
../../googletest/googletest/include
../../googletest/googletest/src
)

set(EXECUTABLE_OUTPUT_PATH ${common_out_path})

add_executable( unittest utest.cpp)
#target_link_libraries( 2dapp 2dlib )



