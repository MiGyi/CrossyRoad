CXX      := -g++
CXXFLAGS := -O2 -Wall -Wno-missing-braces
LDFLAGS  := -L ../lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
BUILD    := build
TARGET   := Game.exe
INCLUDES  := -I ../include/ 
SRC      :=                      \
   $(wildcard ../src/*.cpp)         \
   $(wildcard ../src/COBJECT/*.cpp) \
   $(wildcard ../src/Helper/*.cpp) \

default:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(OBJ) $(INCLUDES) $(LDFLAGS)