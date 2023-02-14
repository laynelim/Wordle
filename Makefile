play: play.o wordle.o
	g++ play.o wordle.o -o play

play.o: play.cc wordle.h
	g++ -std=c++14 -c play.cc

wordle.o: wordle.cc wordle.h
	g++ -std=c++14 -c wordle.cc
