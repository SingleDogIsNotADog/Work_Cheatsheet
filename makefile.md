**Makefile for c**

```
EXEC=main
CFLAGS=-g -Wall -std=c99

SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all:$(OBJS)
	g++ -o $(EXEC) $(OBJS)
	@echo build succ
.cpp .o:
	gcc -o $@ -c $<
clean:
	@rm -f $(OBJS) $(EXEC)
```

**Makefile for c++**

```
EXEC=main
CXXFLAGS=-g -Wall -std=c++11

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

all:$(OBJS)
	g++ -o $(EXEC) $(OBJS)
	@echo build succ
.cpp .o:
	g++ -o $@ -c $<
clean:
	@rm -f $(OBJS) $(EXEC)
```
