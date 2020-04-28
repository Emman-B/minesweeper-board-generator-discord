EXECBIN = minesweeper_boardgen
SOURCES = main.cpp

all:
	g++ -std=c++17 -o ${EXECBIN} ${SOURCES}