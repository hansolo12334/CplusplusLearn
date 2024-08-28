cmake_minimum_required(VERSION 3.5)
project(shared_memery)


include(protoGen.cmake)

add_executable(test_shared_mem src/test_shared_mem.cc)
add_executable(test_shared_mem2 src/test_shared_mem2.cc)


include_directories(include)

add_library(shared_mem src/shared_mem.cc)

add_executable(test_sm1 test_sm1.cc)
add_executable(test_sm2 test_sm2.cc)

target_link_libraries(test_sm1 shared_mem hw_grpc_proto
absl::flags
absl::flags_parse
${_REFLECTION}
${_GRPC_GRPCPP}
${_PROTOBUF_LIBPROTOBUF}
)

target_link_libraries(test_sm2 shared_mem
hw_grpc_proto
    absl::flags
    absl::flags_parse
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF}
  )