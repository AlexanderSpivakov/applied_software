PROJECT ( unittest)

include_directories(
../library
)

set(EXECUTABLE_OUTPUT_PATH ${common_out_path})

add_executable( unittest ../../googletest/googletest/src/gtest-all.cc)
#target_link_libraries( 2dapp 2dlib )



