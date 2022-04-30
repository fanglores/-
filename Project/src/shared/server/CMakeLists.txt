project( UDPSolek )

set( HEADER_FILES "src/event.h" "src/event.cpp" "src/system.h" "src/system.cpp" "src/camera.h" "src/camera.cpp" "src/generator.h" "src/generator.cpp" )

add_executable( server "src/main.cpp" ${HEADER_FILES})

target_include_directories( server PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" )
target_link_libraries( server ${OpenCV_LIBS} )
