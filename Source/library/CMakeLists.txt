PROJECT ( 2dapp )

set(LIBRARY_OUTPUT_PATH ${common_out_path})

add_library( 2dlib SHARED script.cpp fucos.h)
