SRC = ../../src/*/*.cpp \
../../src/*/*/*.cpp \
../../src/*/*/*/*.cpp \

CXX = g++

CXXFLAGS =

NAME = bomberman.exe

LDFLAGS = -lIrrlicht -lsfml-audio

all:	$(NAME)

$(NAME):
		$(CXX) -o $(NAME) $(SRC) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
