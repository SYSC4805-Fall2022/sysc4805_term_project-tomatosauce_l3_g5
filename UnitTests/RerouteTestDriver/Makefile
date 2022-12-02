all: rerouteTest

rerouteTest: rerouteTest.o
	g++ -o rerouteTest rerouteTest.o
rerouteTest.o: RerouteTestDriver.cpp Reroute.hpp AvoidObstacle.hpp
	g++ -c RerouteTestDriver.cpp