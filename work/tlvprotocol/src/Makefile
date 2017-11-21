EXEC=main
CXXFLAGS=-g -Wall -std=c++11

SRCS=$(wildcard *.cpp tlvprotocol/*.cpp)
OBJS=$(SRCS:.cpp=.o)

all:$(OBJS)
	g++ -o $(EXEC) $(OBJS)
	@echo build succ
.cpp .o:
	g++ -o $@ -c $<
clean:
	@rm -f $(OBJS) $(EXEC)
