cmake_minimum_required(VERSION 3.5.1)
project(ex4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



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
    main.cpp
    Node.cpp
    Node.h
    Point.cpp
    Point.h
    StringParse.cpp
    StringParse.h
        test.h

        Parser.cpp Parser.h RegularCab.cpp RegularCab.h
        client.cpp Udp.cpp Udp.h server.cpp Socket.cpp Socket.h)

add_executable(ex4 ${SOURCE_FILES})
