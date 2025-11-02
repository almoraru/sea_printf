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
/*      Filename: sea_printf_bonus.c                                          */
/*      By: espadara <espadara@pirate.capn.gg>                                */
/*      Created: 2025/11/02 15:27:49 by espadara                              */
/*      Updated: 2025/11/02 15:29:18 by espadara                              */
/*                                                                            */
/* ************************************************************************** */

#include "sea_printf.h"

static int	sea_printf_atoi(const char **format)
{
  int	num;

  num = 0;
  while (sea_isdigit(**format))
    {
      num = num * 10 + (**format - '0');
      (*format)++;
	}
  return (num);
}

void	sea_parse_flags(const char **format, t_sea_state *state)
{
  while (**format)
	{
      if (**format == '-')
        state->flags.bits |= FLAG_MINUS;
      else if (**format == '0')
        state->flags.bits |= FLAG_ZERO;
      else if (**format == '#')
        state->flags.bits |= FLAG_HASH;
      else if (**format == ' ')
        state->flags.bits |= FLAG_SPACE;
      else if (**format == '+')
        state->flags.bits |= FLAG_PLUS;
      else
        break ;
      (*format)++;
	}
  if (state->flags.bits & FLAG_MINUS)
    state->flags.bits &= ~FLAG_ZERO;
  if (sea_isdigit(**format))
    state->flags.width = sea_printf_atoi(format);
  if (**format == '.')
	{
      state->flags.bits |= FLAG_HAS_PRECISION;
      (*format)++;
      state->flags.precision = sea_printf_atoi(format);
	}
}

void	sea_handle_width(t_sea_state *state, int len, int is_zero_padded)
{
	char	pad_char;
	int		i;

	if (state->flags.width <= len)
      return ;
	if (is_zero_padded && (state->flags.bits & FLAG_ZERO)
        && !(state->flags.bits & FLAG_MINUS))
      pad_char = '0';
	else
      pad_char = ' ';
	i = 0;
	while (i < state->flags.width - len)
      {
		sea_putchar_fd(pad_char, 1);
		i++;
      }
	state->total_len += i;
}

void	sea_handle_precision(t_sea_state *state, char **str, int *len, int is_neg)
{
  char	*new_str;
  int		new_len;
  int		i;
  int		j;

  if (!(state->flags.bits & FLAG_HAS_PRECISION)
      || state->flags.precision < *len)
    return ;
  new_len = state->flags.precision;
  if (is_neg)
    new_len++;
  new_str = sea_arena_alloc(state->arena, new_len + 1);
  if (!new_str)
    return ;
  new_str[new_len] = '\0';
  i = 0;
  j = 0;
  if (is_neg)
	{
      new_str[i++] = '-';
      j++;
      (*len)--;
	}
  while (i < new_len - *len)
    new_str[i++] = '0';
  sea_memcpy_fast(new_str + i, *str + j, *len);
  *str = new_str;
  *len = new_len;
}
