cmake_minimum_required(VERSION 3.5.1)
project(ex4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(BOOST_ROOT CACHE PATH "/yishai/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})

set(SOURCE_FILES
    CabDecorator.cpp
        CabDecorator.h
        Driver.cpp
        Driver.h
        EventNotifier.cpp
        EventNotifier.h
        MatchinStrategy.cpp
        MatchinStrategyTest.h
        LuxuryCab.cpp
        LuxuryCab.h
        OrderManager.cpp
        OrderManager.h
        Passanger.cpp
        Passanger.h
        Person.cpp
        Person.h
        Point.cpp
        Point.h
        Ride.cpp
        Ride.h
        Vehicle.cpp
        Vehicle.h
        BfsSearch.cpp
    BfsSearch.h
    Grid.cpp
    Grid.h
        Node.cpp
    Node.h
    Point.cpp
    Point.h
    StringParse.cpp
    StringParse.h
        test.h

        Parser.cpp Parser.h RegularCab.cpp RegularCab.h
        Udp.cpp Udp.h Socket.cpp Socket.h)

add_executable(server server.cpp ${SOURCE_FILES})
add_executable(client client.cpp ${SOURCE_FILES})

target_link_libraries(client ${Boost_LIBRARIES})
target_link_libraries(server ${Boost_LIBRARIES})

