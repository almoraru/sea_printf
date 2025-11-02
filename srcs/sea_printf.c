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
/*                                                                            */
/*      Filename: sea_printf.c                                                */
/*      By: espadara <espadara@pirate.capn.gg>                                */
/*      Created: 2025/11/02 14:18:18 by espadara                              */
/*      Updated: 2025/11/02 14:18:27 by espadara                              */
/*                                                                            */
/* ************************************************************************** */

#include "sea_printf.h"

int	sea_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);

	// 1. Loop through the format string
	// 2. If you find a '%', parse the conversion
	// 3. Else, write the character

	// For now, this just prints the format string as a test
	count = sea_strlen(format);
	write(1, format, count);

	va_end(args);
	return (count);
}
