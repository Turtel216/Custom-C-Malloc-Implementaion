cmake_minimum_required(VERSION 3.30)
project(Lock)

enable_testing()

add_executable (test0 test/test-0.c src/lock.c)
add_executable (test1 test/test-1.c src/lock.c)
add_executable (test2 test/test-2.c src/lock.c)
add_executable (test3 test/test-3.c src/lock.c)
add_executable (test4 test/test-4.c src/lock.c)
add_executable (a.out src/main.c src/lock.c)

add_test(lock_test test0 test1 test2 test3 test4)
