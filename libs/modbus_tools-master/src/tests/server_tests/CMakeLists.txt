set(TARGET modbus_tcp_server_test)

# modbus客户端
file(GLOB_RECURSE SERVER_SOURCES "${CMAKE_SOURCE_DIR}/src/protocol/server/*.cpp")

file(GLOB_RECURSE SRC *.cpp)

add_executable(${TARGET} ${SRC} ${SERVER_SOURCES})

target_include_directories(${TARGET} PUBLIC 
    ${GTEST_INCLUDE_DIRS})
    
target_link_libraries(${TARGET} PUBLIC gtest gtest_main pthread)
target_link_libraries(${TARGET} PUBLIC ${LIBMODBUS_STATIC})