cmake_minimum_required(VERSION 3.5)
project(Ex3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(BOOST_ROOT CACHE PATH "/adi/include/boost/")
#set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})

set(SOURCE_FILES
        Map/BfsSearch.cpp
        Map/BfsSearch.h
        Vehicles/CabDecorator.cpp
        Vehicles/CabDecorator.h
        #client.cpp
        Persons/Driver.cpp
        Persons/Driver.h
        TaxiCenter/EventNotifier.cpp
        TaxiCenter/EventNotifier.h
        Map/Grid.cpp
        Map/Grid.h
        Vehicles/LuxuryCab.cpp
        Vehicles/LuxuryCab.h
        TaxiCenter/MatchinStrategy.cpp
        TaxiCenter/MatchinStrategy.h
        TaxiCenter/MatchinStrategyTest.h
        Map/Node.cpp
        Map/Node.h
        TaxiCenter/OrderManager.cpp
        TaxiCenter/OrderManager.h
        SeparateInput/Parser.cpp
        SeparateInput/Parser.h
        Persons/Passanger.cpp
        Persons/Passanger.h
        Persons/Person.cpp
        Persons/Person.h
        Map/Point.cpp
        Map/Point.h
        Vehicles/RegularCab.cpp
        Vehicles/RegularCab.h
        TaxiCenter/Ride.cpp
        TaxiCenter/Ride.h
        #server.cpp
        Communication/Socket.cpp
        Communication/Socket.h
        SeparateInput/StringParse.cpp
        SeparateInput/StringParse.h
        Communication/Tcp.cpp
        Communication/Tcp.h
        test.h
        Vehicles/Vehicle.cpp
        Vehicles/Vehicle.h)

add_executable(server Communication/server.cpp ${SOURCE_FILES})
add_executable(client Communication/client.cpp ${SOURCE_FILES})

target_link_libraries(client ${Boost_LIBRARIES})
target_link_libraries(server ${Boost_LIBRARIES})

