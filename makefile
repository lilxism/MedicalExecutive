CXX =g++
CXXFLAGS=-Wall -g

main: main.o City.o OrderedList.o MedicalExecutive.o
	$(CXX) $(CXXFLAGS) -o main main.o City.o OrderedList.o MedicalExecutive.o -std=c++0x
	
main.o: main.cc MedicalExecutive.h OrderedList.h City.h
	$(CXX) $(CXXFLAGS) -c main.cc -std=c++0x

MedicalExecutive.o: MedicalExecutive.h OrderedList.h City.h
	$(CXX) $(CXXFLAGS) -c MedicalExecutive.cc -std=c++0x

OrderedList.o: OrderedList.h City.h 
	$(CXX) $(CXXFLAGS) -c OrderedList.cc -std=c++0x

City.o: City.h
	$(CXX) $(CXXFLAGS) -c City.cc -std=c++0x

clean: 
	$(RM) main *.o *~
