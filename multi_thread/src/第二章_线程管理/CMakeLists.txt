add_executable(2_1 2_1线程的基本操作/2_1.cc)
target_link_libraries(2_1 pthread)

add_executable(2_11 2_1线程的基本操作/特殊情况下的等待.cc)
target_link_libraries(2_11 pthread)

add_executable(2_12 2_1线程的基本操作/后台运行线程.cc)
target_link_libraries(2_12 pthread)


add_executable(2_2 2_2传递参数/2_2.cc)
target_link_libraries(2_2 pthread)

add_executable(test 2_2传递参数/test.cc)
target_link_libraries(test pthread)
