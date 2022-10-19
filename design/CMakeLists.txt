find_package(Threads REQUIRED)

add_executable(test_threadpool test_threadpool.cpp threadpool.h locker.h runnable.h)
target_link_libraries(test_threadpool pthread)
