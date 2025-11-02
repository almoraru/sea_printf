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
/*      Filename: sea_printf.h                                                */
/*      By: espadara <espadara@pirate.capn.gg>                                */
/*      Created: 2025/11/02 14:16:42 by espadara                              */
/*      Updated: 2025/11/02 14:17:32 by espadara                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEA_PRINTF_H
# define SEA_PRINTF_H


/* INCLUDES */
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/* SEA LIB */
# include "sealib.h"


/* PROTOTYPES  */
int	sea_printf(const char *format, ...);

#endif
