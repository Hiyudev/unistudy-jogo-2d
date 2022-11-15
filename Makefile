CC = g++
CFLAG = -std=c++17
FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
FILES = *.cpp src/*.cpp src/**/*.cpp src/class/**/*.cpp
TARGET = Jogoapp

all:
	rm -f *.o
	$(CC) $(CFLAG) -c $(FILES)
	$(CC) $(CFLAG) *.o -o $(TARGET) $(FLAGS)
