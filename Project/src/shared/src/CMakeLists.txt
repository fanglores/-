project( SolarAutonomics )

set( HEADER_FILES "src/system.h" "src/system.cpp" "src/event.h" "src/event.cpp" "src/camera.h" "src/camera.cpp" "src/generator.h" "src/generator.cpp")

add_executable( SolEx "src/main.cpp" ${HEADER_FILES})

target_include_directories( SolEx PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" )
target_link_libraries( SolEx ${OpenCV_LIBS} )
