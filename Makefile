NAME		:= ComputorV1

CXX			:= g++
CXXFLAGS	:= -std=c++11 -Wall -Werror -Wextra

# Folders
SRC_DIR		= ./srcs/
INC_DIR		= ./includes/
OBJ_DIR		= ./obj/

SRCS_FILES	:= main.cpp treatment.cpp computor.cpp usage.cpp solve.cpp

HDRS_FILES	:= computor.hpp

OBJS_FILES	:= $(SRCS_FILES:.cpp=.o)

SRCS		:= $(addprefix $(SRC_DIR), $(SRCS_FILES))
HDRS		:= $(addprefix $(INC_DIR), $(HDRS_FILES))
OBJS		:= $(addprefix $(OBJ_DIR), $(OBJS_FILES))

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@$(CXX) $(CXXFLAGS) -o $@ -c $< -I $(INC_DIR)

$(NAME): $(OBJS) $(HDRS)
	@clear
	@echo "\033[38;5;196m===ComputorV1 : Compilation...\033[0m"
	@echo "\033[38;5;196m[                              ]\033[0m"
	@$(CXX) $(OBJS) -o $@
	@sleep 0.2
	@clear
	@echo "\033[38;5;196m===ComputorV1 : Compilation...\033[0m"
	@echo "\033[38;5;196m[======                        ]\033[0m"
	@sleep 0.2
	@clear
	@echo "\033[38;5;196m===ComputorV1 : Compilation...\033[0m"
	@echo "\033[38;5;196m[============                  ]\033[0m"
	@sleep 0.2
	@clear
	@echo "\033[38;5;196m===ComputorV1 : Compilation...\033[0m"
	@echo "\033[38;5;196m[==================            ]\033[0m"
	@sleep 0.2
	@clear
	@echo "\033[38;5;196m===ComputorV1 : Compilation...\033[0m"
	@echo "\033[38;5;196m[========================      ]\033[0m"
	@sleep 0.2
	@clear
	@echo "\033[38;5;196m===ComputorV1 : Compilation...\033[0m"
	@echo "\033[38;5;196m[==============================]\033[0m"
	@echo "\033[38;5;196m===ComputorV1 : Done\033[0m"


clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[38;5;40m[✓] \033[38;5;15m Removed object files"

fclean:clean
	@rm -f $(NAME)
	@echo "\033[38;5;40m[✓] \033[38;5;15m Removed executable" $(NAME)

re:fclean all

.PHONY: all clean fclean format re
