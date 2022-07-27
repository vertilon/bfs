build: main.cpp utils.cpp utils.h
	g++ --std=c++17 main.cpp utils.cpp	
test: a.out sample.txt
	cat sample.txt| ./a.out	
