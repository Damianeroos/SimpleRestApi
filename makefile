LDFLAGS = -lcpprest -lpthread -lboost_system -lssl -lcrypto

__start__ : a.out
	./a.out

a.out: main.o Controller.o
	g++ main.o Controller.o $(LDFLAGS)

main.o: main.cpp Controller.hh
	g++ -c -Wall -pedantic main.cpp

Controller.o: Controller.hh Controller.cpp
	g++ -c -Wall -pedantic Controller.cpp

clean:
	-rm *.o *.gch a.out