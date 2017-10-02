CXX = g++
CXXFLAGS += -std=c++11
LOADLIBES += -lstdc++
ENIGMA_SOURCES = Enigma.cpp
PLUGBOARD_SOURCES = Plugboard.cpp
REFLECTOR_SOURCES = Reflector.cpp
ROTOR_SOURCES = Rotor.cpp
OBJECT_FILES = Encodable.o rotor.o plugboard.o reflector.o enigma.o Main.o

all: $(OBJECT_FILES)
	 $(CXX) $(OBJECT_FILES) $(CXXFLAGS) -o enigma

Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c Main.cpp -o Main.o

Encodable.o: Encodable.cpp
	$(CXX) $(CXXFLAGS) -c Encodable.cpp -o Encodable.o

enigma.o: $(ENIGMA_SOURCES)
	$(CXX) $(CXXFLAGS) -c $(ENIGMA_SOURCES) -o enigma.o

plugboard.o: $(PLUGBOARD_SOURCES)
	$(CXX) $(CXXFLAGS) -c $(PLUGBOARD_SOURCES) -o plugboard.o

reflector.o: $(REFLECTOR_SOURCES)
	$(CXX) $(CXXFLAGS) -c $(REFLECTOR_SOURCES) -o reflector.o

rotor.o: $(ROTOR_SOURCES)
	$(CXX) $(CXXFLAGS) -c $(ROTOR_SOURCES) -o rotor.o
	
clean:
	rm -rf enigma *.o

.PHONY: clean
