CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra
SRC = src/*.cpp
TARGET = app.exe

all:
	$(CXX) $(SRC) $(CXXFLAGS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f app.exe app *.o