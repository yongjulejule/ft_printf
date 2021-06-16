CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIB = libft.a
LIBDIR = libft
SRCS = ft_printf.c\
	   ft_print_str.c\
	   ft_print_width.c\
	   ft_print_char.c\
	   ft_print_deci.c\
	   ft_print_deci_nbr.c\
	   ft_print_sign.c\
	   get_flags.c\
	   get_asterisk_info.c\
	   get_nbr_len.c\
	   go_print.c\
	   lsts.c\
	   parse.c\
	   ft_putnbr_char_fd.c\
	   ft_putnbr_l_fd.c\
	   ft_putnbr_ll_fd.c\
	   ft_putnbr_short_fd.c\
	   ft_putnbr_uchar_fd.c\
	   ft_putnbr_ui_fd.c\
	   ft_putnbr_ul_fd.c\
	   ft_putnbr_ull_fd.c\
	   ft_putnbr_ushort_fd.c\
	   ft_putnbr_abs_fd.c\
	   ft_putstr_uft_fd.c\
	   is_this_length.c\

OBJS = ${SRCS:.c=.o}

BONUS_SRCS = ${SRCS}\
		
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

#%.o : %.c
#	$(CC) -c $(CFLAGS) $< -o $@  -I./ft_printf.h -I./$(LIBDIR)

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
	./a.out
