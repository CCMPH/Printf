NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

FILES = ft_printf.c ft_printf_conversions.c ft_printf_utils.c 

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "Create archive file $@"

%.o:%.c ft_printf.h
	@$(CC) $(CFLAGS) -c $<
	@echo "Compiling $@"

clean:
	$(RM) $(OBJS)
	@echo "Removing object files"

normi: $(FILES)
	norminette $(FILES)

fclean: clean
	$(RM) $(NAME)
	@echo "Removing archive file"

re: fclean all

.PHONY: all, clean, fclean, re, normi