cmake_minimum_required(VERSION 3.25)
project(proto_msg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

find_package(Protobuf REQUIRED)

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/msgs)



catkin_package(
  INCLUDE_DIRS
    include
    # for generated Protobuf messages. Export parent dir (build/), so that
    # the #include <*.pb.h> line has the package name, consistent between
    # catkin config --install and --no-install.
    ${CMAKE_CURRENT_BINARY_DIR}/..
    ${GAZEBO_MSG_INCLUDE_DIRS}
  LIBRARIES
    proto_msg
  CATKIN_DEPENDS
    roscpp
)

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${catkin_INCLUDE_DIRS}
                    ${CMAKE_CURRENT_BINARY_DIR}
                    /usr/local/lib/
#                   ...
)

link_directories(${catkin_LIBRARY_DIRS}
                 ${CMAKE_CURRENT_BINARY_DIR}
#                ...
)

set(msgs
    msgs/hansolo.proto
)

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${msgs})
# protobuf_generate_python(PROTO_PY ${msgs})

add_library(proto_msg SHARED ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(proto_msg ${PROTOBUF_LIBRARY})
add_dependencies(proto_msg
   ${catkin_EXPORTED_TARGETS}
)

set(HANSOLO_PROTO_MSG_LIST "")
list(APPEND HANSOLO_PROTO_MSG_LIST proto_msg)

catkin_python_setup()




install(TARGETS ${HANSOLO_PROTO_MSG_LIST}
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# install(DIRECTORY include/
#    DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}
#    FILES_MATCHING PATTERN ".h"
# )

# install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.pb.*"
#   PATTERN "*~" EXCLUDE
# )
