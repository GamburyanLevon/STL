CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = myprogram

SRCS = main.cpp vector.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
