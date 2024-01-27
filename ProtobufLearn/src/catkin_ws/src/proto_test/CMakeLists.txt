cmake_minimum_required(VERSION 3.25)
project(proto_test)

find_package(catkin REQUIRED COMPONENTS
  gencpp
  genpy
  roscpp
  rospy
  std_msgs
  proto_msg
)


find_package(Protobuf REQUIRED)

# file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/msgs)

# set(msgs
#     msgs/hansolo.proto
# )

# PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${msgs})
# protobuf_generate_python(PROTO_PY ${msgs})

# add_library(proto_msg SHARED ${PROTO_SRCS} ${PROTO_HDRS})
# target_link_libraries(proto_msg ${PROTOBUF_LIBRARY})


# generate_messages(DEPENDENCIES proto_test std_msgs)


catkin_package(
    INCLUDE_DIRS
    include
    #proto
    ${CMAKE_CURRENT_BINARY_DIR}/..
    CATKIN_DEPENDS
    roscpp
    gencpp
    genpy
)

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${catkin_INCLUDE_DIRS}
                    ${CMAKE_CURRENT_BINARY_DIR}
                    /usr/local/lib/
)

link_directories(${catkin_LIBRARY_DIRS}
                 ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(test_lisener src/test_lisener.cc )
target_link_libraries(test_lisener
                    proto_msg
                    ${PROTOBUF_LIBRARY}
                    ${catkin_LIBRARIES})



add_executable(test_pub src/test_pub.cc )
target_link_libraries(test_pub
                    proto_msg
                    ${PROTOBUF_LIBRARY}
                    ${catkin_LIBRARIES})





# catkin_python_setup()

install(PROGRAMS
    scripts/test_proto.py
   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
