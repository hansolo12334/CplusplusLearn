add_library(hansolo_core
    ./src/hansolo_server.cc
    ./src/hansolo_client.cc
    ./src/hansolo_tcp.cc
    ../udp/src/wrap.cc)
include_directories(./include)
include_directories(../udp/include)


add_executable(test_core ./test_core.cc ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(test_core
    hansolo_core
    ${PROTOBUF_LIBRARY}
    pthread)

add_executable(test_node ./test_node.cc ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(test_node
    hansolo_core
    ${PROTOBUF_LIBRARY}
    pthread)

add_executable(test_node1 ./test_node1.cc ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(test_node1
    hansolo_core
    ${PROTOBUF_LIBRARY}
    pthread)
