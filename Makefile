all:
	g++ -o ardtool ardtool.cpp ConfigFile.cpp Project.cpp Exceptions.cpp
debug:
	g++ -o ardtool ardtool.cpp ConfigFile.cpp Project.cpp Exceptions.cpp -g
install:
	cp ardtool /usr/bin
	mkdir -p $(HOME)/.ardtool
	cp config.example $(HOME)/.ardtool
userset:
	mkdir -p $(HOME)/.ardtool
	cp config.example $(HOME)/.ardtool
userunset:
	rm -rf $(HOME)/.ardtool
uninstall:
	rm /usr/bin/ardtool
	rm -rf $(HOME)/.ardtool
clean:
	rm -rf ardtool
