PROJECT ( 2dapp )

include_directories(
../library
)
add_executable( 2dapp initial.cpp)
target_link_libraries( 2dapp 2dlib )
