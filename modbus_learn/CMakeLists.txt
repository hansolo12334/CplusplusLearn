cmake_minimum_required(VERSION 3.5.0)
project(modbus_learn)

set(MODBUS_HEADER_DIR /usr/local/include/modbus/)
file(GLOB  MODBUS_LIBS_DIR  /usr/local/lib/libmodbus*.so)

include_directories(${MODBUS_HEADER_DIR})

add_executable(client ./src/client.cc)
target_link_libraries(client ${MODBUS_LIBS_DIR})

add_executable(client1 ./src/client1.cc)
target_link_libraries(client1 ${MODBUS_LIBS_DIR})


add_executable(server ./src/server.cc)
target_link_libraries(server ${MODBUS_LIBS_DIR})
