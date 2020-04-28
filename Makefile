EXECBIN = minesweeper_boardgen
SOURCES = src/main.cpp

all:
	g++ -std=c++17 -o ${EXECBIN} ${SOURCES}