# Colour
C = \033[0;36m
R = \033[0;91m
P = \033[1;95m
G = \033[4;32m
E = \033[0m

# Name
PROG := run

# Sources
SRCS :=	main.cpp Entity.cpp Enemy.cpp Player.cpp Bullet.cpp

# Object
OBJS :=	$(SRCS:.cpp=.o)

# Flag
CXXFLAGS :=	-Wall -Werror -Wextra -std=c++98
CXXFLAGS :=	-std=c++98

# C++ Compiler
CXX := clang++

# Build
$(PROG): $(OBJS)
	@$(CXX) $(OBJS) -lncurses -o $@
	@echo "$(G)Done!$(E)"

%.o:%.c
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# All
all: $(PROG)

# Clean
clean:
			@rm -f $(OBJS)
			@echo "$(R)Cleaned!$(E)"
fclean:     clean
			@rm -f $(PROG)
			@echo "$(P)Cleaned Everything!$(E)"

# Rebuild
re:			fclean all

# Redundency | GNU still runs if files with names below exist
.PHONY:
			all clean fclean re