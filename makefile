SRC=nn11.cpp mat.cpp rand.cpp
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	g++ -o nn11 $^

%.o: %.cpp
	g++ -c -o $@ $<

clean:
	rm -f *.o
	rm nn11

tar:
	tar -cvf ab.tar makefile mat.h rand.h $(SRC)
	ls -l ab.tar
