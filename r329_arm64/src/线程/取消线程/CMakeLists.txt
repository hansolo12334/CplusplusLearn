add_executable(test_thread2 ${PROJECT_SOURCE_DIR}/src/线程/取消线程/test.c)
target_link_libraries(test_thread2 pthread)


add_executable(test_thread3 test1.c)
target_link_libraries(test_thread3 pthread)

add_executable(test_thread4 test2.c)
target_link_libraries(test_thread4 pthread)
