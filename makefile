all: server client

COMMON_SOURCES = CabDecorator.cpp Driver.cpp EventNotifier.cpp \
	MatchinStrategy.cpp LuxuryCab.cpp OrderManager.cpp \
	Passanger.cpp Person.cpp Point.cpp Ride.cpp Vehicle.cpp \
	BfsSearch.cpp Grid.cpp Node.cpp StringParse.cpp \
	Parser.cpp RegularCab.cpp Udp.cpp Socket.cpp
server:
	g++ -std=c++0x server.cpp $(COMMON_SOURCES) -lboost_serialization -I. -g -o server.out
client:
	g++ -std=c++0x client.cpp $(COMMON_SOURCES) -lboost_serialization -I. -g -o client.out
