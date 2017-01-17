cmake_minimum_required(VERSION 3.5)
project(Ex3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(BOOST_ROOT CACHE PATH "/adi/include/boost/")
#set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})

set(SOURCE_FILES
        BfsSearch.cpp
        BfsSearch.h
        CabDecorator.cpp
        CabDecorator.h
        #client.cpp
        Driver.cpp
        Driver.h
        EventNotifier.cpp
        EventNotifier.h
        Grid.cpp
        Grid.h
        LuxuryCab.cpp
        LuxuryCab.h
        MatchinStrategy.cpp
        MatchinStrategy.h
        MatchinStrategyTest.h
        Node.cpp
        Node.h
        OrderManager.cpp
        OrderManager.h
        Parser.cpp
        Parser.h
        Passanger.cpp
        Passanger.h
        Person.cpp
        Person.h
        Point.cpp
        Point.h
        RegularCab.cpp
        RegularCab.h
        Ride.cpp
        Ride.h
        #server.cpp
        Socket.cpp
        Socket.h
        StringParse.cpp
        StringParse.h
        Tcp.cpp
        Tcp.h
        test.h
        Vehicle.cpp
        Vehicle.h)

add_executable(server server.cpp ${SOURCE_FILES})
add_executable(client client.cpp ${SOURCE_FILES})

target_link_libraries(client ${Boost_LIBRARIES})
target_link_libraries(server ${Boost_LIBRARIES})

