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
/*      Updated: 2025/11/02 15:37:17 by espadara                              */
/*                                                                            */
/* ************************************************************************** */

#include "sea_printf.h"
#include <stdio.h>
#include <math.h>

#define TEST_PRINTF(format, ...) \
	do { \
		int sea_ret, real_ret; \
		printf("--- Test Case ---\n"); \
		printf("Format: [%s]\n", format); \
		printf("sea_printf: "); \
		fflush(stdout); \
		sea_ret = sea_printf(format, __VA_ARGS__); \
		fflush(stdout); \
		printf("\n"); \
		printf("   printf: "); \
		fflush(stdout); \
		real_ret = printf(format, __VA_ARGS__); \
		fflush(stdout); \
		printf("\n"); \
		if (sea_ret == real_ret) \
			printf("Return: OK (sea: %d, real: %d)\n\n", sea_ret, real_ret); \
		else \
			printf("Return: FAIL (sea: %d, real: %d)\n\n", sea_ret, real_ret); \
	} while (0)

// A version for tests with no arguments
#define TEST_PRINTF_NO_ARGS(format) \
	do { \
		int sea_ret, real_ret; \
		printf("--- Test Case ---\n"); \
		printf("Format: [%s]\n", format); \
		printf("sea_printf: "); \
		fflush(stdout); \
		sea_ret = sea_printf(format); \
		fflush(stdout); \
		printf("\n"); \
		printf("   printf: "); \
		fflush(stdout); \
		real_ret = printf(format); \
		fflush(stdout); \
		printf("\n"); \
		if (sea_ret == real_ret) \
			printf("Return: OK (sea: %d, real: %d)\n\n", sea_ret, real_ret); \
		else \
			printf("Return: FAIL (sea: %d, real: %d)\n\n", sea_ret, real_ret); \
	} while (0)

int	main(void)
{
	char	*null_str = NULL;

	sea_printf("\n--- 🌊 SEA_PRINTF TESTS 🌊 ---\n\n");

	// --- Basic Tests ---
	TEST_PRINTF_NO_ARGS("Hello from sea_printf!\n");
	TEST_PRINTF_NO_ARGS("No conversions here.\n");
	TEST_PRINTF("A simple char: %c\n", 'A');
	TEST_PRINTF("A simple string: %s\n", "Hello World");
	TEST_PRINTF("A simple int: %d\n", 42);
	TEST_PRINTF("A simple hex: %x\n", 255);
	TEST_PRINTF("A simple ptr: %p\n", (void *)0x12345);
	TEST_PRINTF_NO_ARGS("A simple percent: %%\n");

	// --- Edge Cases ---
	TEST_PRINTF("Null string: %s\n", null_str);
	TEST_PRINTF("Pointer NULL: %p\n", null_str);
	TEST_PRINTF("Int Min: %d\n", INT_MIN);
	TEST_PRINTF("Int Max: %d\n", INT_MAX);
	TEST_PRINTF("Unsigned Max: %u\n", UINT_MAX);
	TEST_PRINTF("Hex Max: %x\n", UINT_MAX);
	TEST_PRINTF("Hex Max Upper: %X\n", UINT_MAX);
	TEST_PRINTF("Multiple: %d %s %c %x\n", 10, "ten", 'T', 10);

	// --- Bonus Flag Tests (Width) ---
	TEST_PRINTF("Width [10s]: |%10s|\n", "test");
	TEST_PRINTF("Width [-10s]: |%-10s|\n", "test");
	TEST_PRINTF("Width [5c]: |%5c|\n", 'X');
	TEST_PRINTF("Width [-5c]: |%-5c|\n", 'X');
	TEST_PRINTF("Width [10d]: |%10d|\n", 123);
	TEST_PRINTF("Width [-10d]: |%-10d|\n", 123);
	TEST_PRINTF("Width [010d]: |%010d|\n", 123);
	TEST_PRINTF("Width [010d neg]: |%010d|\n", -123);
	TEST_PRINTF("Width [-010d]: |%-010d|\n", 123);

	// --- Bonus Flag Tests (Precision) ---
	TEST_PRINTF("Precision [.3s]: |%.3s|\n", "hello");
	TEST_PRINTF("Precision [10.3s]: |%10.3s|\n", "hello");
	TEST_PRINTF("Precision [-10.3s]: |%-10.3s|\n", "hello");
	TEST_PRINTF("Precision [.5d]: |%.5d|\n", 123);
	TEST_PRINTF("Precision [10.5d]: |%10.5d|\n", 123);
	TEST_PRINTF("Precision [-10.5d]: |%-10.5d|\n", 123);
	TEST_PRINTF("Precision [.5d neg]: |%.5d|\n", -123);
	TEST_PRINTF("Precision [10.5d neg]: |%10.5d|\n", -123);
	TEST_PRINTF("Precision [010.5d]: |%010.5d|\n", 123); // Zero flag ignored
	TEST_PRINTF("Precision [.0d zero]: |%.0d|\n", 0);

	// --- Bonus Flag Tests (+, ' ', #) ---
	TEST_PRINTF("Flag [+d]: |%+d|\n", 42);
	TEST_PRINTF("Flag [+d neg]: |%+d|\n", -42);
	TEST_PRINTF("Flag [ d]: |% d|\n", 42);
	TEST_PRINTF("Flag [ d neg]: |% d|\n", -42);
	TEST_PRINTF("Flag [ +d]: |% +d|\n", 42);
	TEST_PRINTF("Flag [#x]: |%#x|\n", 12345);
	TEST_PRINTF("Flag [#X]: |%#X|\n", 12345);
	TEST_PRINTF("Flag [#x zero]: |%#x|\n", 0);
	TEST_PRINTF("Flag [010#x]: |%010#x|\n", 12345);

	// --- Float Tests ---
	sea_printf("\n--- 🌊 FLOAT TESTS 🌊 ---\n\n");
	TEST_PRINTF("Float basic: %f\n", 123.456);
	TEST_PRINTF("Float negative: %f\n", -123.456);
	TEST_PRINTF("Float precision [.2f]: %.2f\n", 1.999);
	TEST_PRINTF("Float precision [.0f]: %.0f\n", 1.999);
	TEST_PRINTF("Float width [20f]: |%20f|\n", 123.456);
	TEST_PRINTF("Float width [-20f]: |%-20f|\n", 123.456);
	TEST_PRINTF("Float width [020f]: |%020f|\n", 123.456);
	TEST_PRINTF("Float width [020f neg]: |%020f|\n", -123.456);
	TEST_PRINTF("Float width+prec [20.2f]: |%20.2f|\n", 1.999);
	TEST_PRINTF("Float width+prec [-20.2f]: |%-20.2f|\n", 1.999);
	TEST_PRINTF("Float width+prec [020.2f]: |%020.2f|\n", 1.999);
	TEST_PRINTF("Float flags [+f]: |%+f|\n", 123.456);
	TEST_PRINTF("Float flags [ f]: |% f|\n", 123.456);
	TEST_PRINTF("Float flags [+f neg]: |%+f|\n", -123.456);
	TEST_PRINTF("Float flags [#f]: |%#f|\n", 123.0);
	TEST_PRINTF("Float flags [#f prec 0]: |%.0#f|\n", 123.0);
	TEST_PRINTF("Float complex: |%020.2+f|\n", 123.4567);

	sea_printf("\n--- 🌊 TESTS COMPLETE 🌊 ---\n");
	return (0);
}
