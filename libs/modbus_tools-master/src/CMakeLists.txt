include_directories(modbus_tools)
include_directories(${PROJECT_SOURCE_DIR}/src)

find_package(GTest REQUIRED)

include_directories(/home/hansolo/CplusplusLearn/libs/modbus_tools-master/3rd/libmodbus/static/include/modbus)
add_subdirectory(modbus_tools)
# add_subdirectory(tests)