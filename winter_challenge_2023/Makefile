NAME		=	../codingame_sync_file
BINARY		=	compiled

CXX			=	g++ -std=c++14

CPPFLAGS	=	-MMD
CXXFLAGS	=	-Wall -Wextra #-Werror

#ADD YOUR SOURCES BELOW WITHOUT THE SOURCE PREFIX MAIN.C GIVEN AS EXAMPLE
SRCS		=	class/Game/Game.cpp									\
				class/Data/Data.cpp									\
				class/Data/distance.cpp								\
				class/Data/biggest_radar_direction.cpp				\
				class/Data/count_no_scaned.cpp						\
				class/Data/get_drone_zone.cpp						\
				class/Data/get_round_move.cpp						\
				class/Data/get_limite_zone.cpp						\
				class/Data/is_scanned.cpp							\
				class/Data/is_full_scanned.cpp						\
				class/Data/get_type_scanned.cpp						\
				class/Data/calculate_advantage_score.cpp			\
				class/Data/calculate_score_at_drones_pos_zero.cpp	\
				class/Stock/Stock.cpp								\
				class/Node/Node.cpp									\
				distance_tuple.cpp									\
				instruction_move.cpp								\
				instruction_wait.cpp								\
				choice_pos.cpp										\
				get_real_pos.cpp									\
				choice_light.cpp									\
				enum_to_str.cpp										\
				main.cpp											\

#IF YOU HAVE HEADER FILES YOU ABSOLUTELY NEED TO ADD THEM IN THE INC_FILES VAR
INC_FILES	= 	utils.hpp											\
				class/Data.hpp										\
				class/Game.hpp										\
				class/Node.hpp										\
				class/Stock.hpp										\
				header.hpp											\

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