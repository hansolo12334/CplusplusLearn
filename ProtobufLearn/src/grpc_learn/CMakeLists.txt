cmake_minimum_required(VERSION 3.20)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROTOBUF_GRPC_ROOT "/usr/local/include/protobuf25_1")

set(CMAKE_PREFIX_PATH
    ${CMAKE_PREFIX_PATH}
    ${PROTOBUF_GRPC_ROOT}/lib/cmake/
)
option(protobuf_MODULE_COMPATIBLE TRUE)
set(_GRPC_GRPCPP gRPC::grpc++)


find_package(Protobuf CONFIG REQUIRED )
message(STATUS "Using protobuf ${Protobuf_VERSION}")
set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)

find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")
set(_GRPC_GRPCPP gRPC::grpc++)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)
# Proto file
get_filename_component(hw_proto "./msgs/hansoloCores.proto" ABSOLUTE)
get_filename_component(hw_proto_path "${hw_proto}" PATH)


# Generated sources
set(hw_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/hansoloCores.pb.cc")
set(hw_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/hansoloCores.pb.h")
set(hw_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/hansoloCores.grpc.pb.cc")
set(hw_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/hansoloCores.grpc.pb.h")


add_custom_command(
      OUTPUT   "${hw_proto_srcs}" "${hw_proto_srcs}" "${hw_grpc_srcs}" "${hw_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${hw_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${hw_proto}"
      DEPENDS "${hw_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# hw_grpc_proto
add_library(hw_grpc_proto
  ${hw_grpc_srcs}
  ${hw_grpc_hdrs}
  ${hw_proto_srcs}
  ${hw_proto_hdrs})

target_link_libraries(hw_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

# Targets greeter_[async_](client|server)
# foreach(_target
#   greeter_client greeter_server
#   greeter_callback_client greeter_callback_server
#   greeter_async_client greeter_async_client2 greeter_async_server)
#   add_executable(${_target} "${_target}.cc")
#   target_link_libraries(${_target}
#     hw_grpc_proto
#     absl::flags
#     absl::flags_parse
#     ${_REFLECTION}
#     ${_GRPC_GRPCPP}
#     ${_PROTOBUF_LIBPROTOBUF})
# endforeach()

add_executable(test src/test.cc)
target_link_libraries(test hw_grpc_proto
                        absl::flags
                        absl::flags_parse
                        ${_REFLECTION}
                        ${_GRPC_GRPCPP}
                        ${_PROTOBUF_LIBPROTOBUF} pthread)
