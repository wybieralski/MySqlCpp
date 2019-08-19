project(${CMAKE_PROJECT_NAME}_lib)

add_library(${CMAKE_PROJECT_NAME}_lib OBJECT)

target_sources(${CMAKE_PROJECT_NAME}_lib PRIVATE
        Connection.cpp
        )

#set(HEADER_FILES
#        Connection.h
#        )
#set(SOURCE_FILES
#        Connection.cpp
#        )
#
#if (EXISTS ${SOURCE_FILES})
#    # The library contains header and source files.
#    add_library(${CMAKE_PROJECT_NAME}_lib STATIC
#            ${SOURCE_FILES}
#            ${HEADER_FILES}
#            )
#    target_include_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC
#            ${CMAKE_CURRENT_SOURCE_DIR}
#            )
#else()
#    # The library only contains header files.
#    add_library(${CMAKE_PROJECT_NAME}_lib INTERFACE)
#endif()
#
