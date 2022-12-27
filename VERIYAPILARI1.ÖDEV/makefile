all: build run

build:
	g++ -I ./include/ -o ./lib/Exception.o -c ./src/Exception.cpp
	g++ -I ./include/ -o ./lib/SatirListesiNode.o -c ./src/SatirListesiNode.cpp
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp
	g++ -I ./include/ -o ./lib/ReadAndAdd.o -c ./src/ReadAndAdd.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesiNode.o -c ./src/YoneticiListesiNode.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./lib/ScreenLayout.o -c ./src/ScreenLayout.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Exception.o ./lib/SatirListesiNode.o ./lib/SatirListesi.o ./lib/ReadAndAdd.o ./lib/YoneticiListesiNode.o ./lib/YoneticiListesi.o ./lib/ScreenLayout.o ./src/test.cpp

run: 
	./bin/test