NAME			= ft_containers

SRCS_FT			= ft_main.cpp
SRCS_STD		= speed_test.cpp
SRCS_INTRA		= main_intra.cpp

hpp				= iterator/*.hpp map.hpp set.hpp stack.hpp vector.hpp

OBJS			= $(SRCS_FT:.cpp=.o)
OBJS_STD		= $(SRCS_STD:.cpp=.o)
OBJS_INTRA		= $(SRCS_INTRA:.cpp=.o)

CXX				= clang++
CXXFLAGS		= -g -std=c++98 -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(hpp)
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp
	@printf "\x1b[32m"
	$(CXX) $(CXXFLAGS)

speed: $(OBJS_STD) $(hpp)
	@$(CXX) $(OBJS_STD) -o $@

intra: $(OBJS_INTRA) $(hpp)
	@$(CXX) $(OBJS_INTRA) -o $@

%.o: %.cpp
	@printf "\x1b[32m"
	$(CXX) $(CXXFLAGS) -o $@ -c $<
	@printf "\033[0m"

clean:

	@rm -f $(OBJS) $(OBJS_STD) $(OBJS_INTRA)
	@echo "\033[31m [INFO] Objects removed! \033[0m"

fclean: clean
	@rm -f $(NAME) ./speed ./intra
	@echo "\033[31m [INFO] $(NAME) removed! \033[0m"

re:     fclean all

.PHONY: all clean fclean format re