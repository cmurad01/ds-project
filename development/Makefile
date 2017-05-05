CMP = g++ -std=c++11
CLASS = player
SUB1 = college
MAIN = main
EXEC = main

$(EXEC): $(MAIN).cpp $(CLASS).o $(SUB1).o
		$(CMP) $^ -o $@

$(CLASS).o: $(CLASS).cpp $(CLASS).h
		$(CMP) -c $(CLASS).cpp -o $(CLASS).o

$(SUB1).o: $(SUB1).cpp $(SUB1).h
		$(CMP) -c $(SUB1).cpp -o $(SUB1).o

clean:
				rm *.o
				rm $(EXEC)
