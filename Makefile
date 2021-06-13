CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIB = libft.a
LIBDIR = libft
SRCS = ft_printf.c\
	   ft_print_str.c\
	   ft_print_width.c\
	   get_flags.c\
	   get_asterisk_info.c\
	   go_print.c\
	   lsts.c\
	   parse.c\

OBJS = ${SRCS:.c=.o}

BONUS_SRCS = ${SRCS}\
		
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

.PHONY: all
all: $(NAME) #clean

$(NAME) : $(OBJS) $(LIB)
	ar rc $@ $(OBJS) $(LIBDIR)/$(LIB)

$(LIB):
	cd $(LIBDIR); make bonus; cd ..

.PHONY: clean
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	cd $(LIBDIR); make clean; cd ..
.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR); rm -f $(LIB); cd ..

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: $(BONUS_OBJS)
	ar cr $(NAME) $(BONUS_OBJS)

debug: clean 
	$(CC) -g3 -fsanitize=address $(MAIN) $(SRCS) $(LIBDIR)/$(LIB)
