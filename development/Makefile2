CMP = g++ -std=c++11
MAIN = main
EXEC = go
CLASS1 = player
CLASS2 = college

$(EXEC): $(MAIN).o $(CLASS1).o
	$(CMP) $(CLASS1).o $(CLASS2).o $(MAIN).o -o $(EXEC)

$(MAIN).o: $(MAIN).cpp $(CLASS1).h
	$(CMP) -c $(MAIN).cpp -o $(MAIN).o

$(CLASS1).o: $(CLASS2).o $(CLASS1).h $(CLASS1).cpp
	$(CMP) -c $(CLASS1).cpp -o $(CLASS1).o

$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h
	$(CMP) -c $(CLASS2).cpp -o $(CLASS2).o

clean:
	rm *.o
	rm $(EXEC)P = g++
MAIN = main

