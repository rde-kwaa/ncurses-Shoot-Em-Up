# Colour
C = \033[0;36m
R = \033[0;91m
P = \033[1;95m
G = \033[4;32m
E = \033[0m

# Compiler
CXX          := clang++

# The Target Binary Program
TARGET      := ft_retro

# The Directories, Source, Includes, Objects and Binary
SRCDIR      := src
INCDIR      := inc
OBJDIR      := obj
TARGETDIR   := bin
SRCEXT      := cpp
DEPEXT      := d
OBJEXT      := o

#Flags, Libraries and Includes
CXXFLAGS    := -std=c++98 -Wall -Werror -Wextra -pedantic
LIB         := -lncurses
INC         := -I$(INCDIR) -I/usr/local/include
INCDEP      := -I$(INCDIR)

SRCS     := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJS     := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRCS:.$(SRCEXT)=.$(OBJEXT)))

#Defauilt Make
all: directories $(TARGET)

# Rebuild
re: fclean all

# Make the Directories
directories:
	@mkdir -p $(OBJDIR)

# Cleaners
# clean
clean:
	@$(RM) -rf $(OBJDIR)
	@echo "$(R)Cleaned!$(E)"

# fclean
fclean:     clean
	@$(RM) -rf $(TARGET)
	@echo "$(P)Cleaned Everything!$(E)"

# debug:
	# clang++ EntityDebug.cpp ./src/Entity.cpp ./src/Player.cpp ./src/Bullet.cpp ./src/Enemy.cpp -o debugEntity

#Pull in dependency info for *existing* .o files
-include $(OBJS:.$(OBJEXT)=.$(DEPEXT))

#Link
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $^ $(LIB)
	@echo "$(G)Done!$(E)"

#Compile
$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<
	@$(CXX) $(CXXFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(OBJDIR)/$*.$(DEPEXT)
	@cp -f $(OBJDIR)/$*.$(DEPEXT) $(OBJDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(OBJDIR)/$*.$(OBJEXT):|' < $(OBJDIR)/$*.$(DEPEXT).tmp > $(OBJDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(OBJDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(OBJDIR)/$*.$(DEPEXT)
	@rm -f $(OBJDIR)/$*.$(DEPEXT).tmp

# Redundency | GNU still runs if files with names below exist
.PHONY: all re clean fclean
