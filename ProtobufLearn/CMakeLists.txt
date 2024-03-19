cmake_minimum_required(VERSION 3.25)
project(ProtobufLearn)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf REQUIRED)


set(msgs msgs/test.proto
         msgs/AddressBook.proto
         ./src/hansolo_thread/msgs/coreConnection.proto)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${msgs})
protobuf_generate_python(PROTO_PY ${msgs})

add_library(SHARED ${PROTO_SRCS} ${PROTO_HDRS})

add_executable(test src/io/test.cc  ${PROTO_SRCS} ${PROTO_HDRS} )
target_link_libraries(test ${PROTOBUF_LIBRARY} pthread)

add_executable(test_phonebook src/io/test_phoneBook.cc  ${PROTO_SRCS} ${PROTO_HDRS} )
target_link_libraries(test_phonebook ${PROTOBUF_LIBRARY} pthread)

add_executable(read_phoneBook src/io/read_phoneBook.cc  ${PROTO_SRCS} ${PROTO_HDRS} )
target_link_libraries(read_phoneBook ${PROTOBUF_LIBRARY} pthread)


add_executable(server src/tcp/server.cc  ${PROTO_SRCS} ${PROTO_HDRS} )
target_link_libraries(server ${PROTOBUF_LIBRARY} pthread)
add_executable(client src/tcp/client.cc  ${PROTO_SRCS} ${PROTO_HDRS} )
target_link_libraries(client ${PROTOBUF_LIBRARY} pthread)





include_directories(src/tcp/include)
add_executable(tcp_client src/tcp/tcp_client.cc src/tcp/src/tcp_socket.cc  ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(tcp_client ${PROTOBUF_LIBRARY} pthread)

add_executable(tcp_server src/tcp/tcp_server.cc src/tcp/src/tcp_socket.cc ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(tcp_server ${PROTOBUF_LIBRARY} pthread)


include_directories(src/udp/include)
add_executable(tcp_server_select_model src/tcp/tcp_server_select_model.cc src/udp/src/wrap.cc ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(tcp_server_select_model ${PROTOBUF_LIBRARY} pthread)

add_subdirectory(./src/udp)

add_subdirectory(./src/hansolo_thread)
