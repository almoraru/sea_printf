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
/*      Updated: 2025/11/02 14:35:26 by espadara                              */
/*                                                                            */
/* ************************************************************************** */

#include "sea_printf.h"

int	sea_printf(const char *format, ...){
  t_sea_state state;

  state.arena = sea_arena_init(0); //4096 by default
  if (!state.arena)
    return (-1);
  state.total_len = 0;
  va_start(state.args, format);
  while (*format)
    {
      if (*format == '%')
        {
          format++;
          sea_reset_flags(&state.flags);
          sea_parse_flags(&format, &state);
          seas_parse_conversion(&format, &state);
        } else {
        sea_putchar_fd(*format, 1);
        state.total_len++;
      }
      format++;
    }
  va_end(state.args);
  sea_arena_free(state.arena);
	return (count);
}
