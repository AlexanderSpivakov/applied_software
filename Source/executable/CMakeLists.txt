PROJECT ( 2dapp )

include_directories(
../library
)

set(EXECUTABLE_OUTPUT_PATH ${common_out_path})

add_executable( 2dapp initial.cpp)
target_link_libraries( 2dapp 2dlib )

