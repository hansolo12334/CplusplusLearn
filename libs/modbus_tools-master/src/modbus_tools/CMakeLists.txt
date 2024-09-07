# 界面
file(GLOB MODBUS_TOOLS_SRC "*.cpp")
# modbus客户端
file(GLOB_RECURSE CLIENT_SOURCES "${CMAKE_SOURCE_DIR}/src/protocol/client/*.cpp")

set(TARGET modbus_tools)

# 设置二进制文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)

# 尝试找到libmodbus的静态库  
find_library(LIBMODBUS_STATIC libmodbus.a PATHS ${CMAKE_SOURCE_DIR}/3rd/libmodbus/static/lib)  
message("LIBMODBUS_STATIC: ${LIBMODBUS_STATIC}")

add_executable(${TARGET} ${MODBUS_TOOLS_SRC} ${CLIENT_SOURCES})

set(TVISION_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/3rd/tvision/include/")
message(STATUS "TVISION_INCLUDE_DIRS: ${TVISION_INCLUDE_DIRS}")
target_include_directories(${TARGET} PUBLIC ${TVISION_INCLUDE_DIRS})

target_link_libraries(${TARGET} PRIVATE tvision)
target_link_libraries(${TARGET} PUBLIC pthread ${LIBMODBUS_STATIC})