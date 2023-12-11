# makefile for libftprintf

# source files for libftprintf
SRC		=	ft_printf.c					\
			handle_c.c					\
			handle_diu.c				\
			handle_p.c					\
			handle_xX.c					\
			handle_percent.c			\
			handle_s.c					\
			scan_str.c					\
			placeholders.c				\

# object files for libftprintf
OBJECTS	= $(SRC:.c=.o)

# name of libftprintf static library
NAME = libftprintf.a

# compiler and flags
CC = cc
CCFLAGS = -Wall -Wextra -Werror

# force remove
RM = rm -f

# default rule
all: $(NAME) 

# rule to build libftprintf static library
$(NAME): $(OBJECTS)
	@ar -rsc $(NAME) $(OBJECTS)

# rule to build object files for libftprintf
$(OBJECTS): 
	$(CC) $(CCFLAGS) -c $(SRC)

# rule to clean up object files
clean: 
	$(RM) $(OBJECTS)
#	cd libft && $(MAKE) clean

# rule to clean up object files and libftprintf static library
fclean: clean
	$(RM) $(NAME)

# rule to rebuild all
re: fclean all