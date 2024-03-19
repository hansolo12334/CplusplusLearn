add_library(hansolo_core
    ./src/hansolo_server.cc
    ./src/hansolo_client.cc
    ./src/hansolo_tcp.cc
    ./src/hansolo_tcp_thread.cc
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


add_executable(test_server_tcp ./test_server_tcp.cc )
target_link_libraries(test_server_tcp hansolo_core pthread)


#测试多client select 模型
include_directories(./include/multiClient/)
add_executable(test_select_server ./include/multiClient/test_select_server.cc ./include/multiClient/wrap.cc ./include/multiClient/hansolo_tcp.cc)
