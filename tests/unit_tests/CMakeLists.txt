file(GLOB SRCS *.cpp)
ADD_EXECUTABLE(unit_tests
        ${SRCS}
        insert_test.cpp
        select_test.cpp
        )
TARGET_LINK_LIBRARIES(
        unit_tests
        libgtest
        libgmock
        mysqlclient
        ${CMAKE_PROJECT_NAME}_lib
)
add_test(NAME unit_tests
        COMMAND unit_tests)