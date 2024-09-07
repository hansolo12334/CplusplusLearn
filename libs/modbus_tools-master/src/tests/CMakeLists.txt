# 添加头文件的包含路径  
find_package(GTest REQUIRED)

add_subdirectory(tool_tests)

add_subdirectory(client_tests)

add_subdirectory(server_tests)