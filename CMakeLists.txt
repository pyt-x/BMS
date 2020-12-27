cmake_minimum_required(VERSION 3.17)
project(BMS C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(BMS main.c manage.c manage.h book.c penalty.c register_login.c lend_return.c)