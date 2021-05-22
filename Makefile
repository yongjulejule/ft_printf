CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIB = libft.a
LIBDIR = libft
SRCS = ft_printf.c\
	   get_flags.c\
	   get_flags2.c\
	   lsts.c\
	   parse.c

OBJS = ${SRCS:.c=.o}

BONUS_SRCS = ${SRCS}\
		
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

.PHONY: all
all: $(NAME)

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

