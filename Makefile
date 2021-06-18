CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIB = libft.a
LIBDIR = libft
SRCS = \
	   ft_printf.c\
	   ft_print_str.c\
	   ft_print_width.c\
	   ft_print_char.c\
	   ft_print_deci.c\
	   ft_print_deci_nbr.c\
	   ft_print_sign.c\
	   get_flags.c\
	   get_asterisk_info.c\
	   get_nbr_len.c\
	   get_length_flag.c\
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
	   go_print.c\
	   lsts.c\
	   parse.c\
	   ft_utflen.c\
	   ft_print_hash.c\
	   ft_print_hexa.c\
	   ft_print_hexa_nbr.c\
	   ft_putnbr_uchar_hexa_fd.c\
	   ft_putnbr_ui_hexa_fd.c\
	   ft_putnbr_ul_hexa_fd.c\
	   ft_putnbr_ull_hexa_fd.c\
	   ft_putnbr_ushort_hexa_fd.c\
	   ft_handle_n_spec.c\
	   get_byte.c\

OBJS = ${SRCS:.c=.o}

BONUS_SRCS = ${SRCS}\

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

#%.o : %.c
#	$(CC) -c $(CFLAGS) $< -o $@  -I./ft_printf.h -I./$(LIBDIR)

.PHONY: all
all: $(NAME) #clean

$(NAME) : $(OBJS) $(LIB)
	ar rc $@ $(OBJS) 

$(LIB):
	make -C $(LIBDIR)
	cp $(LIBDIR)/$(LIB) $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIBDIR) clean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: $(NAME) 

debug: all clean 
	$(CC) -g3 -fsanitize=address $(MAIN) $(SRCS) $(LIBDIR)/$(LIB)
	./a.out

leaks: clean
	$(CC) -g $(MAIN) $(SRCS) $(LIBDIR)/$(LIB)
