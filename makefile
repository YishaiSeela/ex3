all: server client

COMMON_SOURCES = CabDecorator.cpp CabDecorator.h Driver.cpp Driver.h EventNotifier.cpp \
	EventNotifier.h MatchinStrategy.cpp MatchinStrategyTest.h LuxuryCab.cpp LuxuryCab.h OrderManager.cpp OrderManager.h \
	Passanger.cpp Passanger.h Person.cpp Person.h Point.cpp Point.h Ride.cpp Ride.h Vehicle.cpp Vehicle.h \
	BfsSearch.cpp BfsSearch.h Grid.cpp Grid.h Node.cpp Node.h StringParse.cpp StringParse.h test.h \
	Parser.cpp Parser.h RegularCab.cpp RegularCab.h Udp.cpp Udp.h Socket.cpp Socket.h
server:
	g++ -std=c++0x server.cpp $(COMMON_SOURCES) -lboost_serialization -I. -o server.out
client:
	g++ -std=c++0x client.cpp $(COMMON_SOURCES) -lboost_serialization -I. -o client.out
