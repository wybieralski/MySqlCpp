cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(Test)


set(Sources src/Connection.cpp)
set(Headers src/Connection.h)
add_executable(exe2 main.cpp ${Sources} ${Headers})


add_executable(app main.cpp
        src/Connection.cpp
        src/Connection.h
        )

target_link_libraries(app
        mysqlclient)

target_link_libraries(exe2
        mysqlclient)

