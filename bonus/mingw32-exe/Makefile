SRC = ../../src/*/*.cpp \
../../src/*/*/*.cpp \
../../src/*/*/*/*.cpp \

CXX = g++

CXXFLAGS =

NAME = bomberman.exe

LDFLAGS = -lIrrlicht -lsfml-audio

all:	$(NAME)

$(NAME):
		$(CXX) -o $(NAME) $(SRC) $(LDFLAGS) $(CXXFLAGS)

clean:
		$(RM) $(NAME)

re: clean all

dbg: CXXFLAGS += -g -O0
dbg: re