include_directories(./include)
add_executable(udp_server udp_server.cc src/wrap.cc)
add_executable(udp_client udp_client.cc src/wrap.cc)
