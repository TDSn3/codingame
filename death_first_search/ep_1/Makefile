NAME		=	../codingame_sync_file
BINARY		=	compiled

CXX			=	g++

CPPFLAGS	=	-MMD
CXXFLAGS	=	-Wall -Wextra #-Werror

SRCS		=	class/Vertex.cpp	\
				class/Data.cpp		\
				main.cpp			\

INC_FILES	= 	header.hpp			\
				class/Vertex.hpp	\
				class/Data.hpp		\

INC_PATH	=	includes/
INC			=	-I $(INC_PATH)


SRCS_PATH	=	./sources/
OBJS_PATH	=	./objects/

OBJS		=	$(addprefix $(OBJS_PATH), $(SRCS:.cpp=.o))
DEPS		=	$(OBJS:.o=.d)


all: $(NAME)

$(NAME):	$(addprefix $(INC_PATH), $(INC_FILES)) $(addprefix $(SRCS_PATH), $(SRCS))
			@cat $^ | grep -v '#\s*include\s*"' > $(NAME)
			make $(BINARY)
			@echo "Created merged file"

$(BINARY): $(OBJS)
			$(CXX) $(CXXFLAGS) $^ -o $(BINARY) $(INC)


$(OBJS_PATH):
				mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.cpp
					@mkdir -p $(dir $@)
					$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@ $(INC)


clean:
		rm -rf $(OBJS_PATH)

fclean:		clean
		rm -rf $(NAME)

re:	fclean
	make all


.PHONY: all clean fclean re test vtest

-include $(DEPS)

#
# MIT License
# 
# Copyright (c) 2022 aweaver
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
