all:
	g++ -o RVMTest RVMTest.cpp
	g++ -o ENVTest ENVTest.cpp
	g++ -o ExceptionsTest ExceptionsTest.cpp ../Exceptions.cpp
	g++ -o ProjectTest ProjectTest.cpp ../Project.cpp ../Exceptions.cpp
	g++ -o ConfigFileTest ConfigFileTest.cpp ../ConfigFile.cpp ../Project.cpp ../Exceptions.cpp
debug:
	g++ -o RVMTest RVMTest.cpp -g                  
	g++ -o ENVTest ENVTest.cpp -g
	g++ -o ExceptionsTest ExceptionsTest.cpp ../Exceptions.cpp -g
	g++ -o ProjectTest ProjectTest.cpp ../Project.cpp ../Exceptions.cpp -g
	g++ -o ConfigFileTest ConfigFileTest.cpp ../ConfigFile.cpp ../Project.cpp ../Exceptions.cpp -g
clean:                                                                                 
	rm -rf RVMTest ENVTest ExceptionsTest ProjectTest ConfigFileTest
