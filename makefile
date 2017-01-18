all: server client

COMMON_SOURCES = Vehicles/CabDecorator.cpp Persons/Driver.cpp TaxiCenter/EventNotifier.cpp \
	TaxiCenter/MatchinStrategy.cpp Vehicles/LuxuryCab.cpp TaxiCenter/OrderManager.cpp \
	Persons/Passanger.cpp Persons/Person.cpp Map/Point.cpp TaxiCenter/Ride.cpp Vehicles/Vehicle.cpp \
	Map/BfsSearch.cpp Map/Grid.cpp Map/Node.cpp SeparateInput/StringParse.cpp \
	SeparateInput/Parser.cpp Vehicles/RegularCab.cpp Communication/Tcp.cpp Communication/Socket.cpp
server:
	g++ -std=c++0x Communication/server.cpp $(COMMON_SOURCES) -lboost_serialization -I. -g -o server.out -pthread
client:
	g++ -std=c++0x Communication/client.cpp $(COMMON_SOURCES) -lboost_serialization -I. -g -o client.out -pthread
