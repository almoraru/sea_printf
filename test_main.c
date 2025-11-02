/* ************************************************************************** */
/*                                                                            */
/*                        ______                                              */
/*                     .-"      "-.                                           */
/*                    /            \                                          */
/*        _          |              |          _                              */
/*       ( \         |,  .-.  .-.  ,|         / )                             */
/*        > "=._     | )(__/  \__)( |     _.=" <                              */
/*       (_/"=._"=._ |/     /\     \| _.="_.="\_)                             */
/*              "=._ (_     ^^     _)"_.="                                    */
/*                  "=\__|IIIIII|__/="                                        */
/*                 _.="| \IIIIII/ |"=._                                       */
/*       _     _.="_.="\          /"=._"=._     _                             */
/*      ( \_.="_.="     `--------`     "=._"=._/ )                            */
/*       > _.="                            "=._ <                             */
/*      (_/                                    \_)                            */
/*      Created: 2025/11/02 14:14:49 by espadara                              */
/*      Updated: 2025/11/02 14:17:34 by espadara                              */
/*                                                                            */
/* ************************************************************************** */

#include "sea_printf.h"
#include <stdio.h>

int	main(void)
{
  int	my_count;
  int	real_count;

	// --- Test 1 ---
	sea_printf("--- My sea_printf ---\n");
	my_count = sea_printf("Hello from sea_printf!\n");
	sea_printf("Characters printed (my count): ");
	sea_putnbr_fd(my_count, 1);
	sea_putchar_fd('\n', 1);

	// --- Test 2 ---
	printf("\n--- Real printf ---\n");
	real_count = printf("Hello from printf!\n");
	printf("Characters printed (real count): %d\n", real_count);

	return (0);
}
