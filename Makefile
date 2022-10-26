CC = g++
FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
FILES = *.cpp src/*.cpp src/**/*.cpp
TARGET = Jogoapp

all: 
	$(CC) -std=c++17 -c $(FILES)    
	$(CC) -std=c++17 *.o -o $(TARGET) $(FLAGS)
