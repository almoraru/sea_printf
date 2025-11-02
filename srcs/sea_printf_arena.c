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
/*      Filename: sea_printf_arena.c                                          */
/*      By: espadara <espadara@pirate.capn.gg>                                */
/*      Created: 2025/11/02 15:08:47 by espadara                              */
/*      Updated: 2025/11/02 15:09:32 by espadara                              */
/*                                                                            */
/* ************************************************************************** */

#include "sea_printf.h"

static int	count_digits_base(unsigned long long n, int base_len)
{
  int	count = 1;
  while (n >= (unsigned long long)base_len)
	{
      n /= base_len;
      count++;
	}
  return (count);
}

char	*sea_arena_utoa_base(t_sea_state *state, unsigned long long n,
		char *base_chars)
{
  int		base_len;
  int		len;
  char	*str;

  base_len = sea_strlen(base_chars);
  len = count_digits_base(n, base_len);
  str = sea_arena_alloc(state->arena, len + 1);
  if (!str)
    return (NULL);
  str[len] = '\0';
  while (len-- > 0)
	{
      str[len] = base_chars[n % base_len];
      n /= base_len;
	}
  return (str);
}

char	*sea_arena_itoa(t_sea_state *state, long long n)
{
  char				*str;
  int					len;
  unsigned long long	num;
  int					is_neg;

  is_neg = (n < 0);
  num = (n < 0) ? -n : n;
  len = count_digits_base(num, 10);
  if (is_neg)
    len++;
  str = sea_arena_alloc(state->arena, len + 1);
  if (!str)
    return (NULL);
  str[len] = '\0';
  while (len-- > 0)
	{
      str[len] = (num % 10) + '0';
      num /= 10;
	}
	if (is_neg)
      str[0] = '-';
	return (str);
}
