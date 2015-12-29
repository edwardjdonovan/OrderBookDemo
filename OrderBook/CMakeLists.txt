project(OrderBook)

add_definitions(-std=gnu++11)

set(HEADER_FILES OrderBook.h)
set(SOURCE_FILES OrderBook.cpp)

add_library(OrderBook STATIC ${SOURCE_FILES} ${HEADER_FILES})
