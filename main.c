#include <stdio.h>
#include "ft_printf.h"


int main()
{
	int i = 10;
	printf("============================!!!MY PRINTF!!!============================\n");
	printf("============================This is String!============================\n");
	ft_printf("MY  : |%*.*s|\n", 100, 5, "hello printf");
	printf("LIB : |%*.*s|\n", 100, 5, "hello printf");
	ft_printf("MY  : |%*.s|\n", 100, "hello printf");
	printf("LIB : |%*.s|\n", 100, "hello printf");
	ft_printf("MY  : |%*.7s|\n", 100, "hello printf");
	printf("LIB : |%*.7s|\n", 100, "hello printf");
	ft_printf("MY  : |%*.*s|\n", -100, 5, "hello printf");
	printf("LIB : |%*.*s|\n", -100, 5, "hello printf");
	ft_printf("MY  : |%*.*s|\n", 100, 0, "hello printf");
	printf("LIB : |%*.*s|\n", 100, 0, "hello printf");
	ft_printf("MY  : |%0*.*s|\n", 100, 5, "hello printf");
	printf("LIB : |%0*.*s|\n", 100, 5, "hello printf");
	ft_printf("MY  : |%--*.*s|\n", 100, 5, "hello printf");
	printf("LIB : |%--*.*s|\n", 100, 5, "hello printf");
	printf("============================This is Charactor!=========================\n");
	ft_printf("MY  : |%*c|\n", 100, 'R');
	printf("LIB : |%*c|\n", 100, 'R');
	ft_printf("MY  : |%*.c|\n", 100, 'R');
	printf("LIB : |%*.c|\n", 100, 'R');
	ft_printf("MY  : |%*.7c|\n", 100, 'R');
	printf("LIB : |%*.7c|\n", 100, 'R');
	ft_printf("MY  : |%*.*c|\n", -100, 5, 'R');
	printf("LIB : |%*.*c|\n", -100, 5, 'R');
	ft_printf("MY  : |%*.*c|\n", 100, 0, 'R');
	printf("LIB : |%*.*c|\n", 100, 0, 'R');
	ft_printf("MY  : |%0*.*c|\n", 100, 5, 'R');
	printf("LIB : |%0*.*c|\n", 100, 5, 'R');
	ft_printf("MY  : |%--*.*c|\n", 100, 5, 'R');
	printf("LIB : |%--*.*c|\n", 100, 5, 'R');
	printf("============================This is Dedimal!=========================\n");
	ft_printf("MY  : |%d|\n", -123);
	printf("LIB : |%d|\n",  -123);
	ft_printf("MY  : |%.100d|\n", -123);
	printf("LIB : |%.100d|\n",  -123);
	ft_printf("MY  : |%*d|\n", 100, -123);
	printf("LIB : |%*d|\n", 100, -123);
	ft_printf("MY  : |%0*d|\n", 100, -123);
	printf("LIB : |%0*d|\n", 100, -123);
	ft_printf("MY  : |%*.7d|\n", 100, -123);
	printf("LIB : |%*.7d|\n", 100, -123);
	ft_printf("MY  : |%0*.*d|\n", -100, 5, -123);
	printf("LIB : |%0*.*d|\n", -100, 5, -123);
	ft_printf("MY  : |%*.*d|\n", 100, 0, -123);
	printf("LIB : |%*.*d|\n", 100, 0, -123);
	ft_printf("MY  : |%0*.*d|\n", 100, 5, -123);
	printf("LIB : |%0*.*d|\n", 100, 5, -123);
	ft_printf("MY  : |%--*.*d|\n", 100, 5, -123);
	printf("LIB : |%--*.*d|\n", 100, 5, -123);
	ft_printf("MY  : |%d|\n", 4242);
	printf("LIB : |%d|\n",  4242);
	ft_printf("MY  : |%+0.100d|\n", 4242);
	printf("LIB : |%+0.100d|\n",  4242);
	ft_printf("MY  : |%*d|\n", 100, 4242);
	printf("LIB : |%*d|\n", 100, 4242);
	ft_printf("MY  : |%0+*d|\n", 100, 4242);
	printf("LIB : |%0+*d|\n", 100, 4242);
	ft_printf("MY  : |%*.7d|\n", 100, 4242);
	printf("LIB : |%*.7d|\n", 100, 4242);
	ft_printf("MY  : |%0 *.*d|\n", -100, 5, 4242);
	printf("LIB : |%0 *.*d|\n", -100, 5, 4242);
	ft_printf("MY  : |% +*.*d|\n", 100, 0, 4242);
	printf("LIB : |% +*.*d|\n", 100, 0, 4242);
	ft_printf("MY  : |% 0*.*d|\n", 100, 5, 4242);
	printf("LIB : |% 0*.*d|\n", 100, 5, 4242);
	ft_printf("MY  : |%+--*.*d|\n", 100, 5, 4242);
	printf("LIB : |%+--*.*d|\n", 100, 5, 4242);
//	ft_printf("ab%%%%%%%%%%cas|%s|글 자|%s|글 자|%s|\n\n\n",\
//			'H', "Hello", "\t", "world!");
//	ft_printf("really%-+0 *.123dbcsd%sdlkj%  000123.432dasdbfd%c\n", 10, "hello", 10, 'c');
	printf("==============decimal check==================\n");
	printf("%01d\n", -10);
	printf("|%-+30.10d|\n", 10);
	printf("%-d\n", 10);
	printf("|%*.*d|\n",15, 0, 10);
	printf("|%*.*d|\n", -15, 0, 10);
	printf("|%*.*d|\n",15, -1, 10);
	printf("|%*.*d|\n", -15, -1, 10);
	printf("% d\n", 10);
	printf("u opt is |%100uds|\n", -1);
	printf("|%100ds|\n", 100);
	printf("|%100ds|\n", 100);
	printf("==============float check==================\n");
	printf("%g\n", 10.1234);
	printf("return is %d\n",	printf("%- .500g\n", 10.424242));
	printf("%-e\n", 4242.42424242424242424242424242424);

	printf("==============string check=====================\n");
	printf("\n\n|%010.10c|\n\n",'a');
 //	printf("|%123*.41s|",  "THis is str",100, "hello");
 //	printf("|%*123.41s|",  "THis is str",100, "hello");
 //	printf("|%12*23.41s|",  "THis is str",100, "hello");
	
//	printf("|%123.*41s|",  "THis is str",100, "hello");
//	printf("|%123.4*1s|",  "THis is str",100, "hello");
//	printf("|%123.41*s|",  "THis is str",100, "hello");
	
//	printf("ERROR_CASE(FLAG)|%+100ss|\n", "THis is str");
//	printf("ERROR_CASE(NOT SPECIFIER)|%++++++00++++100Kds|\n", 100);

	printf("|%*.*s|\n", -100, -1, "hello");
	printf("|%++--++++++++100ds|\n", 100);
	printf("|%     00100ds|\n", 100);
	printf("|%++++++00++++100ds|\n", 100);
	printf("|%*s|\n",100, "isthis");
	printf("==============p, x, Xcheck=====================\n");
	printf("|%1$p| |%2$#x| |%2$#010X|\n", &i, (int)-31);

}
