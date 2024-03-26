cmake_minimum_required(VERSION 2.20)
project(sql_test)

add_executable(test_sql ./test_sql.cc)
target_link_libraries(test_sql mysqlclient)