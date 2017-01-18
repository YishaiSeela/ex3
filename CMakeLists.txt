cmake_minimum_required(VERSION 3.5)
project(Ex3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(BOOST_ROOT CACHE PATH "/adi/include/boost/")
#set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})

set(SOURCE_FILES
<<<<<<< HEAD
        Map/BfsSearch.cpp
        Map/BfsSearch.h
        Veicle/CabDecorator.cpp
        Veicle/CabDecorator.h
        #client.cpp
        Persons/Driver.cpp
        Persons/Driver.h
        taxiCenter/EventNotifier.cpp
        taxiCenter/EventNotifier.h
        Map/Grid.cpp
        Map/Grid.h
        Veicle/LuxuryCab.cpp
        Veicle/LuxuryCab.h
        taxiCenter/MatchinStrategy.cpp
        taxiCenter/MatchinStrategy.h
        taxiCenter/MatchinStrategyTest.h
        Map/Node.cpp
        Map/Node.h
        taxiCenter/OrderManager.cpp
        taxiCenter/OrderManager.h
        separateInput/Parser.cpp
        separateInput/Parser.h
        Persons/Passanger.cpp
        Persons/Passanger.h
        Persons/Person.cpp
        Persons/Person.h
        Map/Point.cpp
        Map/Point.h
        Veicle/RegularCab.cpp
        Veicle/RegularCab.h
        taxiCenter/Ride.cpp
        taxiCenter/Ride.h
        #server.cpp
        communication/Socket.cpp
        communication/Socket.h
        separateInput/StringParse.cpp
        separateInput/StringParse.h
        communication/Tcp.cpp
        communication/Tcp.h
        test.h
        Veicle/Vehicle.cpp
        Veicle/Vehicle.h)
=======
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
>>>>>>> a317c55625c3cb867d87260fb6992b46951de479

add_executable(server communication/server.cpp ${SOURCE_FILES})
add_executable(client communication/client.cpp ${SOURCE_FILES})

target_link_libraries(client ${Boost_LIBRARIES})
target_link_libraries(server ${Boost_LIBRARIES})

