project( SolarAutonomics )

add_executable( SolEx "src/main.cpp" )

target_include_directories( SolEx PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" )
target_link_libraries( SolEx ${OpenCV_LIBS} )
