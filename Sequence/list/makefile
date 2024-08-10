CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = myprogram

SRCS = main.cpp list.cpp node.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
