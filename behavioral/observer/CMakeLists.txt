cmake_minimum_required(VERSION 3.8)

set(This observer)

set(Headers observer.h)
set(Sources observer.cpp)

add_executable(observer "observer.cpp" "observer.h" "observerTest.cpp")

#add_library(${This} PUBLIC ${Headers} ${Sources})
