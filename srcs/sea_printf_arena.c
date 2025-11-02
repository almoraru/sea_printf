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
/*      Updated: 2025/11/02 15:39:45 by espadara                              */
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

char	*sea_arena_ftoa(t_sea_state *state, double d, int *out_len)
{
  int			prec;
  double		rounder;
  long long	int_part;
  double		frac_part;
  char		*int_str;
  int			int_len;
  char		*final_str;
  char		*p;
  int			i;

  prec = 6;
  if (state->flags.bits & FLAG_HAS_PRECISION)
    prec = state->flags.precision;
  rounder = 0.5;
  i = 0;
  while (i++ < prec)
    rounder /= 10.0;
  d += rounder;
  int_part = (long long)d;
  frac_part = d - (double)int_part;
  int_str = sea_arena_itoa(state, int_part);
  int_len = sea_strlen(int_str);
  if (int_str[0] == '-')
    int_len--;
  *out_len = int_len + (prec > 0 || (state->flags.bits & FLAG_HASH) ? 1 : 0) + prec;
  final_str = sea_arena_alloc(state->arena, *out_len + 1);
  p = final_str;
  sea_memcpy_fast(p, int_str, int_len + (int_str[0] == '-'));
  p += int_len + (int_str[0] == '-');
  if (prec > 0 || (state->flags.bits & FLAG_HASH))
    *p++ = '.';
  i = 0;
  while (i++ < prec)
	{
      frac_part *= 10.0;
      *p++ = (int)frac_part + '0';
      frac_part -= (int)frac_part;
	}
  *p = '\0';
  return (final_str);
}
