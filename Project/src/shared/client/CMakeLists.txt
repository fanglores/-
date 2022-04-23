project(UDPSolek)

add_executable(client "src/client.cpp")

target_include_directories(client PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(client ${OpenCV_LIBS})
