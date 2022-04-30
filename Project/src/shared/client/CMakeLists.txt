project(UDPSolek)

set(HEADERS "src/client.h" "src/client.cpp")

add_executable(client "src/main.cpp" "${HEADERS}")
